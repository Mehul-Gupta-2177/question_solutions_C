#include<iostream>
#include<string>
#include<vector>
using namespace std;

// finds a how many times a substring is there within a given string
// and printing its location
// Optimal O(n) solution = KMP algorithm
vector<int> number_of_time(string str, string substr);
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

vector<int> number_of_time(string str, string substr){
    
    // checker 1
    vector<int> index;
    if(substr.size() > str.size()){
        index.push_back(0);
        return index;
    }
    // checker 2
    if(substr.size() == str.size()){
        if(substr == str){
            index.push_back(1);
            index.push_back(0);
            return index;
        }
    }

    int final_char_index = str.size() - substr.size() - 1;
    int count = 0;
    for(int i = 0; i <= final_char_index; i++){

    }


    return index;

}