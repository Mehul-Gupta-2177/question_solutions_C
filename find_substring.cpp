#include<iostream>
#include<string>
#include<vector>
using namespace std;

// finds a how many times a substring is there within a given string
// and printing its location
// Optimal O(n) solution = KMP algorithm

// Acknowledgement GeeksforGeeks

// LPS =  longest proper prefix which is also suffix. 

void computeLPSArray(string substring, int substr_len, int lps[]); 
int KMPSearch(string substring, string string_given);

// NAIVE APPROACH in the making
//vector<int> number_of_time(string str, string substr);


int main() {

    // sets and gets all the strings
    cout << "String?" << endl;
    string string_given;
    cin >> string_given;
    cout << "subString?" << endl;
    string sub_string_given;
    cin >> sub_string_given;
    cout << endl;
    
   // number_of_time(string_given, sub_string_given);
   int instance = KMPSearch(sub_string_given, string_given);

    cout << "Num of Matches " << instance << endl;
    return 0;

}

//NAIVE APPROACH SO DROPPED 
/*vector<int> number_of_time(string str, string substr){
    
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


    return index;
    // slide window for all indexes, where +1 index is there and check is substr is there

}*/
int KMPSearch(string substring, string string_given)
{
    int substr_len = substring.size();
    int str_len = string_given.size();

    int lps[substr_len];

    // passing array by reference
    // can also be a vector instead of an array in lps
    computeLPSArray( substring, substr_len, lps);

    int i = 0;
    int j = 0;
    int count = 0;
    while(i < str_len )
    {
        if(substring[j]==string_given[i])
        {
            // if both the jth char in substr and ith char in str match, increment both
            i++;
            j++;
        }
        if (j == substr_len) { 
            // if j==substr_len it is confirmed that we have found the pattern and we output the index
            cout<<i - substr_len <<" index: match" << endl;
            //  update j as lps of last matched character in substring
            j = lps[j - 1]; 
            // number matches are incremented
            count++;
        } 
        else if (i < str_len && substring[j] != string_given[i]) {  
            // If match fails
            if (j == 0)
            {
                // and no character match has taken place only increment i;
                i++;
            }    
            else
                j = lps[j - 1];  //Update j as lps of last matched character
        }
    }

    return count;
}

void computeLPSArray(string substring, int substr_len, int lps[])
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // starting at the second letter of the substring
    int i = 1;
    
    // the loop calculates lps[i] for i = 1 to substr_len-1
    // and fills the array according to the pattern where we see 
    // how much are the characters repeated from the prefix and the suffix
    // for eg AABAACCCAABAA will have an lps array of 
    //        [0,1,0,1,2,0,0,0,1,2,3,4,5]

    while (i < substr_len )
    {
        if(substring[i]==substring[len])
        {   
            // increases the length of the longest 
            // prefix suffix to one
            len++;
            // tells the prefix of this string at this point is 
            // the same as the leading suffix
            lps[i] = len;
            // increments the i by 1
            i++;
            continue;
        }
        else
        {     
            //  if there is nothing in common 
            //  with the prefix and length is of the 
            // longest prefix suffix  is 0, it 
            // sets the value of that lps 
            // position as 0     
            // and increments the i     
            if(len==0)
            {      
                
                lps[i] = 0;
                i++;
                continue;
            }
            else
            {
                // if the longest prefix suffix
                // still continuing it sets the
                // len as the len of the lps before that
                // to see if any character is common after that
                // for example AACAACA
                // it goes [0,1,0,1,2,3,1]   
                len = lps[len-1];
                continue;
            }
        }
    }
    


}