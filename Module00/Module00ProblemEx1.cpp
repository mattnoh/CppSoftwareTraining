#include <iostream>
#include <string>
#include <cctype>  // for toupper and tolower function

using namespace std;

int main() {

    string input;
    cout << "Write: ./convert (up or down) 'string' = ";
    getline(cin, input); // read the entire input


    if (input.substr(0, 13) == "./convert up ") { // from 0 to 13 check if the user wrote ./convert up
        string text = input.substr(13); // starting fromm 13 take the written text into a new string
        for (int i = 0; i < text.length(); ++i) {  // loop from i = 0 to i < str.length()
            text[i] = toupper(text[i]);  // make each letter into uppercase
        }
        cout << text << endl;

    } else if (input.substr(0, 15) == "./convert down ") {  // from 0 to 15 check if the user wrote ./convert down
        string text = input.substr(15);
        for (int i = 0; i < text.length(); ++i) {  // Loop from i = 0 to i < str.length()
            text[i] = tolower(text[i]);  // Modify each character in the string
        }
        cout << text << endl;
    }

    return 0;
}
