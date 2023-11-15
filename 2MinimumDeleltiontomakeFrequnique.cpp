#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        map<char,int> hash; // created map to count the frequency of each char
        for(int i=0;i<s.size();++i){
            hash[s[i]]++; // char freq stored into map
        }
        vector<int> freq; // created freq vector which will store frequency
        for(auto &val: hash){
            freq.emplace_back(val.second); // storing frequency from map
        }
        set<int> st; // set for putting freq into it 
        int good = 0; //creating variable good to store how many char to be deleted to make it good
        for(int i=0;i<freq.size();++i){
            auto it = st.find(freq[i]); // freq[i] is located in set st
            if(it!=st.end() && freq[i]!=0){ // freq[i] must not be 0 and succesffuly found in set
                freq[i]--; // decrementing if found in set like 3 3 2
                good++;  // incrementing deleted counter 
                i--; // going back if 3 2 2 here 2 is also present so it must be deleted again
            }
            else{
                st.insert(freq[i]); // not present in set then putting into it
            }
        }
        return good;        
    }
};

int main(){
    Solution s;
    string st = "aab";
    cout<<s.minDeletions(st);
    return 0;
}