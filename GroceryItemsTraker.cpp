#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <limits>

class ItemFrequency
{
private:
    std::map<std::string, int> frequencyMap;

public:
    bool readFromFile(const std::string &filename)
    {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open())
        {
            return false;
        }

        std::string item;
        int count;

        while (inputFile >> item >> count)
        {
            frequencyMap[item] = count;
        }

        inputFile.close();
        return true;
    }

    int getItemFrequency(const std::string &item)
    {
        return frequencyMap[item];
    }

    void printAllFrequencies()
    {
        for (const auto &item_count : frequencyMap)
        {
            std::cout << item_count.first << " " << item_count.second << std::endl;
        }
    }

    void printHistogram()
    {
        for (const auto &item_count : frequencyMap)
        {
            std::cout << item_count.first << " ";
            for (int i = 0; i < item_count.second; i++)
            {
                std::cout << "\u2588";
            }
            std::cout << std::endl;
        }
    }

    bool backupData(const std::string &filename)
    {
        std::ofstream backupFile(filename);
        if (!backupFile.is_open())
        {
            return false;
        }

        for (const auto &item_count : frequencyMap)
        {
            backupFile << item_count.first << " " << item_count.second << std::endl;
        }

        backupFile.close();
        return true;
    }
};

int main()
{
    ItemFrequency itemFrequency;
    if (!itemFrequency.readFromFile("CS210_Project_Three_Input_File.txt"))
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

    if (!itemFrequency.backupData("frequency.dat"))
    {
        std::cerr << "Error: Could not create backup file." << std::endl;
        return 1;
    }

    int choice;

    do
    {
        std::cout << "Menu:\n";
        std::cout << "1. Search for an item's frequency\n";
        std::cout << "2. Print all item frequencies\n";
        std::cout << "3. Print histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        while (!(std::cin >> choice) || choice < 1 || choice > 4)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4: ";
        }

        if (choice == 1)
        {
            std::string item;
            std::cout << "Enter item name: ";
            std::cin >> item;
            std::cout << "Frequency of " << item << ": " << itemFrequency.getItemFrequency(item) << std::endl;
        }
        else if (choice == 2)
        {
            itemFrequency.printAllFrequencies();
        }
        else if (choice == 3)
        {
            itemFrequency.printHistogram();
        }

    } while (choice != 4);

    return 0;
}
