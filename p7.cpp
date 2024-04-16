#include<iostream>
using namespace std;


class complex {
private:
    float r;
    float i;

public:
    // Function to get data for a complex number
    void getdata() {
        cout << "Real part :" << endl;
        cin >> r;
        cout << "Imaginary part :" << endl;
        cin >> i;
    }

    // Overloaded addition operator
    complex operator +(complex temp1) {
        complex temp2;
        temp2.r = r + temp1.r;
        temp2.i = i + temp1.i;
        return temp2;
    }

    // Overloaded subtraction operator
    complex operator -(complex temp1) {
        complex temp2;
        temp2.r = r - temp1.r;
        temp2.i = i - temp1.i;
        return temp2;
    }

    // Overloaded multiplication operator
    complex operator *(complex temp1) {
        complex temp2;
        // Perform complex multiplication
        temp2.r = (r * temp1.r) - (i * temp1.i);
        temp2.i = (r * temp1.i) + (i * temp1.r);
        return temp2;
    }

    // Overloaded division operator
    complex operator /(complex temp1) {
        complex temp2;
        // Perform complex division
        temp2.r = ((r * temp1.r) + (i * temp1.i)) / (i * i + temp1.i * temp1.i);
        temp2.i = ((r * temp1.r) - (i * temp1.i)) / (i * i + temp1.i * temp1.i);
        return temp2;
    }

    // Function to display a complex number
    void putdata() {
        cout << r << "+" << i << "i" << endl;
    }
};

// Main function
int main() {
    complex c1, c2, c3;
    c1.getdata();
    c2.getdata();

    char ch;
    cout << "Choose operator :" << endl;
    cout << "(+) Addition" << endl;
    cout << "(-) Subtraction" << endl;
    cout << "(*) Multiplication" << endl;
    cout << "(/) Division" << endl;
    cin >> ch;

    // Perform operation based on user's choice
    switch(ch) {
        case '+':
            c3 = c1 + c2;
            c3.putdata();
            break;
        case '-':
            c3 = c1 - c2;
            c3.putdata();
            break;
        case '*':
            c3 = c1 * c2;
            c3.putdata();
            break;
        case '/':
            c3 = c1 / c2;
            c3.putdata();
            break;
        default:
            cout << "Invalid operator!!!!!!";
    }

    return 0;
}
