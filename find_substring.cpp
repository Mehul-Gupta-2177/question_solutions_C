#include<iostream>
#include<string>
using namespace std;

// finds a how many times a substring is there within a given string
int number_of_time(string str, string substr);
int main() {

    // sets and gets all the strings
    cout << "String?" << endl;
    string string_given;
    cin >> string_given;
    cout << "subString?" << endl;
    string sub_string_given;
    cin >> sub_string_given;
    cout << endl;
    
    number_of_time(string_given, sub_string_given);

    return 0;

}

int number_of_time(string str, string substr){
    
    if(substr.size() > str.size()){
        return 0;
    }
    
    bool a = true; 

    int initial_char_at = 0;
    while(a){
        
    }



    return 0;

}