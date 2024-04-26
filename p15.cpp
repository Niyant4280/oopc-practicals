#include<iostream>
using namespace std;


class product
{

protected:

// data member
double product_id;
string product_name;
string product_mfg;
double product_prize;

  product(double product_id,string product_name,string product_mfg,double product_prize)
      { // perametrized constructor that's intialize data member of product class.
          this->product_id=product_id;
          this->product_name=product_name;
          this->product_mfg=product_mfg;
          this->product_prize=product_prize;
      }

    virtual putdata()=0;
    // create vertual function.

};

class smart_watch : public product{
    // inherit smart_watch from product publiclly.

protected:

double dial_size;

public:

smart_watch(double product_id,string product_name,string product_mfg,double product_prize,double dial_size):product(product_id,product_name,product_mfg,product_prize){
    // perametrized constructor intialize data member of both class.
this->dial_size=dial_size;

}

  putdata(){

 cout<<product_id<<" : "<<product_name<<" : "<<product_mfg<<" : "<<product_prize<<" : "<<dial_size<<endl;

}

};

class bed_sheet : public product{

protected:

double width;
double heigth;

public:

bed_sheet(double product_id,string product_name,string product_mfg,double product_prize,double weidth , double heigth):product(product_id,product_name,product_mfg,product_prize)
{
    this->width=weidth;
    this->heigth=heigth;
}

putdata(){

 cout<<product_id<<" : "<<product_name<<" : "<<product_mfg<<" : "<<product_prize<<" : "<<width<<" : "<<heigth<<" : "<<endl;


}

};

int main(){

    int choice;
    cout<<"Enter 1 : smart watch menu\nEnter 2 : bedsheet menu\n";
    cout<<"Enter your choice : "<<endl;
    cin>>choice;
    int id;
    string name,mfg;
    float prize,width,heigth;
    float sizz;

    switch(choice)
    {
    case 1:
        cout<<"Enter Watch data : "<<endl<<endl;
        cout<<"Enter product id : ";
        cin>>id;
        cout<<"Enter product name : ";
        cin>>name;
        cout<<"Enter product manufacturer : ";
        cin>>mfg;
        cout<<"Enter product price : ";
        cin>>prize;
        cout<<"Enter product dial size : ";
        cin>>sizz;
        smart_watch *obj1;         //Dynamic memory allocation

        obj1=new smart_watch(id,name,mfg,prize,sizz);
        obj1->putdata();
        break;
    case 2:
        cout<<"Enter badSheet data"<<endl<<endl;
        cout<<"Enter product id : ";
        cin>>id;
        cout<<"Enter product name : ";
        cin>>name;
        cout<<"Enter product manufacturer : ";
        cin>>mfg;
        cout<<"Enter product price : ";
        cin>>prize;
        cout<<"Enter bedsheet width : ";
        cin>>width;
        cout<<"Enter bedsheet height : ";
        cin>>heigth;
        bed_sheet *obj2;
        obj2=new bed_sheet(id,name,mfg,prize,width,heigth);
        obj2->putdata();
    }


}
