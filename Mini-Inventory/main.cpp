#include <iostream>
#include <string>

/*****************************************************************************************************
This program will be a mini inventory system that allows user to input their own details
Author: filthypotato
Created: 10/24/2025
Revisions: 
*****************************************************************************************************/

struct Item
{
    std::string name{};
    float price{};
    int quantity{};
};

// Funcations called above main so they can be used properly
// Fills the array with user inputs
void arrayItems(Item items[], int size);
// Output of items in array
void outputItems(const Item items[], int size);
// Total calculation price
float calculationPriceTotal(const Item items[], int size);
// Search by name in the array
int searchByName(const Item items[], int size, std::string target);


int main()
{
    const int SIZE{3};    // easy size of 3, can be changed as needed
    Item inventory[SIZE];  // array of SIZE item structs

    // Initializes the array by calling funtion to main and passing parameters
    arrayItems(inventory, SIZE);

    // Displays the array
    std::cout << "Inventory List" << "\n";
    outputItems(inventory, SIZE);

    // Calculated price
    float total = calculationPriceTotal(inventory, SIZE);  // making variable named total and calling the calculated price
    std::cout << "Total price of items: $" << total << "\n";  // prints value of all items given

    // Search by name
    std::string searchItem{};                                    // creating variable searchItem
    std::cout << "Enter an item you would like to search for: "; // asking for user input for item they would like to search for.
    std::cin >> searchItem;

    int index = searchByName(inventory, SIZE, searchItem); // making variable index and calling function for searchByName function

    if (index != -1) // if index is NOT equal to -1
    {
        std::cout << "\nItem found" << "\n";
        std::cout << "Name: " << inventory[index].name << "\n"; // takes inventory of the index variable and calls the name
        std::cout << "Price: $" << inventory[index].price << "\n"; // takes inventory of the index variable and calls prices
        std::cout << "Quantity: " << inventory[index].quantity << "\n"; // takes inventory of the index and called quantity
    }
    else
    {
        std::cout << "No item by the name of " << searchItem << " was found." << "\n"; // prints no item found and name given
    }

    return 0;
}

void arrayItems(Item items[], int size)
{
    std::cout << "Enter details (name, price, quantity) \n";  // prints enter details for user.

    for (int i = 0; i < size; i++)      // loops user input until size is met
    {
        std::cout << "\nItem" << i + 1 << "\n"; 
        std::cout << "Name: ";   
        std::cin >> items[i].name;   // lets user input name type

        std::cout << "Price: ";
        std::cin >> items[i].price;  // Lets user input price of item

        std::cout << "Quantity: ";
        std::cin >> items[i].quantity;  // Lets user input quantity of item
    }
}

void outputItems(const Item items[], int size)
{
    for (int i = 0; i < size; i++)      // loops looking for item to output
    {
        std::cout << "Item" << i + 1 << "\n";
        std::cout << " Name: " << items[i].name << "\n";  // calls items variable from structs and calls name
        std::cout << " Price: $" << items[i].price << "\n"; // calls items variable from structs and calls price
        std::cout << " Quantity: " << items[i].quantity << "\n"; // calls items variable from structs and calls quantity
    }
}

float calculationPriceTotal(const Item items[], int size)
{
    float total{0.0};                       // float total initialized to 0.0

    for (int i = 0; i < size; i++)                   
        total = total + items[i].price * items[i].quantity; // holds arr items and adds them to a the new variable total
    return total;
}

int searchByName(const Item items[], int size, std::string target)
{
    int name{};                  // vartiable for name by search
    bool found{false};          // found set to false

    for (name = 0; name < size; name++)     
    {
        if (items[name].name == target)  // if item is equal to user input of supplied item in inventory. print name
        {
            found = true;
            break;
        }
    }

    if (found)
        return name;
    else
        return -1;
}