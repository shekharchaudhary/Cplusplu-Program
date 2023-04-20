#include <iostream>
#include <iomanip>
using namespace std;
float initialInvest, monthlyDep, annualIntrest, years, months, totalAmt, intrestAmt, yearTotIntrest;

int main()
{
    // Display form to the user
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: " << endl;
    cout << "Monthly Deposit: " << endl;
    cout << "Annual Interest: " << endl;
    cout << "Number of years: " << endl;
    // system("PAUSE");
    // system("CLS");
    // Get input from the user
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: $";
    cin >> initialInvest;
    if (initialInvest < 0)
    {
        cout << "Initial investment amount cannot be less than $0" << endl;
        cout << "Initial Investment Amount: $";
        cin >> initialInvest;
    };
    cout << "Monthly Deposit: $";
    cin >> monthlyDep;
    if (monthlyDep < 0)
    {
        cout << "Initial investment amount cannot be less than $0" << endl;
        cout << "Monthly Deposit: $";
        cin >> monthlyDep;
    };
    cout << "Annual Interest: %";
    cin >> annualIntrest;
    cout << "Number of years: ";
    cin >> years;
    months = years * 12;
    // system("PAUSE");
    // system("CLS");
    // Set total amount to initial investment to be updated
    totalAmt = initialInvest;
    // Display year data without monthly deposits
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "=================================================================" << endl;
    cout << "YearYear End BalanceYear End Earned Interest" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (int i = 0; i < years; i++)
    {
        // Calculate yearly interest
        intrestAmt = (totalAmt) * ((annualIntrest / 100));
        // Calculate year end total
        totalAmt = totalAmt + intrestAmt;
        // Print results to table showcasing only two decimal points
        cout << "" << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << intrestAmt << "\n";
    }
    // Set total amount to initial investment to be updated
    totalAmt = initialInvest;
    // Display year data with monthly deposits
    cout << endl;
    cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "=================================================================" << endl;
    cout << "YearYear End BalanceYear End Earned Interest" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (int i = 0; i < years; i++)
    {
        // Set yearly interest to zero at the start of the year
        yearTotIntrest = 0;
        for (int j = 0; j < 12; j++)
        {
            // Calculate monthly interest
            intrestAmt = (totalAmt + monthlyDep) * ((annualIntrest / 100) / 12);
            // Calculate month end interest
            yearTotIntrest = yearTotIntrest + intrestAmt;
            // Calculate month end total
            totalAmt = totalAmt + monthlyDep + intrestAmt;
        }
        // Print results to table showcasing only two decimal points
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << yearTotIntrest << "\n";
    }
    return 0;
}