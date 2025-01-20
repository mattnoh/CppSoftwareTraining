#ifndef contactfuc_H
#define contactfuc_H

#include <string>
#include <iostream>
#include <ncurses.h> //for terminal control functions getch().

using namespace std;

bool name_valid(string);  //check if a name is not empty and within character limits.
bool num_valid(string);   //check if a phone number is not empty and within character limits.


string temp_name, temp_num, temp_nname;
int choice, i, counter;
bool flag;
bool cancel_flag;


class contact { 

    string name; // contact name
    string num; // contact number
    string nickname;

    public:

    contact() : name(""), num(""), nickname("")   // constructor within the class with initializer List
    {}


    // shows all contacts
    // if the contact exists send 1 if not 0
    bool show(){
        if(name !=""){                                      // if the name is not blank
            cout << name << "\t" << num << "\t" << nickname << endl;            // print name and number (contact details *need to add nicknames!*)
            return 1;
        }
        else
            return 0;
    }   

    // search function
    bool show(string search){                               // takes string search to bool
        if(search == name){                                 // match if the search string matches details in name string
            cout << name << "\t" << num << endl;
            return 1;     
        }
        else
            return 0;
    }

    //checking if name exists
    bool name_exists(string tname){                         // if temp_name = name name exists is true
        if (tname == name)
            return 1;
        else   
            return 0;
    }

    // contact object initialized by valid values
    bool add(string new_name, string new_num, string new_nickname){              // if name is blank
        if(name==""){                       
            name = new_name;                                // put the given new_ into name
            num = new_num;
            nickname = new_nickname;
            return 1;
        }
        else 
            return 0;
    }

    //edit contact
    bool edit(string);

    //delate contact details
    bool erase(string new_name){                            // if the provied new_name matches name
        if ( new_name == name){                             // turn name and number string into blank
            name = "";
            num =  "";
            nickname = "";
            return 1;
        }
        else 
            return 0;
    }
};

//edit the contacts
bool contact :: edit (string new_name){                     //

    string new_num;
    if (new_name == name){

        cout << "Enter New name: "; 
        cin >> new_name;

        cout << "Enter New Number: ";
        cin >> new_num;

        name = new_name;
        num = new_num;
        return 1;
    }
    else 
        return 0;
}

contact person [50];

void showContacts() {

    cout << "Showing Contacts" << endl;

        for (i = 0; i<50; i++){
            if(person[i].show())
                flag = 1;
        }

        if(!flag)
            cout << "No Contacts Found!" << endl;
}

void addContacts() {
    
    cout << "Add New Contact" << endl;
            counter = 0;

            //loop until correct and mobile number are entered

            do {
                flag = 0;
                if(counter)
                    cout << "Try Again\t\t\t\tpress $ to cancel" << endl;
                
                //counts how many times the do-while loop executes
                counter++;

                cout <<"name: ";
                cin >> temp_name;

                cout << "Mobile Number: ";
                cin >> temp_num;

                cout << "Nickname:  ";
                cin >> temp_nname;

                for(i=0; i<50; i++)
                    if (person[i].name_exists(temp_name)){
                        cout << "the entered name already exists" << endl;
                        flag = 1;
                        break;
                    }
            }while(!name_valid(temp_name) ||
                            flag ||
                    !num_valid(temp_num));


            //adding the contact to phonebook

            for(i=0; i<50; i++)
                if(person[i].add(temp_name, temp_num, temp_nname)){

                    cout << "Contact Added Successfully" <<endl;
                    flag  = 1;
                    break;
                }
            if(!flag)
                cout << "Memory full" << endl;


}

void editContacts () {

    cout << "Enter a Contact name to Edit:"
        "\t\t\t\t\n";

    cin >> temp_name;

        for(i=0;i,50; i++)
            if(person[i].edit(temp_name)){
                cout << "edited Sucessfully" << endl;
                flag = 1;
                break;
            }
        if(!flag)
            cout<< " Contact name Not Found" << endl;
}


void deleteContacts () {
    do
            {
                if(counter)
                    cout<< "Try Again" << endl;
                counter++;
                cout << "Enter a Contact name to Delete;" ;
                cin >> temp_name;

                // confirmation
                for (i=0; i<50; i++)
                if(person[i].name_exists(temp_name)){

                    flag =11;
                    cout << "Are You Sure You Want to Delete? (1/0)" << endl;

                    int yes;
                    cin >> yes;
                    if(!yes) {
                        system("cls");
                        cancel_flag =1;
                    }
                    break;
                }

                if(!flag)
                cout << "Contact name Not Found" << endl;
                if(cancel_flag)
                break;

                
                //deletes the contact
                if(flag){
                    for(i=0; i<50; i++)
                        if(person[i].erase(temp_name)){
                            cout << "Deleted Successfully" << endl;
                            break;
                    }
                }

            }while (!flag);
           
}

void searchContacts(){

    do {
                if(counter)
                    cout<< "Try Again" << endl;
                counter++;
                cout<< "Search A name: \t\t\t\tPress$ to Cancel\n";
                cin >> temp_name;

                //cancel operation
                if(temp_name=="$"){
                    system("cis");
                    break;
                }

                for(i=0; i<50; i++)
                    if(person[i].show(temp_name)){
                        flag=1;
                        break;
                    }
                if(!flag)
                    cout << "Contact name Not Found" << endl;
            }while(!flag);
}


#endif 