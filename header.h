// JJ Newell 10-3-24

#pragma once
#ifndef HEADER_H
#define HEADER_H

// BankInfo class
class BankInfo {
public:

	void SetInterestRate(double t_apy);
	void SetNumberOfYears(int t_numberOfYears);
	void SetInitialInvestment(double t_initialInvestment);
	void SetMonthlyDeposit(double t_monthlyDeposit);
	double GetInterestRate() const;
	double GetInitialInvestment() const;
	double GetMonthlyDeposit() const;
	double balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numberOfYears);
	double calcBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_annualInterest, int t_numberOfYears);
	int GetNumberOfYears() const;

private:

	double m_monthlyDeposit;
	double m_numberOfYears;
	double m_totalAmount;
	double m_apy;
	double m_yearlyTotalInterest;
};

#endif