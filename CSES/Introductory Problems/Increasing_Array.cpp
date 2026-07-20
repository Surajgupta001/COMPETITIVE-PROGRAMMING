/*
You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?

Input
The first input line contains an integer n: the size of the array.
Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.

Output
Print the minimum number of moves.

Constraints
1 ≤ n ≤ 2·10^5
1 ≤ x_i ≤ 10^9

Example

Input:
5
3 2 5 1 7

Output:
5
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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    long long moves = 0;
    int max = v[0];
    
    for(int i=0; i<n; i++){
        if(v[i] < max) moves += max - v[i];
        else max = v[i]; // Update max to the current element if it's larger
    }
    cout<<moves<<endl;
    
    return 0;
}