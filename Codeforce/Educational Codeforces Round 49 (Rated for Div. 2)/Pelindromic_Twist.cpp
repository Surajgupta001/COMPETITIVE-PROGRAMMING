/*
You are given a string s consisting of n lowercase Latin letters. n is even.

For each position i (1≤i≤n) in string s you are required to change the letter on this position either to the previous letter in alphabetic order or to the next one (letters 'a' and 'z' have only one of these options). Letter in every position must be changed exactly once.

For example, letter 'p' should be changed either to 'o' or to 'q', letter 'a' should be changed to 'b' and letter 'z' should be changed to 'y'.

That way string "codeforces", for example, can be changed to "dpedepqbft" ('c' → 'd', 'o' → 'p', 'd' → 'e', 'e' → 'd', 'f' → 'e', 'o' → 'p', 'r' → 'q', 'c' → 'b', 'e' → 'f', 's' → 't').

String s is called a palindrome if it reads the same from left to right and from right to left. For example, strings "abba" and "zz" are palindromes and strings "abca" and "zy" are not.

Your goal is to check if it's possible to make string s a palindrome by applying the aforementioned changes to every position. Print "YES" if string s can be transformed to a palindrome and "NO" otherwise.

Each testcase contains several strings, for each of them you are required to solve the problem separately.

Input
The first line contains a single integer T (1≤T≤50) — the number of strings in a testcase.

Then 2T lines follow — lines (2i−1) and 2i of them describe the i-th string. The first line of the pair contains a single integer n (2≤n≤100, n is even) — the length of the corresponding string. The second line of the pair contains a string s, consisting of n lowercase Latin letters.

Output
Print T lines. The i-th line should contain the answer to the i-th string of the input. Print "YES" if it's possible to make the i-th string a palindrome by applying the aforementioned changes to every position. Print "NO" otherwise.

Example

Input
5
6
abccba
2
cf
4
adfa
8
abaazaba
2
ml

Output

YES
NO
YES
NO
NO

Note
The first string of the example can be changed to "bcbbcb", two leftmost letters and two rightmost letters got changed to the next letters, two middle letters got changed to the previous letters.

The second string can be changed to "be", "bg", "de", "dg", but none of these resulting strings are palindromes.

The third string can be changed to "beeb" which is a palindrome.

The fifth string can be changed to "lk", "lm", "nk", "nm", but none of these resulting strings are palindromes. Also note that no letter can remain the same, so you can't obtain strings "ll" or "mm".
*/ 

#include <iostream>
#include <string>
using namespace std;

void solve(){
    int n;
    cin>>n;

    string str;
    cin>>str;

    // Check if the string length is even
    if(n % 2 != 0){
        // If the length is odd, it's not possible to transform the string into a palindrome
        cout<<"NO"<<endl;
        return;
    }

    // Check if the string is empty
    if(str.empty()){
        // If the string is empty, it's not possible to transform it into a palindrome
        cout<<"NO"<<endl;
        return;
    }
    
    int i = 0; // left pointer
    int j = n-1; // right pointer

    while(i < j){
        if(str[i] != str[j]){
            // Calculate the absolute difference between the ASCII values of the characters
            int diff = abs(str[i] - str[j]);
            if(diff != 2){
                // If the difference is not 2, it's not possible to transform the string into a palindrome
                cout<<"NO"<<endl;
                return;
            }
        }
        i++;
        j--;
    }
    cout<<"YES"<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }
    
    return 0;
}