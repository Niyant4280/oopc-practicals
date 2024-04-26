
#include<iostream>
using namespace std;

class literature {
    int id;
    string title;
public:
    void getdata() {
        cout << "Enter id of literature: ";
        cin >> id;
        cout << "Enter title of literature: ";
        cin >> title;
    }

    void putdata() {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
    }
};

class elit : public virtual literature {
    string DOI;
public:
    void getdata1() {
        cout << "Enter DOI: ";
        cin >> DOI;
    }

    void putdata1() {
        cout << "DOI: " << DOI << endl;
    }
};

class hardbound : public virtual literature {
    int copies; // Number of copies in stock
public:
    void getdata2() {
        cout << "Enter number of copies in stock: ";
        cin >> copies;
    }

    void putdata2() {
        cout << "Copies in stock: " << copies << endl;
    }
};

class books : public elit, public hardbound {
    int ISBN_no;
    char temp;

public:
    static const int MAX_BOOKS = 20;
    static int bookCount;
    void getdata3() {
        literature::getdata();
        cout << "Enter ISBN number: ";
        cin >> ISBN_no;
        cout << "(E) copy or (H) hardbound: ";
        cin >> temp;

        if (temp == 'E') {
            elit::getdata1();
        } else if (temp == 'H') {
            hardbound::getdata2();
        }
        bookCount++;
    }

    void putdata3() {
        literature::putdata();
        cout << "ISBN number: " << ISBN_no << endl;
        if (temp == 'E') {
            elit::putdata1();
        } else if (temp == 'H') {
            hardbound::putdata2();
        }
    }
};

class magazines : public elit, public hardbound {
    int ISSN_no;
    char temp;

public:
    static const int MAX_MAGAZINES = 20;
    static int magazineCount;
    void getdata4() {
        literature::getdata();
        cout << "Enter the ISSN number: ";
        cin >> ISSN_no;
        cout << "(E) copy or (H) hardbound: ";
        cin >> temp;

        if (temp == 'E') {
            elit::getdata1();
        } else if (temp == 'H') {
            hardbound::getdata2();
        }
        magazineCount++;
    }

    void putdata4() {
        literature::putdata();
        cout << "ISSN number: " << ISSN_no << endl;
        if (temp == 'E') {
            elit::putdata1();
        } else if (temp == 'H') {
            hardbound::putdata2();
        }
    }
};

int books::bookCount = 0;
int magazines::magazineCount = 0;

int main() {
    books b[books::MAX_BOOKS];
    magazines m[magazines::MAX_MAGAZINES];
    char ch;
    do {
        int choice;
        cout << "Enter 1: Add book data" << endl;
        cout << "Enter 2: Add magazine data" << endl;
        cout << "Enter 3: List all books" << endl;
        cout << "Enter 4: List all magazines" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                int n;
                cout << "Enter the number of books to add: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    b[i].getdata3();
                }
                break;
            }
            case 2: {
                int n;
                cout << "Enter the number of magazines to add: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    m[i].getdata4();
                }
                break;
            }
            case 3:
                for (int i = 0; i < books::bookCount; ++i) {
                    b[i].putdata3();
                }
                break;
            case 4:
                for (int i = 0; i < magazines::magazineCount; ++i) {
                    m[i].putdata4();
                }
                break;
            default:
                cout << "INVALID CHOICE!!!!!" << endl;
        }
        cout << "Enter M to goto main menu: ";
        cin >> ch;
    } while(ch == 'M' || ch == 'm');
    return 0;
}

