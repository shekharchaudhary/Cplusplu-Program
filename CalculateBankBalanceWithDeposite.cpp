#include <iostream>
/**
 * Calculates and returns an end of year balance for a given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param monthlyDeposit dollar amount added into the investment each month
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 *
 * @return the final calculated end of year balance
 */
double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears)
{
    // you may wish to change this function when you bring it into your program
    // for now  please get it to work here as specified in this function header

    //       IMPORTANT TIPS:
    // You may assume a working printDetails(int yearIndex, double balance, double interestEarnedThisYear) exists
    // printDetails should be called after each year
    // Compounding should be done monthly
    // Make sure to divide the interest rate by 100 and by 12
    // This month’s deposit does not earn interest(until next month)
    // Year begins with 1, not 0

    /*
    Example for 100 initial investment and 10% interest and $10 monthly payment:
    Year            Year End Balance        Interest Earned
     1               	$236.13                 	$16.13
     2                  $386.51                	    $30.38
     3               	$552.64                 	$46.13
     4              	$736.16                 	$63.52
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
            balance += monthlyDeposit;
        }

        printDetails(i, balance, interestEarnedThisYear);
    }

    // return the ending balance
    return balance;
}