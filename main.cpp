/*
 * ProjectTwo.cpp
 *
 *  Date: October 3, 2024
 *  Author: Carlos Rodriguez
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Banking.h"

using namespace std;

// Function prototypes
void PrintHomeScreen(Banking& myInvestment); // Function to print the home screen and gather user input
int validIntInput(); // Function to validate integer input
double validDoubleInput(); // Function to validate double input

// Main function
int main() {
    char user_input = 'a'; // Variable to hold user input for controlling the loop
    Banking myInvestment; // Create an instance of the Banking class

    // Loop until the user decides to quit
    while (user_input != 'q') {
        system("cls"); // Clear the console screen
        PrintHomeScreen(myInvestment); // Print home screen and get user input

        // Calculate and display balances without and with monthly deposits
        myInvestment.calcBalanceWithoutMonthlyDeposits();
        myInvestment.calcBalanceWithMonthlyDeposits();

        // Prompt the user for input on whether to continue or quit
        cout << "Please enter 'q' to quit. Enter any other character to run another report: ";
        cin >> user_input; // Get user input
    }

    return 0; // Exit the program
}

// Function to print home screen and get input from user
void PrintHomeScreen(Banking& myInvestment) {
    try {
        // Display the input prompt
        cout << "**********************************" << endl;
        cout << "********** Data Input ************" << endl;

        // Get and validate the initial investment amount
        cout << "Initial Investment Amount: $";
        double initialInvestment = validDoubleInput(); // Get user input
        if (initialInvestment < 0) {
            throw runtime_error("Invalid entry."); // Throw an error if input is negative
        }
        myInvestment.SetInitialInvestment(initialInvestment); // Set the initial investment

        // Get and validate the monthly deposit
        cout << "Monthly Deposit: $";
        double monthlyDeposit = validDoubleInput(); // Get user input
        if (monthlyDeposit < 0) {
            throw runtime_error("Invalid entry."); // Throw an error if input is negative
        }
        myInvestment.SetMonthlyDeposit(monthlyDeposit); // Set the monthly deposit

        // Get and validate the annual interest rate
        cout << "Annual Interest: %";
        double annualInterest = validDoubleInput(); // Get user input
        if (annualInterest < 0) {
            throw runtime_error("Invalid entry."); // Throw an error if input is negative
        }
        myInvestment.SetInterestRate(annualInterest); // Set the annual interest rate

        // Get and validate the number of years
        cout << "Number of years: ";
        int years = validIntInput(); // Get user input
        if (years <= 0) {
            throw runtime_error("Invalid entry."); // Throw an error if input is zero or negative
        }
        myInvestment.SetNumberOfYears(years); // Set the number of years

        system("PAUSE"); // Pause the console before clearing
    }
    catch (runtime_error& excpt) {
        // Handle runtime errors by displaying the error message
        cout << excpt.what() << endl; // Display the error message
        cout << "Cannot compute with negative value." << endl; // Inform the user about the issue
        system("PAUSE"); // Pause before clearing the screen
        system("cls"); // Clear the console screen
    }
}

// User input validation to make sure input is an integer
int validIntInput() {
    int x; // Variable to hold the input

    while (true) {
        if (cin >> x) {
            break; // Exit loop if input is valid
        }
        else {
            // Prompt for valid input if the current input is invalid
            cout << "Invalid Input! Please input a numerical value: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
        }
    }

    return x; // Return the validated integer
}

// User input validation to make sure input is a double
double validDoubleInput() {
    double x; // Variable to hold the input

    while (true) {
        if (cin >> x) {
            break; // Exit loop if input is valid
        }
        else {
            // Prompt for valid input if the current input is invalid
            cout << "Invalid Input! Please enter a valid number: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
        }
    }

    return x; // Return the validated double
}