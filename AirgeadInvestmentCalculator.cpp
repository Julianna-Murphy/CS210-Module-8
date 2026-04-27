#include <iostream>
#include <iomanip>
#include <string>


using namespace std;


/**
 * Airgead Banking Yearly Balance and Earned Interest Calculator
 * 
 * The purpose of this program is to create a working, scalable program
 * that calculates a user's yearly balance and earned interest.
 * The user will enter an initial investment, monthly deposit(if applicable), 
 * annual interest, and number of years on the investment and the program
 * with print a yearly breakdown report on the investment.
 * 
 * Julianna Murphy
 */


/** 
 * helper to print each row starting at the year,
 * balance and interest using data collected from the user
 * setting the width for better user experience
 */
void PrintRow(int year, double balance, double interest) {
    cout << fixed << setprecision(2)
         << right << setw(6)  << year
         << right << setw(13) << balance
         << right << setw(16) << interest
         << "\n";
}

/**
 * provides a long line of dashes, of length 58 for user experience
 */
void PrintDivider() {
    cout << string(58, '-') << "\n";
}

/**
 * Prints the column headers for each monthly deposit screen
 */
void PrintHeader(const string& title) {
    const string border(58, '=');
    cout << "\n" << border << "\n";

    PrintDivider();
    cout << left << setw(8) <<"Year" << 
    right << setw(15) << "Year End Balance" 
    << right << setw(27) << "Year End Earned Interest" << endl;
    PrintDivider();
}

/**
 * prints program's opening title, use a lot of endl for alignment
 */
void PrintTitle() {
    const string border = "* * * * * * * * * * * * * * * * * * * * * *";

    cout << border              << "\n";
    cout << "**       Welcome to Airgead Banking      **" << "\n";
    cout << border              << "\n";
    cout << border              << "\n";
    cout << border              << "\n";
    cout << border              << "\n";
    cout << "**   Please Enter Your Deposit Values:   **" << "\n";
    cout << border              << "\n\n";



}

/**
 * Calculates the opening balance and earned interest
 * when the user has a monthly deposit with user inputed values
 */
void ReportNoDeposit(double principal, double annualRate, int years) {
    PrintHeader("Without Additional Monthly Deposits");

    const double monthlyRate = (annualRate / 100.0) / 12.0;
    double opening = principal;

    for (int i = 1; i <= years; ++i) {
        double yearInterest = 0.0;

        for(int j = 1; j <= 12; ++j) {
        
            double monthInterest  = opening * monthlyRate;         
            yearInterest += monthInterest;
            opening += monthInterest;
        }
        PrintRow(i, opening, yearInterest);

    }
    PrintDivider();
}

/**
 * Calculates the opening balance and earned interest
 * when the user has a monthly deposit when using user entered
 * values
 */
void ReportWithDeposit(double principal, double monthlyDeposit,
                       double annualRate, int years) {
    PrintHeader("With Additional Monthly Deposits");

    //uses provide formula in the function requirements
    const double monthlyRate = (annualRate / 100.0) / 12.0;
    const int totalMonths = years * 12;
    double opening = principal;

    for (int i = 1; i <= years; ++i) { //goes through each year to calculate year interest
        double yearInterest = 0.0;

        for(int j = 1; j <= 12; ++j) { //calculates each month to find opening balance
        
            //calculates monthly interest, increments year interest and opening balance
            double monthInterest  = (opening + monthlyDeposit) * monthlyRate;           
            yearInterest += monthInterest;
            opening += monthlyDeposit + monthInterest;
        }

        PrintRow(i, opening, yearInterest);
    
    }

    PrintDivider();
}

int main() {

    PrintTitle(); //prints title in PrintTitle function

    //creating the variables
    double initialInvestment; 
    double monthlyDeposit;    
    double annualInterest;
    int numYears;         

    //gets user input
    cout << "Initial Investment:         $";
    cin >> initialInvestment;
    cout << "Monthly Deposit:            $";
    cin >>  monthlyDeposit;
    cout << "Annual Interest (%):         ";
    cin >>  annualInterest;
    cout << "Number of Years:             "; 
    cin >> numYears;

    //gets positive value of each entered input
    initialInvestment = abs(initialInvestment);
    monthlyDeposit = abs(monthlyDeposit);
    annualInterest = abs(annualInterest);
    numYears = abs(numYears);

    cout << "\nPress any key to continue . . . \n";
    cin.get(); //ends when user presses a key

    // prints each report (without monthly deposit first, with deposit second)
    ReportNoDeposit  (initialInvestment, annualInterest, numYears);
    ReportWithDeposit(initialInvestment, monthlyDeposit, annualInterest, numYears);

    cout << "\n";
    return 0;
}