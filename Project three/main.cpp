/*
 * Project Three.cpp
 *
 *  Date: 02/24/2025
 *  Author: Robert Mora
 */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// Class to manage grocery tracking
class GroceryTracker {
private:
    map<string, int> itemFrequency; // Stores item names and their purchase counts
    string inputFile = "CS210_Project_Three_Input_File.txt";
    string outputFile = "frequency.dat";

    // Loads item data from the file and counts occurrences
    void loadFile() {
        ifstream file(inputFile);
        if (!file) {
            cerr << "Error: Unable to open " << inputFile << endl;
            return;
        }
        string item;
        while (file >> item) {
            transform(item.begin(), item.end(), item.begin(), ::tolower); // Normalize to lowercase
            itemFrequency[item]++; // Track item frequency
        }
        file.close();
    }

    // Saves item frequencies to a file for future reference
    void saveToFile() {
        ofstream file(outputFile);
        if (!file) {
            cerr << "Error: Unable to write to " << outputFile << endl;
            return;
        }
        for (const auto& pair : itemFrequency) {
            file << pair.first << " " << pair.second << endl; // Store item and its count
        }
        file.close();
    }

public:
    // Constructor initializes the program by loading and saving data
    GroceryTracker() {
        cout << "Loading data from file...\n";
        loadFile();
        cout << "Saving backup data...\n";
        saveToFile();
    }

    // Allows user to search for an item and displays its purchase count
    void searchItem() {
        string item;
        cout << "Enter item to search: ";
        cin >> item;
        transform(item.begin(), item.end(), item.begin(), ::tolower);
        if (itemFrequency.find(item) != itemFrequency.end()) {
            cout << item << " was purchased " << itemFrequency[item] << " times." << endl;
        }
        else {
            cout << item << " was not found in the records." << endl;
        }
    }

    // Displays all items along with their purchase frequencies
    void displayFrequencies() {
        cout << "\nItem Purchase Frequencies:\n";
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Displays a histogram representation of item purchases
    void displayHistogram() {
        cout << "\nPurchase Histogram:\n";
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                cout << "*"; // Each asterisk represents one purchase
            }
            cout << endl;
        }
    }
};

// Function to display the menu options to the user
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Search for an item\n";
    cout << "2. Display all items and frequencies\n";
    cout << "3. Display histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Main function to drive the program
int main() {
    GroceryTracker tracker; // Initialize the tracker
    int choice;

    do {
        displayMenu();
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }

        switch (choice) {
        case 1:
            tracker.searchItem(); // User searches for an item
            break;
        case 2:
            tracker.displayFrequencies(); // Show all items and their purchase counts
            break;
        case 3:
            tracker.displayHistogram(); // Display a visual representation of data
            break;
        case 4:
            cout << "Exiting program... Goodbye!\n";
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
