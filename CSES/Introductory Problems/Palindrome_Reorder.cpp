/*
Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

Input
The only input line has a string of length n consisting of characters A–Z.

Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1<=n<=10^6

Example
Input:
AAAACACBA

Output:
AACABACAA
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
    cin >> str;

    vector<int> freq(26, 0);
    for(int i=0; i<str.size(); i++){
        freq[str[i] - 'A']++; // Count the frequency of each character
    }

    int oddCount = 0;
    int oddCharIndex = -1;

    for(int i=0; i<26; i++){
        if(freq[i] % 2 != 0){ // Check for odd frequency characters
            oddCount++;
            oddCharIndex = i; // Store the index of the character with odd frequency
        }
    }

    if(oddCount > 1){
        cout << "NO SOLUTION" << endl; // More than one character with odd frequency means no palindrome can be formed
        return 0;
    }

    string half = "";
    for(int i=0; i<26; i++){
        half += string(freq[i] / 2, 'A' + i); // Create the first half of the palindrome using half of the even frequency characters
    }
    string palindrome = half; // Start with the first half of the palindrome
    if(oddCount == 1){ // If there is one character with odd frequency, add it in the middle
        palindrome += string(freq[oddCharIndex] - 2 * (freq[oddCharIndex] / 2), 'A' + oddCharIndex); // Add the odd character in the middle of the palindrome
    }
    reverse(half.begin(), half.end()); // Reverse the first half to create the second half of the palindrome
    palindrome += half; // Add the reversed first half to complete the palindrome
    cout << palindrome << endl;
    return 0;
}