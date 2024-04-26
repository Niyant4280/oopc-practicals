#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

int main()
{

    ifstream inf("cardata.txt");

    if (!inf) {
		cout << "Unable to open file";
		return 1;
	}

	cout<<"File opened successfully\n";
	string model_name,fuel_type, trans, airbag;
	string price, mileage, tc;
	float price1, mileage1, tc1;
	string seating;
	int seating1;
	while(inf)
    {
        getline(inf,model_name,',');
        cout<<"model name = "<<model_name<<endl;
        getline(inf,fuel_type,',');
        cout<<"fuel Type = "<<fuel_type<<endl;
        getline(inf,price,',');
        price1 = stof(price);
        cout<<"Price = "<<price1<<endl;
        price1 = stof(price);
        getline(inf,mileage,',');
        mileage1 = stof(mileage);
        cout<<"mileage = "<<mileage1<<endl;
        getline(inf,trans,',');
        cout<<"Transmission = "<<trans<<endl;
        getline(inf,tc,',');
        tc1 = stof(tc);
        cout<<"Tank Capacity = "<<tc1<<endl;
        getline(inf,seating,',');
        seating1 = stod(seating);
        cout<<"Seating = "<<seating1<<endl;
        getline(inf,airbag,';');
        cout<<"Airbags = "<<airbag<<endl;

    }

    inf.close();

    getch();



    return 0;
}

