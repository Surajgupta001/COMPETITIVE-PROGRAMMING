/*
C. Blackslex and Number Theory

Blackslex worked too hard and started dreaming about numbers. Solve the following task from his dreams.

You are given an array a1,a2,…,an.

In one operation you choose an index i (1≤i≤n) and an integer x which is at least k and set

a[i]:=a[i] mod x,

where umodv denotes the remainder of dividing u by v.

Your goal is to make all elements of the array identical. Among all positive integers k, determine the maximum k for which there exists a finite sequence of the above operations that makes all array elements equal.

Input
The first line contains a single integer t (1≤t≤10^4) — the number of test cases.

The first line of each test case contains a single integer n (2≤n≤2⋅10^5).

The second line contains n integers a1,a2,…,an (1≤ai≤10^9, all values of a are distinct).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case, print a single integer — the maximum positive integer k such that it is possible to make all elements of the array identical using any number of operations with moduli x restricted to k≤x.

Example

Input
3
3
5 7 9
2
2 3
7
11 74 5 22 52 97 82

Output
5
2
6
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        long long minVal = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < minVal) minVal = a[i];
        }

        long long minDiff = LLONG_MAX;
        for (long long x : a) {
            if (x > minVal) {
                minDiff = min(minDiff, x - minVal);
            }
        }

        long long k = max(minVal, minDiff);
        cout << k << "\n";
    }

    return 0;
}