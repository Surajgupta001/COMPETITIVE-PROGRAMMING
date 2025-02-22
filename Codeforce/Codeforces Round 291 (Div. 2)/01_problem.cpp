/*
A. Chewbaсca and Number
========================
Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t.

Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

Input
The first line contains a single integer x (1 ≤ x ≤ 1018) — the number that Luke Skywalker gave to Chewbacca.

Output
Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

Examples
Input
27
Output
22

Input
4545
Output
4444

*/ 

/*
====== Approch - To solve this problem =====

1. Convert the number to a string.
1. Iterate through the digit from left -> right.
3. for each digit, check whether to invert it or not
4. Combine the transformed digit into a single
5. Convert the string back to a integer.
*/ 

#include <iostream>
#include <string>
using namespace std;

string transformNumber(string str) {
    int len = str.length();

    // Handle the leftmost digit separately
    if(str[0] != '9' && str[0] >= '5') {
        str[0] = '9' - str[0] + '0';
    }

    // Invert the remaining digits
    for(int i = 1; i < len; i++){
        if(str[i] >= '5') {
            str[i] = '9' - str[i] + '0';
        }
    }

    return str;
}

int main(){
    string str;
    cin >> str;
    cout << transformNumber(str) << endl;
    return 0;
}