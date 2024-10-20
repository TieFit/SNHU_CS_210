// JJ Newell 10-3-24

#include <iostream>
#include <iomanip>
#include "header.h"

using namespace std;

// initialize variables for later use
BankInfo myInvestment;
double initialInvestment;
double monthlyDeposit;
double apy;
double months;
double validDoubleInput();
int validIntInput();
int years;
char user_input = ' ';
void printHomeScreen();


// accessors and mutators to retrieve data from BankInfo class

void BankInfo::SetInitialInvestment(double t_initialInvestment) {
	m_totalAmount = t_initialInvestment;
}
void BankInfo::SetMonthlyDeposit(double t_monthlyDeposit) {
	m_monthlyDeposit = t_monthlyDeposit;
}
void BankInfo::SetInterestRate(double t_apy) {
	m_yearlyTotalInterest = t_apy;
}
void BankInfo::SetNumberOfYears(int t_numberOfYears) {
	m_numberOfYears = t_numberOfYears;
}
double BankInfo::GetInitialInvestment() const {
	return m_totalAmount;
}
double BankInfo::GetMonthlyDeposit() const {
	return m_monthlyDeposit;
}
double BankInfo::GetInterestRate() const {
	return m_yearlyTotalInterest;
}
int BankInfo::GetNumberOfYears() const {
	return m_numberOfYears;
}

// function to display tableHeading info 
void tableHeading() {
	cout << string(66, '=') << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << string(66, '-') << endl;
}

// function to calculate and output balance without monthly deposit
double BankInfo::calcBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_apy, int t_numberOfYears) {
	m_totalAmount = t_initialInvestment;

	// output message for header info
	cout << endl << "     Balance and Interest Without Additional Monthly Deposits" << endl;

	// calls tableHeading function to display table header
	tableHeading();

	// calculate yearly interest and year end total
	for (int i = 0; i < t_numberOfYears; i++) {
		m_apy = m_totalAmount * (t_apy / 100);
		m_totalAmount = m_totalAmount + m_apy;
		cout << " " << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_apy << endl;
	}

	return m_totalAmount;
}

// function to calculate and output balance with monthly deposit
double BankInfo::balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_apy, int t_numberOfYears) {
	m_totalAmount = t_initialInvestment;

	// output message for header info
	cout << endl << "     Balance and Interest With Additional Monthly Deposits" << endl;

	// calls tableHeading function to display table header
	tableHeading();

	// Calculate yearly interest and year end total
	for (int i = 0; i < t_numberOfYears; i++) {
		m_yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			m_apy = (m_totalAmount + t_monthlyDeposit) * ((t_apy / 100.00) / 12.00);
			m_yearlyTotalInterest = m_yearlyTotalInterest + m_apy;
			m_totalAmount = m_totalAmount + t_monthlyDeposit + m_apy;
		}

		cout << " " << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_yearlyTotalInterest << endl;
	}

	return m_totalAmount;
}


// function to display homescreen info and also get user input
void printHomeScreen() {
	try {
		// output messages for formatting home screen
		cout << "**********************************" << endl;
		cout << "********** Data Input ************" << endl;
		cout << "Initial Investment Amount: $";

		// input validation for getting initialInvestment 
		initialInvestment = validDoubleInput();
		if (initialInvestment < 0) {
			throw runtime_error("Invalid entry.");
		}

		myInvestment.SetInitialInvestment(initialInvestment);

		// input validation for getting monthlyDeposit 
		cout << "Monthly Deposit: $";
		monthlyDeposit = validDoubleInput();
		if (monthlyDeposit < 0) {
			throw runtime_error("Invalid entry.");
		}

		myInvestment.SetMonthlyDeposit(monthlyDeposit);

		// input validation for getting apy
		cout << "Annual Interest: %";
		apy = validDoubleInput();;
		if (apy < 0) {
			throw runtime_error("Invalid entry.");
		}

		myInvestment.SetInterestRate(apy);

		// input validation for getting years
		cout << "Number of years: ";
		years = validIntInput();
		if (years <= 0) {
			throw runtime_error("Invalid entry.");
		}

		myInvestment.SetNumberOfYears(years);

		system("PAUSE");
	}

	// outputs error to user if a negative value is entered. then prompts user to reset the homescreen by pressing any key
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Enter a value that is not negative." << endl;
		system("PAUSE");
		system("cls");
		printHomeScreen();
	}
}

// input validation to only accept an int as input
int validIntInput() {
	int x;

	while (1) {
		if (cin >> x) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid input, enter a valid number.";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}

// input validation to confirm input is a double
double validDoubleInput() {
	double x;

	while (1) {
		if (cin >> x) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid input, enter a valid number: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}


// main function
int main() {
	while ((user_input != 'q') && (user_input != 'Q')) {
		system("cls");
		printHomeScreen();

		myInvestment.calcBalanceWithoutMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());
		myInvestment.balanceWithMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetMonthlyDeposit(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());

		cout << "Please enter 'q' or 'Q' to quit. Enter any other character or number to run another report. ";
		cin >> user_input;
	}

	return 0;
}
