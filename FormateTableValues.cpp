#include <iostream>
#include <iomanip>

/**
 * Prints the calculated results of each years investment details in 3 separate fields
 * @param year year number
 * @param yearEndBalance the current dollar value of the investment
 * @param interestEarned dollar amount of how much earned in that year
 */
void printDetails(int year, double yearEndBalance, double interestEarned)
{

    // you may wish to change this function when you bring it into your program
    // for now please get it to work here

    //       IMPORTANT TIPS:
    // There should be two tabs in between each field
    // Dollars should be printed to the second decimal place

    /*
    Example:
     1               	$110.00                 	$10.00

    */
    // TODO: your code here to implement the method
    // returns nothing, just prints output to cout
    std::cout << std::fixed << std::setprecision(2);
    std::cout << year << "\t\t"
              << "$" << yearEndBalance << "\t\t"
              << "$" << interestEarned << std::endl;
}