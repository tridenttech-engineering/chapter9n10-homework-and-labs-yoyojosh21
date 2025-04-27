//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);
double getTotal(double, int);

int main()
{
    //declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    //call function to calculate payments
    creditPayment = getPayment(carPrice - rebate,
        creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, 
        dealerRate / 12, term * 12);    //assign values to calculate payments

    //display payments
    cout << fixed << setprecision(2) << endl; 
    if (creditPayment==-1 || dealerPayment==-1){
        cout << "Error : interest rate cannot be zero"<< endl;
    } else{
        cout << "Credit union payment: $" << creditPayment << endl;
        cout << "Dealer payment: $" << dealerPayment << endl;
        cout << "Total paid through credit union: $" << getTotal(creditPayment, term * 12) << endl;
        cout << "Total paid through dealer: $" << getTotal(dealerPayment, term * 12) << endl;
    }


    return 0;
}//end of main function    

    //*****function definitions*****
double getPayment(int prin,
                  double monthRate, 
                  int months)
{
    if (monthRate ==0)
        return -1;
    //calculates and returns a monthly payment

    double monthPay = prin * monthRate / 
        (1 - pow(monthRate + 1, -months));
    return static_cast<int>((monthPay + 0.005) * 100) / 100.0;;
} //end of getPayment function//*****function definition*****
double getTotal(double monthPay, int months)
{
    return static_cast<int>((monthPay * months + 0.005) * 100) / 100.0;
}