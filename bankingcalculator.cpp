/*
 * ProjectTwo.cpp
 *
 *  Date: October 3, 2024
 *  Author: Carlos Rodriguez
 */

#include "Banking.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor to initialize member variables
Banking::Banking() : m_totalAmount(0), m_interestAmount(0), m_yearlyTotalInterest(0), m_monthlyDeposit(0), m_numberOfYears(0) {}

// Accessors and Mutators
void Banking::SetInitialInvestment(double t_initialInvestment) {
    m_totalAmount = t_initialInvestment;
}
void Banking::SetMonthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}
void Banking::SetInterestRate(double t_annualInterest) {
    m_yearlyTotalInterest = t_annualInterest;
}
void Banking::SetNumberOfYears(int t_numberOfYears) {
    m_numberOfYears = t_numberOfYears;
}
double Banking::GetInitialInvestment() const {
    return m_totalAmount;
}
double Banking::GetMonthlyDeposit() const {
    return m_monthlyDeposit;
}
double Banking::GetInterestRate() const {
    return m_yearlyTotalInterest;
}
int Banking::GetNumberOfYears() const {
    return m_numberOfYears;
}

// Function to calculate and output balance without a monthly deposit
double Banking::calcBalanceWithoutMonthlyDeposits() const {
    double totalAmount = m_totalAmount;

    // Display table heading for the output
    cout << endl << "     Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << std::string(66, '=') << endl;    // Separator line
    cout << "Year          Year End Balance          Year End Earned Interest" << endl;
    cout << std::string(66, '-') << endl;    // Separator line
 
    // Calculate yearly interest and year end total
    for (int i = 0; i < m_numberOfYears; i++) {
        m_interestAmount = totalAmount * (m_yearlyTotalInterest / 100);  // Calculate interest for the year
        totalAmount += m_interestAmount;                                 // Update total amount with interest
        cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t\t$" << m_interestAmount << endl;
    }

    return totalAmount;                     // Return the final total amount
}

// Function to calculate and output balance with a monthly deposit
double Banking::calcBalanceWithMonthlyDeposits() const {
    double totalAmount = m_totalAmount;

    // Display table heading
    cout << endl << "     Balance and Interest With Additional Monthly Deposits" << endl;
    cout << std::string(66, '=') << endl;
    cout << "Year          Year End Balance          Year End Earned Interest" << endl;
    cout << std::string(66, '-') << endl;

    // Calculate yearly interest and year end total
    for (int i = 0; i < m_numberOfYears; i++) {
        m_yearlyTotalInterest = 0;

        // Calculate monthly deposits and interest
        for (int j = 0; j < 12; j++) {
            m_interestAmount = (totalAmount + m_monthlyDeposit) * ((m_yearlyTotalInterest / 100.00) / 12.00);
            m_yearlyTotalInterest += m_interestAmount;
            totalAmount += m_monthlyDeposit + m_interestAmount;
        }

        // Output year-end balance and yearly interest earned
        cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t\t$" << m_yearlyTotalInterest << endl;
    }

    return totalAmount;                 // Return the final total amount
}