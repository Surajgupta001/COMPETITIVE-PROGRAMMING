/*

You are given all numbers between 1,2, .... n except one. Your task is to find the missing number.

Input
The first input line contains an integer n.
The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).

Output
Print the missing number.

Constraints
1 ≤ n ≤ 2⋅10^5

Example

Input:
5
2 3 1 5

Output:
4
*/ 

#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <numeric> // For std::accumulate
using namespace std;

int main(){
    long long n; // Use long long to handle larger integers
    cin >> n;
    vector<long long> sequence; // Use long long for sequence elements
    sequence.reserve(1000000); // Preallocate memory for the sequence

    // Read the input numbers into the vector
    for (long long i = 0; i < n - 1; i++) {
        long long x;
        cin >> x;
        sequence.push_back(x);
    }

    // Calculate the expected sum of numbers from 1 to n
    long long expectedSum = (n * (n + 1)) / 2;

    // Calculate the actual sum of the input numbers
    long long actualSum = accumulate(sequence.begin(), sequence.end(), 0LL);

    // The missing number is the difference between expected and actual sums
    cout << expectedSum - actualSum << endl;

    return 0;
}