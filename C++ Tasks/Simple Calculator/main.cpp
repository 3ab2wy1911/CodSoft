#include <bits/stdc++.h>
using namespace std;
/*
TASK 2
SIMPLE CALCULATOR
3 / 9 / 2023
A calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.
 */

void calc() {

    int num1, num2 , choice =1;
//________________________________________________________________

    cout <<"Welcome to SIMPLE CALCULATOR"<<endl;
    cout << "********************************"<<endl;
    while(choice)
    {
        cout << "Choose the number of the operation to perform : \n1. Addition\n2. Subtraction\n3.Multiplication\n4.Division\n0.Exit\n";
        cin >> choice;
        cout << "Enter First Number : \n";
        cin>>num1;
        cout << "Enter Second Number : \n";
        cin>>num2;

//________________________________________________________________

        if (choice<0 or choice>4 or (!num2 and choice == 4)){   // handle the case where user enters invalid choice or divide by zero.
            cout << "Bad Input !!!"<<endl;
            continue;
        }

//________________________________________________________________
        cout << "The result = ";
        switch (choice) {   // Print the result to the user depending on his choice.
            case 1: cout << num1 + num2<<endl;
            break;
            case 2: cout << num1 - num2<<endl;
            break;
            case 3: cout << num1 * num2 << endl;
            break;
            case 4: cout << num1 / num2 << endl;
            break;
            default: cout << "Bad Choice !!!"<<endl;
        }
    }
}

//________________________________________________________________

int main() {
    calc();
}
