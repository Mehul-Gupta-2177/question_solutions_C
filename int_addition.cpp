#include<iostream>
#include<string>
#include<utility>
#include<math.h>
#include <vector>
#include <unordered_map>


// question: aˆ3 + bˆ3 = cˆ3 + dˆ3. find all positive intger
// sols under 1k
// can use a hashmap 
// runtime = O(n^2)

using namespace std;

int main() {
    int n = 20;
    unordered_map<int, vector< pair<int, int> > > hashmap;
    for(int c = 0; c < n; c++){
        for (int d = 0; d < n; d++){
            int result = pow(c,3) + pow(d,3);
            pair<int, int> temp;
            temp.first = c;
            temp.second = d;
            hashmap[result].push_back(temp);  
        }
    }

    for(int a = 0; a < n; a++){
        for (int b = 0; b < n; b++){
            int result = pow(a,3) + pow(b,3);
            vector< pair<int, int> > temp_vec = hashmap[result];

            for(int i = 0; i < int(temp_vec.size()); i++){
                cout << a << "," << b << "," << temp_vec[i].first << "," <<  temp_vec[i].second<<endl;
            }

        }
    }    
   return 0; 
}