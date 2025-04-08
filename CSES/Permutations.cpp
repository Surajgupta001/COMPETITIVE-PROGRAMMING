/*
A permutation of integers 1,2,....,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.

Input
The only input line contains an integer n.

Output
Print a beautiful permutation of integers 1,2,\ldots,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".
Constraints

1 ≤ n ≤ 10^6

Example 1

Input:
5

Output:
4 2 5 3 1

Example 2

Input:
3

Output:
NO SOLUTION
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;

    if(n == 1) cout<<"1"<<endl;
    else if(n == 2 || n == 3) cout<<"NO SOLUTION"<<endl;
    else{
        for(int i=2; i<=n; i+=2) cout<<i<<" "; // Print even numbers first
        for(int i=1; i<=n; i+=2) cout<<i<<" "; // Then print odd numbers
        cout<<endl;
    }

    return 0;
}