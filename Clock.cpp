// Developer : Shekhar Chaudhary
// Date : 03 / 19 / 2023
// Purpose : Chada Tech Clocks

// twoDigitString

#include <iostream>
#include <string>

using namespace std;

/**
 * Formats a number as 2 digits, with a leading 0 if needed
 * This method can be useful when converting a time like 9 hours, 12 minutes and 3 seconds to "09:12:03"
 * It's a good building block to help you get that part right and not have to repeat code
 *
 * @param n number to format, assumed between 0 and 59, inclusive
 * @return two digit string representation of number
 */
string twoDigitString(unsigned int n)
{
    // TODO: your code here to implement the method
    // Numbers between 10 and 59 just need to be converted to a string
    // Numbers from 0 to 9 need a "0" tacked onto the front of the string representation of the number

    if (n >= 10 && n <= 59)
    {
        return to_string(n);
    }
    else if (n >= 0 && n <= 9)
    {
        return "0" + to_string(n);
    }

    // Return an empty string if the input number is out of the valid range (0-59)
    return "";
}

/**
 * Returns a string of length n, each character a c.
 * For example, nCharString(5, '*') should return "*****"
 *
 * @param n string length, >=0
 * @return string of n c's
 */
string nCharString(size_t n, char c)
{
    /**
     * You may wish to change this function when you bring it into your program
     * For now please get it to work here with the existing function signature
     * You may assume <string> has been included
     */
    // TODO: your code here to implement the method

    // Create a string of n characters, each character being c
    string result(n, c);

    // Return the n character string
    return result;
}

/**
 * Formats the time in military format

 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss
 */
string formatTime24(unsigned int h, unsigned int m, unsigned int s)
{
    // You may assume <string> has been imported and the method twoDigitString works
    // for example, twoDigitString(7) returns "07" and twoDigitString(59) returns "59"
    // That should simplify your work here and help you not repeat code.
    // You need a colon betweeh hours and minutes and between minutes and seconds.
    // Tests will pass in (7, 24, 9) and (23, 0, 59) and expect 07:24:09 and 23:00:59
    // You may change this function in the program you submit, but please get it to work
    // here first, with this function signature.
    // TODO: Your code here

    string hours = twoDigitString(h);
    string minutes = twoDigitString(m);
    string seconds = twoDigitString(s);

    // return time as hh:mm:ss
    return hours + ":" + minutes + ":" + seconds;
}

/**
 * Formats the time in am/pm format
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss A M or hh:mm:ss P M where hh is between 01 and 12, inclusive
 */
string formatTime12(unsigned int h, unsigned int m, unsigned int s)
{
    /* Feel free to adapt this function in your program, but first please get it to work
    here with this signature.
    You may assume you have a working twoDigitString(n) and include <string>
    twoDigitString(n) gives a 0 followed by the character for n if n is a single digit and gives the
    two-digit string if n is two digits, for example twoDigitString(7) returns "07" and twoDigitString(12) returns "12".
    Include colons as separators, add one space after seconds then  A M or P M as appropriate
    Tests will pass in (7, 24, 9), (23, 0, 59), (0, 0, 1), and (12, 0, 59)
    TODO: Your code here */

    string am_pm;
    if (h >= 12)
    {
        am_pm = "P M";
        h = (h == 12) ? h : h - 12;
    }
    else
    {
        am_pm = "A M";
        h = (h == 0) ? 12 : h;
    }

    string hours = twoDigitString(h);
    string minutes = twoDigitString(m);
    string seconds = twoDigitString(s);

    // return hh:mm:ss A M or hh:mm:ss P M
    return hours + ":" + minutes + ":" + seconds + " " + am_pm;
}

// test cases (["Add One Hour", "Add One Minute", "Add One Second", "Exit Program"], 4, 26 or 57)
/**
 * Prints menu
 *
 * @param *strings[], nonempty array of choices
 * @param width, width of each line, will be comfortably bigger than the longest string
 *
 */
void printMenu(char *strings[], unsigned int numStrings, unsigned char width)
{
    /**
     * In your own program feel free to change the function signature. For now, please first get it to work as is.
     * You may assume <string> and <iostream> have been imported.
     * You may assume a function nCharString has been implemented, and you will want to call it for stars and spaces.
     * string nCharString(size_t n, char c) produces a string of n c's. For example, nCharString(5, '*') returns "*****"
     * and nCharString (7,' ') will return 7 spaces.
     */
    // TODO: Your code here. Use the comments to see the expected format of the menu.

    // first print width *'s followed by an endl
    cout << nCharString(width, '*') << endl;

    // Next, for each string s in the array
    for (unsigned int i = 0; i < numStrings; ++i)
    {
        // Calculate the number of spaces needed after the string
        unsigned int numSpaces = width - 1 - (4 + strlen(strings[i]));

        // Print menu item line
        cout << "*"
             << " " << (i + 1) << " "
             << "-"
             << " " << strings[i] << nCharString(numSpaces, ' ') << "*" << endl;

        // Skip a line after each line except the last line
        if (i < numStrings - 1)
        {
            cout << endl;
        }
    }

    // Outside the loop print another width *s followed by an endl
    cout << nCharString(width, '*') << endl;
}

