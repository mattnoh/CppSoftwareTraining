#include <string>
#include <iostream>
#include <ncurses.h> //for terminal control functions getch().

using namespace std;

bool name_valid(string);  //check if a name is not empty and within character limits.
bool num_valid(string);   //check if a phone number is not empty and within character limits.


// use class to create user-defined data type to hold data members and member functions, 
// which can be accessed and used by creating an instance of that class.

class contact { 

    string name; // contact name
    string num; // contact number

    public:

    contact() : name(""), num("")    // constructor within the class with initializer List
    {}


    // shows all contacts
    // if the contact exists send 1 if not 0
    bool show(){
        if(name !=""){                                      // if the name is not blank
            cout << name << "\t" << num << endl;            // print name and number (contact details *need to add nicknames!*)
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
    bool add(string new_name, string new_num){              // if name is blank
        if(name==""){                       
            name = new_name;                                // put the given new_ into name
            num = new_num;
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

        cout << "Enter New Name: "; 
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

// main part of the phonebook

int main () {

    contact person [50];

    string temp_name, temp_num;
    int choice, i, counter;
    bool flag;
    bool cancel_flag;

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
            cout << "Showing Contacts" << endl;

            for (i = 0; i<50; i++){
                if(person[i].show())
                    flag = 1;
            }

            if(!flag)
                cout << "No Contacts Found!" << endl;
          
            break;
        
        case 1:
            cout << "Add New Contact" << endl;
            counter = 0;

            //loop until correct and mobile number are entered

            do {
                flag = 0;
                if(counter)
                    cout << "Try Again\t\t\t\tpress $ to cancel" << endl;
                
                //counts how many times the do-while loop executes
                counter++;

                cout <<"Name: ";
                cin >> temp_name;

                cout << "Mobile Number: ";
                cin >> temp_num;

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
                if(person[i].add(temp_name, temp_num)){

                    cout << "Contact Added Successfully" <<endl;
                    flag  = 1;
                    break;
                }
            if(!flag)
                cout << "Memory full" << endl;
            break;

        case 2:
            cout << "Enter a Contact Name to Edit:"
            "\t\t\t\t\n";

            cin >> temp_name;

            for(i=0;i,50; i++)
                if(person[i].edit(temp_name)){
                    cout << "edited Sucessfully" << endl;
                    flag = 1;
                    break;
                }
            if(!flag)
                cout<< " Contact Name Not Found" << endl;
            break;

        case 3:
            do
            {
                if(counter)
                    cout<< "Try Again" << endl;
                counter++;
                cout << "Enter a Contact Name to Delete;" ;
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
                cout << "Contact Name Not Found" << endl;
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
            break;

        case 4:
            do {
                if(counter)
                    cout<< "Try Again" << endl;
                counter++;
                cout<< "Search A Name: \t\t\t\tPress$ to Cancel\n";
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
                    cout << "Contact Name Not Found" << endl;
            }while(!flag);

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

    if(tnum.size()>13) {
        
        cout << "Invalid Number\nEnter A Number Within 20 char" << endl;
        return 0;
    }
    else if(tnum == ""){

        cout << "Invalid Number\nNumber Cannot be Blank" << endl;
        return 0;
    }
    else 
        return 1; 
}