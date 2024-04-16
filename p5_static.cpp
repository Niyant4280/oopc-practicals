#include<iostream>
using namespace std;


#define pi 3.148

// Class for setting radius and calculating area of circle
class set_radius{
    private:
        float r;
        float ar_circle;
        int count=0;
    public:
        // Default constructor
        set_radius()
        {
            area(r);
            count++;
            cout << count;
            object();
        }

        // Parameterized constructor with radius input
        set_radius(float r)
        {
            area(r);
            count++;
            cout << count;
            object();
        }

        // Function to calculate area of circle
        float area(float r)
        {
            cout << "Radius of Circle :";
            cin >> r;
            ar_circle=pi*r*r;
            cout << ar_circle << endl;
            return ar_circle;
        }

        // Destructor
        ~set_radius()
        {
            cout << "one object is Deleted" << endl;
            count--;
        }

        // Function to display the total active objects
        void object()
        {
            cout << "Total active Objects are: " << count << endl; // Display the total active objects
        }
};


int main()
{
    float r;
    set_radius c1 ,c2(20),c3(c1);

    return 0;
}
