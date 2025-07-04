/*
Given a string, your task is to generate all different strings that can be created using its characters.

Input
The only input line has a string of length n. Each character is between a–z.

Output
First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.

Constraints
1<=n<=8

Example

Input:
aabac

Output:
20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa
*/ 

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
    
int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin>>str;

    sort(str.begin(), str.end());

    vector<string> permutation;

    do{
        permutation.push_back(str);
    }
    while(next_permutation(str.begin(), str.end()));

    cout<<permutation.size()<<endl;
    
    for(auto &s : permutation){
        cout<<s<<endl;
    }

    return 0;
}