#include<iostream>
using namespace std;


class employee {
public:
    int id;
    string name, qualification;
    float exp;
    int mo_no;
    static int count_call; // Static variable to count the number of employee data entries
    static float total_experience; // Static variable to store the total experience of all employees

public:
    // Function to get data for an employee
    void getdata() {
        cout << "Please Enter the Name of the Employee:" << endl;
        cin >> name;
        cout << "Please Enter the Qualification of the Employee:" << endl;
        cin >> qualification;
        cout << "Please Enter the Experience of the Employee:" << endl;
        cin >> exp;
        total_experience += exp; // Add employee's experience to the total experience
        cout << "Please Enter the Mobile Number of the Employee:" << endl;
        cin >> mo_no;
        count_call++; // Increment the count of employee data entries
    }

    // Function to display data for an employee
    void displaydata() const {
        cout << "Name of the Employee:" << name << endl;
        cout << "Qualification of the Employee:" << qualification << endl;
        cout << "Experience of the Employee:" << exp << endl;
        cout << "Mobile Number of the Employee:" << mo_no << endl;
    }

    // Static function to display the count of employee data entries
    static void displaycount() {
        cout << "Number of employee data entries: " << count_call << endl;
    }

    // Static function to calculate the average experience of all employees
    static float avg_exp() {
        if (count_call == 0) { // Check if there are no employee data entries
            return 0; // Return 0 to avoid division by zero
        }
        return total_experience / count_call;
    }
};

// Initialization of static variables outside the class
int employee::count_call = 0;
float employee::total_experience = 0;

int main() {
    int n;
    cout << "Enter the number of employees you want to enter data for: ";
    cin >> n;

    // Dynamically allocate an array of employee objects
    employee *employees = new employee[n];

    // Loop to get data for each employee
    for (int i = 0; i < n; ++i) {
        cout << "Please Enter the Id for employee " << (i + 1) << ":" << endl;
        cin >> employees[i].id;

        // Validate employee ID
        if (employees[i].id < 1000 || employees[i].id > 9999) {
            cout << "Invalid Id Entered" << endl;
            --i; //
            continue;
        }

        employees[i].getdata();
        employees[i].displaydata();

        cout << "Press Y to enter data for another employee or press N to exit : ";
        char opt;
        cin >> opt;

        if (opt != 'Y' && opt != 'y') {
            break;
        }
    }

    employee::displaycount();
    cout << "Average experience of all employees: " << employee::avg_exp() << " years" << endl;

    delete[] employees; // Deallocate the dynamic array
    return 0;
}
