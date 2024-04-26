#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class tata
{

private:  // data member
    string model;
    string fuel_type_name;
    double price;
    double milage;
    string transmission;
    double tank_capacity;
    int no_seats;
    string airbag_name;

public:
    bool airBag;

    void get_data(string modelName, string fuel, double money, double mil, string transmi, double tank_capa, int seatNo, string airBag)
    { // function to get car data from text file.
        // passing perameter into getdata().
        model = modelName;
        fuel_type_name = fuel;
        price = money;
        milage = mil;
        transmission = transmi;
        tank_capacity = tank_capa;
        no_seats = seatNo;
        airbag_name = airBag;
    }

    void model_option()
    { // function to saw only model of car.

        cout << model;
    }

    void get_data_option1()
    // show only any one car details which is choosen by user.
    {
        cout << setw(10) << model << setw(10) << fuel_type_name << setw(10) << price << setw(12) << milage << setw(15) << transmission << setw(15) << tank_capacity << setw(10) << no_seats << setw(10) << airbag_name;

        cout << endl
             << endl; // saw property of car , with proper aligment using setw.
    }

    void get_data_option2(string fual_option2)
    { // function for sutaibale for option 2.
    // show perticular fuel type car models.

        if (fuel_type_name == fual_option2)
        {
            cout << setw(10) << model << setw(10) << fuel_type_name << setw(10) << price << setw(12) << milage << setw(15) << transmission << setw(15) << tank_capacity << setw(10) << no_seats << setw(10) << airbag_name;

            cout << endl
                 << endl;
        }
    }

    void get_data_option3(int budget)
    {// show car models that's price is below than user budget.

        if (budget >= price)
        {
            cout << setw(10) << model<< setw(10) << fuel_type_name << setw(10) << price << setw(12) << milage << setw(15) << transmission << setw(15) << tank_capacity << setw(10) << no_seats << setw(10) << airbag_name;

            cout << endl
                 << endl;
        }
    }
};

int main()
{

    int count = 0;

    tata car[100];
    string fual_option2;
    float budget;


    ifstream f("cardata.txt"); // open cardata.txt file

    if (!f) // if file is not open then show error.
    {
        cout << "File not found !";
        return 1;
    }

    // veriable that's store string which is get by txt file
    string modale;
    string fuel_type_name;
    string price;
    string milage;
    string transmission;
    string tank_capacity;
    string no_seats;
    string airbag_name;

    // used to convert string into double datatype.
    double pri;
    double mil;
    double tank;
    int sea;

    while (f)  // loop that continous stroe string till ','.
    {

        cout << "getting data...";

        getline(f, modale, ','); // getline store string till ',' encountred.

        getline(f, fuel_type_name, ',');

        getline(f, price, ',');
        pri = stof(price);

        getline(f, milage, ',');
        mil = stof(milage);

        getline(f, transmission, ',');

        getline(f, tank_capacity, ',');
        tank = stof(tank_capacity);

        getline(f, no_seats, ',');
        sea = stod(no_seats);

        getline(f, airbag_name, ';');

        car[count].get_data(modale, fuel_type_name, pri, mil, transmission, tank, sea, airbag_name);
        count++;
    }

    f.close(); // close file here.

    cout << "Get The Car details Accordingly your Preference:" << endl
         << endl; // saw way to get car data
    cout << "(1) Model Name  (2) Fuel Type  (3) Price Range" << endl
         << endl;
    int option;
    cout << "Enter your Option : ";
    cin >> option; // enter your option here.
    cout << endl;

    switch (option)
    {
    case 1:

        cout << "List of TATA Cars : " << endl
             << endl;

        for (int i = 0; i < count; i++)
        { // saw only all model of tata cars.

            cout << "(" << i + 1 << ") ";
            car[i].model_option();

        }

        cout << endl
             << endl;

        cout << "Chose your Car to See Details : ";
        int car_choose;
        cin >> car_choose; // enter car model to get full details of car model.

        car[car_choose - 1].get_data_option1(); // calling option1 function to display data according them.

        break;

    case 2:

        cout << "Enter your Fuel option : ";
        cin >> fual_option2; // enter fual type

         cout << endl;


        cout << setw(10) << left << "Model" << setw(10) << "Fuel" << setw(10) << "price" << setw(12) << "Mileage" << setw(15) << "Transmission" << setw(15) << "Tank Capacity" << setw(10) << "Seating" << setw(10) << "Airbages" << endl;
        cout << setw(20) << " " << setw(10) << "(Lakhs)" << setw(10) << "(km/L)" << setw(17) << " " << setw(15) << "(Liters)" << setw(12) << "Capacity" << endl
             << endl;

        for (int i = 0; i < count; i++)
        {

            car[i].get_data_option2(fual_option2); // get specify fuale type car model details.
        }

        break;

    case 3:

        cout << "Enter your Budget : ";
        cin >> budget; // enter your budget.



        cout << setw(10) << left << "Model" << setw(10) << "Fuel" << setw(10) << "price" << setw(12) << "Mileage" << setw(15) << "Transmission" << setw(15) << "Tank Capacity" << setw(10) << "Seating" << setw(10) << "Airbages" << endl;
        cout << setw(20) << " " << setw(10) << "(Lakhs)" << setw(10) << "(km/L)" << setw(17) << " " << setw(15) << "(Liters)" << setw(12) << "Capacity" << endl
             << endl;

        for (int i = 0; i < count; i++)
        {

            car[i].get_data_option3(budget); // get model details in range of user budget.
        }

    } // switch breacket end.
}
