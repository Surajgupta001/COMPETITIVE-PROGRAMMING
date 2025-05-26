/*
You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.

Your task is to efficiently find out if you can empty both the piles.

Input
The first input line has an integer t: the number of tests.
After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.

Output
For each test, print "YES" if you can empty the piles and "NO" otherwise.
Constraints

1<=t<=10^5
0<=a, b<=10^9

Example
Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES
*/ 

#include <iostream>
using namespace std;
    
int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long t;
    cin >> t;

    while(t--){
        long long a, b;
        cin >> a >> b;

        // Check if both piles can be emptied
        if ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b)) {
            cout << "YES" << endl; // If the total is divisible by 3 and the smaller pile can support the larger one
        }
        else {
            cout << "NO" << endl; // Otherwise, it's not possible to empty both piles
        }

    }
        
    return 0;
}