/**
 * Display the clocks
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 */
void displayClocks(unsigned int h, unsigned int m, unsigned int s)
{
    // The code in your submitted program may vary. For now, please get this to work with the given
    // function signature.
    // You may assume you have a working nCharString and formatTime24 and formatTime12 and <iostream> has been imported
    //
    // nCharString(27,'*') gives a string of 27 stars. nCharString(3,' ') gives 3 spaces
    // formatTime12(h, m, s) and formatTime24(h, m, s) give the formatted time as specified in the assignment
    // test will pass in (0, 59, 9)
    // TODO: Your code here, follow the comments for each line
    // cout 27 stars + 3 spaces + 27 stars + endl
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;

    // cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
    cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');

    // cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
    cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;

    // cout an endl for a blank line
    cout << endl;

    // cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
    cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');

    // cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
    cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;

    // cout 27 stars + 3 spaces + 27 stars + endl
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

/**
 * Adds one second
 */

int seconds = 0;
int minutes = 0;
int hours = 0;

int getSecond()
{
    return seconds;
}

void setSecond(int s)
{
    seconds = s;
}

int getMinute()
{
    return minutes;
}

void setMinute(int m)
{
    minutes = m;
}

int getHour()
{
    return hours;
}

void setHour(int h)
{
    hours = h;
}

// ADD ONE MINUTE

// ADD ONE HOUR

/**
 * Adds one hour
 */
void addOneHour()
{
    /** Assume you have a working getHour() and setHour(h)
     * Feel free to change things around in your code, but first please get it working here
     * with these function signatures.
     * if getHour() is between 0 and 22 inclusive, add 1 and setHour() to that
     * if getHour() is 23 the next value for hour is 0 so setHour() to that
     * test will check values of hours from 0 to 23 from getHour()
     */
    // TODO: Your code here
    int currentHour = getHour();
    if (currentHour >= 23)
    {
        setHour(0);
    }
    else
    {
        setHour(currentHour + 1);
    }

    // nothing to return, just setHour to the appropriate value
}

/**
 * Adds one minute
 */
void addOneMinute()
{
    /**assume you have working getMinute(), setMinute(m), and addOneHour()
     * Feel free to change these in your program, but for now please get things to work with
     * these function signatures.
     * if getMinute() is between 0 and 58 inclusive, add 1 and setMinute() to the new value
     * if getMinute() is 59 the minutes must be set to 0 and you must call addOneHour()
     * test will set hours and minutes to 0, then addOneMinute 60 times
     */
    // TODO: Your code here
    int currentMinute = getMinute();
    if (currentMinute >= 59)
    {
        setMinute(0);
        int currentHour = getHour();
        setHour((currentHour + 1) % 24);
    }
    else
    {
        setMinute(currentMinute + 1);
    }

    // nothing to return, just setMinute to the appropriate value and use addOneHour if needed
}

// ADD ONE SECOND

void addOneSecond()
{
    /** assume you have working getSecond(), setSecond(s), and addOneMinute()
     * addOneMinute will take care of the hours if necessary
     * Feel free to change things around in your program, but for now please make this work with these function signatures.
     * if getSecond() is between 0 and 58 inclusive, add 1 and setSecond()
     * if getSecond() is 59, seconds wrap around to 0 and you need to call addOneMinute()
     * test will set minutes to 4 and seconds to 0, then addOneSecond 60 times
     */

    // TODO: your code here

    int currentSecond = getSecond();
    if (currentSecond >= 59)
    {
        setSecond(0);
        addOneMinute();
    }
    else
    {
        setSecond(currentSecond + 1);
    }

    // nothing to return, just call setSecond() with the right value and addOneMinute() when needed
}

// input user choice

int getMenuChoice(int n)
{
    int choice;
    do
    {
        cout << "1. Add one hour\n";
        cout << "2. Add one minute\n";
        cout << "3. Add one second\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    } while (choice < 1 || choice > n);
    return choice;
}
// Main function

int main()
{
    // Example usage twoDigitString
    // unsigned int n = 3;
    // string formatted_number = twoDigitString(n);
    // cout << "Formatted number: " << formatted_number << endl;

    // Example usage nCharString
    // size_t n1 = 5;
    // char c = '*';
    // string repeated_chars = nCharString(n1, c);
    // cout << "Repeated characters: " << repeated_chars << endl;

    // Example usage formatTime24
    // unsigned int h = 7;
    // unsigned int m = 24;
    // unsigned int s = 9;
    // string formatted_time24 = formatTime24(h, m, s);
    // cout << "Formatted time: " << formatted_time24 << endl;

    // Example usage formatTime12
    // string formatted_time12 = formatTime12(h, m, s);
    // cout << "Formatted time: " << formatted_time12 << endl;

    // Example usage printMenu
    char *menuItems[] = {"Add one Hour", "Add one minute", "Add one second", "Exit Program"};
    unsigned int numItems = sizeof(menuItems) / sizeof(menuItems[0]);
    unsigned char width = 20;

    // printMenu(menuItems, numItems, width);

    // Example usage displayClocks
    unsigned int h = 7;
    unsigned int m = 24;
    unsigned int s = 9;

    // displayClocks(h, m, s);
    int choice;

    do
    {
        displayClocks(h, m, s);
        printMenu(menuItems, numItems, width);
        choice = getMenuChoice(4);
        switch (choice)
        {
        case 1:
            addOneHour();
            break;
        case 2:
            addOneMinute();
            break;
        case 3:
            addOneSecond();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        }
        cout << "Current time: " << getHour() << ":" << getMinute() << ":" << getSecond() << endl;
    } while (choice != 4);

    return 0;
}