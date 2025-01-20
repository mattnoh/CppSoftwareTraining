#include <string>
#include <iostream>
#include <ncurses.h> //for terminal control functions getch().
#include "contactfuncs.h"

using namespace std;

bool name_valid(string);  //check if a name is not empty and within character limits.
bool num_valid(string);   //check if a phone number is not empty and within character limits.


// use class to create user-defined data type to hold data members and member functions, 
// which can be accessed and used by creating an instance of that class.


// main part of the phonebook

int main () {



    cout << "-- PHONEBOOK --" << endl;

    do {                                                    // this do while loop displays the menu
                                                            // and when user inputs with "choice" executes each corresponding case 
        cout << "\n\n\n";
        cout << "0. Show Contacts" << endl
        << "1. Add Contacts" << endl
        << "2. Edit Contacts" << endl
        << "3. Delete Contacts" << endl
        << "4. Search" << endl
        << "5. Quit" << endl << endl
        << "Your Choice...";
        cin >> choice;

        system("clear");
        cancel_flag = 0;
        flag = 0;
        counter = 0;

        switch (choice) {
        case 0: 
            showContacts();
            break;
        case 1:
            addContacts();
            break;
        case 2:
            editContacts();
            break;
        case 3:
            deleteContacts();
            break;
        case 4:
            searchContacts();
            break;
        case 5:
            return 0;
            break;

        default:
            break;
        }
    }while(1);

    getch();
    return 0;

}

bool name_valid(string tname){

    if(tname.size()>20){
        
        cout << "Invalid Name\nEnter A Name Within 20 char" << endl;
        return 0;
    }
    else if(tname == ""){

        cout << "Invalid Name\nName Cannot be Blank" << endl;
        return 0;
    }
    else 
        return 1; 
}

bool num_valid(string tnum){

    if(tnum.size()<13) {
        
        cout << "Invalid Number\nEnter A Number Over 13 char" << endl;
        return 0;
    }
    else if(tnum == ""){

        cout << "Invalid Number\nNumber Cannot be Blank" << endl;
        return 0;
    }
    else 
        return 1; 
}