#include <iostream>
/**
 * Calculates and returns an end of year balance for given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 *
 * @return the final calculated end of year balance
 */
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears)
{
    // you may wish to change this function when you bring it into your program
    // for now please get it to work here as specified

    //       IMPORTANT TIPS:
    // You should assume a working printDetails(int yearIndex, double balance, double interestEarnedThisYear) exists
    // printDetails should be called after each year
    // Compounding should be done monthly
    // Make sure to keep values to at least 2 decimal places
    // Make sure to divide the interest rate by 100 and by 12
    // Year begins with 1, not 0

    /*
    Example:for 100 initial, 10% interest, and 4 years
    Year            Year End Balance        Interest Earned
     1               	$110.47                 	$10.47
     2                $122.04                	    $11.57
     3               	$134.82                 	$12.78
     4              	$148.94                 	$14.12
    */
    // TODO: your code here to implement the method
    double balance = initialInvestment;
    interestRate /= 1200; // Dividing the interest rate by 100 and by 12

    for (int i = 1; i <= numberOfYears; i++)
    {
        double interestEarnedThisYear = 0;

        for (int j = 0; j < 12; j++)
        {
            double interestEarnedThisMonth = balance * interestRate;
            balance += interestEarnedThisMonth;
            interestEarnedThisYear += interestEarnedThisMonth;
        }

        printDetails(i, balance, interestEarnedThisYear);
    }

    // return the final balance
    return balance;
}