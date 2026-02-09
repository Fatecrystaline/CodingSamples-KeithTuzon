#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Define the base Item class
class Item {
protected:
    string name;        // Name of the item
    string description; // Description of the item
    double cost;        // Cost of the item

public:
    // Constructor to initialize an item
    Item(string itemName, string itemDescription, double itemCost) {
        name = itemName;
        description = itemDescription;
        cost = itemCost;
    }

    virtual void displayItem() const {
        cout << "Item Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Cost: " << cost << " Gold" << endl;
    }

    string getName() const { return name; }
    double getCost() const { return cost; }
};

// Derived class for Weapon items
class Weapon : public Item {
private:
    double attackPower;

public:
    Weapon(string itemName, string itemDescription, double itemCost, double itemAttackPower)
        : Item(itemName, itemDescription, itemCost), attackPower(itemAttackPower) {}

    void displayItem() const override {
        Item::displayItem();
        cout << "Attack Power: " << attackPower << endl;
    }
};

// Derived class for Consumable items
class Consumable : public Item {
private:
    string effect;

public:
    Consumable(string itemName, string itemDescription, double itemCost, string itemEffect)
        : Item(itemName, itemDescription, itemCost), effect(itemEffect) {}

    void displayItem() const override {
        Item::displayItem();
        cout << "Effect: " << effect << endl;
    }
};

// Derived class for Equipment items
class Equipment : public Item {
private:
    string equipmentType;

public:
    Equipment(string itemName, string itemDescription, double itemCost, string itemType)
        : Item(itemName, itemDescription, itemCost), equipmentType(itemType) {}

    void displayItem() const override {
        Item::displayItem();
        cout << "Equipment Type: " << equipmentType << endl;
    }
};

// Function to display the shop's inventory
void displayShop(const vector<Item*>& shopItems) {
    cout << "Welcome to the Item Shop!" << endl;
    cout << "=========================" << endl;
    for (const Item* item : shopItems) {
        item->displayItem();
        cout << "-------------------------" << endl;
    }
}

// Function to display the inventory
void displayInventory() {
    ifstream file("inventory.txt");
    string line;

    cout << "\nYour Inventory:\n";
    if (!file) {
        cout << "Error: Could not open inventory file.\n";
        return;
    }

    while (getline(file, line)) {
        cout << "- " << line << endl;
    }
    file.close();
}

int main() {
    int gold = 100;
    int deci1 = 0, deci3 = 0, deci4 = 0;
    string deci2 = "null";

    fstream file("inventory.txt", ios::in | ios::out | ios::app);
    try {
        if (file.is_open()) {

            cout << "Please enter your budget (default is 100): ";
            cin >> gold;
            cout << endl;

            // Create a vector to store the items in the shop
            vector<Item*> shopItems;

            // Add items to the shop
            shopItems.push_back(new Consumable("HealingPotion", "Restores 50 health points", 15.0, "Restores health"));
            shopItems.push_back(new Equipment("SteelHelmet", "A standard helmet that provides protection", 40.00, "Armor"));
            shopItems.push_back(new Weapon("SteelSword", "A sharp sword for attacking", 25.0, 50.0));
            shopItems.push_back(new Equipment("WizardCap", "A magic cap that boosts magic potential", 40.00, "Magic"));
            shopItems.push_back(new Equipment("Wand", "A tool used to cast simple magic", 30.00, "Magic"));
            shopItems.push_back(new Consumable("BeeHive", "Unleashes a hive of angry bees to poison foes", 20.00, "Poison effect"));
            shopItems.push_back(new Consumable("Apple", "Restores 25 health points", 10.00, "Restores health"));
            shopItems.push_back(new Equipment("Boots", "Simple boots that provide extra speed", 30.00, "Armor"));

            bool continueShopping = true;

            // Display the shop's inventory once at the start
            displayShop(shopItems);

            while (continueShopping) {
                cout << "\n1 = Purchase something from the shop\n2 = Check your inventory\n3 = Tip the shopkeep\n4 = Exit the shop\nWhat would you like to do?: ";
                cin >> deci1;

                if (deci1 == 1) {
                    cout << "What would you like to purchase with your " << gold << " gold? Enter the name of your selection, and please make sure it's spelled correctly: ";
                    cin >> deci2;
                    bool found = false;
                    for (Item* item : shopItems) {
                        string purchase = item->getName();
                        double cost = item->getCost();
                        if (deci2 == purchase) {
                            if (gold >= cost) {
                                file << purchase << endl;  // Add purchased item to inventory file
                                gold = gold - cost;
                                cout << "Thank you for your purchase! You now have " << gold << " gold." << endl;
                                found = true;
                                break;
                            } else {
                                cout << "You don't have enough gold to buy this item!" << endl;
                                found = true;
                                break;
                            }
                        }
                    }
                    if (!found) {
                        cout << "Item not found. Please check the name and try again." << endl;
                    }
                }
                else if (deci1 == 2) {
                    displayInventory();  // Display the user's inventory
                    cout << "- " << gold << " Gold" << endl;
                }
                else if (deci1 == 3) {
                    bool tipping = true;
                    while (tipping == true){
                        cout << "How much would you like to tip? (Enter 0 to go back): ";
                        cin >> deci3;
                        if (deci3 <= gold and deci3 > 0) {
                            cout << "Are you sure you want to tip " << deci3 << " gold? (1 = Yes, 2 = No): ";
                            cin >> deci4;
                            if (deci4 == 1) {
                                gold = gold - deci3;
                                if (deci3 <= 10) {
                                    cout << "Thank you for the tip." << endl;
                                    tipping = false;
                                }
                                else if (deci3 <= 100 and deci3 > 10) {
                                    cout << "Thank you very much!" << endl;
                                    tipping = false;
                                }
                                else if (deci3 <= 900 and deci3 > 100) {
                                    cout << "Oh, wow! Thank you!" << endl;
                                    tipping = false;
                                }
                                else if (deci3 <= 8000 and deci3 > 900) {
                                    cout << "Are... Are you sure? That's a lot! Thank you so much!" << endl;
                                    tipping = false;
                                }
                                else if (deci3 > 8000) {
                                    cout << "Th-this isnt some kinda money laundering thing is it?" << endl;
                                    tipping = false;
                                }
                            }
                            else {
                                cout << "Ok";
                            }
                        }
                        if (deci3 < 0 ) {
                            cout << "You can't give a negative tip, that's not how tips work." << endl;
                        }
                        else if (deci3 == 0) {
                            tipping = false;
                        }
                        else if (deci3 > gold) {
                            cout << "You don't have that much gold, but I appreciate the thought!" << endl;  
                        }
                    }
                }
                else if (deci1 == 4) {
                    cout << "Ok. Thanks for stopping by!" << endl;
                    continueShopping = false;  // Exit the loop
                }
                else {
                    if (deci1 < 1 || deci1 > 3) {
                        throw invalid_argument("Error: Invalid selection");
                    }
                }
            }
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    file.close();


    return 0;
}
