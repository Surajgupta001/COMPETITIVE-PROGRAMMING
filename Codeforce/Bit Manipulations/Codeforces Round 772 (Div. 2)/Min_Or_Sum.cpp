/*
You are given an array a of size n.

You can perform the following operation on the array:

Choose two different integers i,j (1≤i<j≤n), replace ai with x and aj with y. In order not to break the array, ai|aj=x|y must be held, where | denotes the bitwise OR operation. Notice that x and y are non-negative integers.
Please output the minimum sum of the array you can get after using the operation above any number of times.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). Description of the test cases follows.

The first line of each test case contains an integer n (2≤n≤100) — the size of array a.

The second line of each test case contains n integers a1,a2,…,an (0≤ai<230).

Output
For each test case, print one number in a line — the minimum possible sum of the array.

Example
Input
4
3
1 3 2
5
1 2 4 8 16
2
6 6
3
3 5 6
Output
3
31
6
7

Note
In the first example, you can perform the following operations to obtain the array [1,0,2]:

1. choose i=1,j=2, change a1=1 and a2=2, it's valid since 1|3=1|2. The array becomes [1,2,2].

2. choose i=2,j=3, change a2=0 and a3=2, it's valid since 2|2=0|2. The array becomes [1,0,2].

We can prove that the minimum sum is 1+0+2=3

In the second example, We don't need any operations.
*/ 

#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    
    int x = 0;
    for(int i=0; i<n; i++){
        int y;
        cin >> y;

        x |= y;
    }
    cout << x << endl;
}

int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
        
    return 0;
}