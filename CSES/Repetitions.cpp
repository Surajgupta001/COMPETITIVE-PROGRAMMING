/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

Input
The only input line contains a string of n characters.

Output
Print one integer: the length of the longest repetition.
Constraints

1 ≤ n ≤ 2·10^6

Example
Input:
ATTCGGGA

Output:
3
*/ 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str;
    cin>>str;
    
    int max_count = 1;
    int current_count = 1;

    // Use size_type to match the return type of str.length()
    for(size_t i = 0; i < str.length() - 1; i++){
        if(str[i] == str[i+1]) current_count++; // Same character found
        else{
            max_count = max(max_count, current_count);
            current_count = 1; // Reset count for the next character
        }
    }
    max_count = max(max_count, current_count); // Check the last sequence
    
    cout<<max_count<<endl; // Output the maximum count
    
    return 0;
}