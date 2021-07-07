#include<iostream>
#include<string>
using namespace std;

// finds a how many substrings are there within a given string
int number_of_time(string str);
int main() {

    // sets and gets all the strings
    cout << "String?" << endl;
    string string_given;
    cin >> string_given;
    int total_sub = number_of_time(string_given);
    cout << "number of substrings = " << total_sub << endl;
    return 0;

}

int number_of_time(string str){
    
    int n = str.size();
    // as we see that say for 5 chars
    // the num of substrings are 
    // 5 + 4 + 3 + 2 + 1
    // n + n - 1 + n - 2..... + n - n + 1 
    // which is  Σ n -  i + 1, where  i = 1 -> n
    // therefore by using calculus we get
    // = n^2  - ((n(n+1))/2) + n 
    // = n(n+1) - ((n(n+1))/2)
    // ==((n(n+1))/2)
    int num = ((n*(n+1))/2);
    return num;

}