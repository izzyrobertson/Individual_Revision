// CS105_Revision_4-9-21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Base { //grandparent class
protected: //protected for inheritance use
    int a, b;

public:
    Base(int x = 0, int y = 0) { //constructor
        a = x;
        b = y;
    }
    void Input() {
        Loop: //local loop variable
            cout << "\nPlease input the first integer: ";
            cin >> a;
            if (a <= 0 || a >= 1000000) {
                cout << "\nPlease enter a number between 0 to 1000000" << endl;
                goto Loop; //loops back to question while answer is not between numbers
            }
            Loop2: //local loop variable
            cout << "\nPlease input the second integer: ";
            cin >> b;
            if (b <= 0 || b >= 1000000) {
                cout << "\nPlease enter a number between 0 to 1000000" << endl;
                goto Loop2; //loops back to question while answer is not between numbers
            }
    }
};

class Summation : public Base { //parent class
protected:
    int sum; //protected for inheritance use
public:
    void calculate() {
        sum = a + b; //value for sum added through inheritated values of a and b
    }
};

class Display: public Summation { //child class
public:
    void display() {
        cout << "\nA: " << a << endl; //inheritated from grandparent class
        cout << "\nB: " << b << endl; //inheritated from grandparent class
        cout << "A + B = " << sum; //inheritated from parent class
    }
};

int main()
{
    Display d; //object
    int T = 0;

    Loop: //local loop variable
    cout << "\nHow many test cases would you like: ";
    cin >> T;
    if (T <= 0 || T > 10) { 
        cout << "\nPlease enter between 1 or 10 tests!";
        goto Loop;
    }

    for (int i = 0; i < T; i++) { //calls functions through child class object
        d.Input();
        d.calculate(); //calculate() function must be called to intialize value of sum in display() function
        d.display();
    }
}
