/*
 * ProjectTwo.cpp
 *
 *  Date: October 3, 2024
 *  Author: Carlos Rodriguez
 */

#pragma once
#ifndef BANKING_H
#define BANKING_H

// Banking class declaration
class Banking {
public:
    // Constructor
    Banking();
    
    // Setters
    void SetInitialInvestment(double t_initialInvestment);
    void SetMonthlyDeposit(double t_monthlyDeposit);
    void SetInterestRate(double t_annualInterest);
    void SetNumberOfYears(int t_numberOfYears);

    // Getters
    double GetInitialInvestment() const;
    double GetMonthlyDeposit() const;
    double GetInterestRate() const;
    int GetNumberOfYears() const;

    // Calculation methods
    double calcBalanceWithoutMonthlyDeposits() const;
    double calcBalanceWithMonthlyDeposits() const;

private:
    double m_totalAmount;
    double m_interestAmount;
    double m_yearlyTotalInterest;
    double m_monthlyDeposit;
    int m_numberOfYears; // Changed to int
};

#endif // BANKING_H