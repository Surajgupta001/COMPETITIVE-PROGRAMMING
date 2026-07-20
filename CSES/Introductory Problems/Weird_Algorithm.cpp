/*
Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:

3 → 10 → 5 → 16 → 8 → 4 → 2 → 1. 
The sequence for n=6 is 6 → 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1. 
The sequence for n=7 is 7 → 22 → 11 → 34 → 17 → 52 → 26 → 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1.

The algorithm is called the Collatz conjecture, and it is not known whether it always terminates. The conjecture states that no matter what value of n you start with, the sequence will always reach 1 eventually. The conjecture has been checked for all starting values of n up to 2^60, but it remains unproven for larger values.
Your task is to simulate the execution of the algorithm for a given value of n.

Input
The only input line contains an integer n.

Output
Print a line that contains all values of n during the algorithm.

Constraints
1≤ n ≤ 10^6

Example
Input:
3

Output:
3 10 5 16 8 4 2 1
*/ 

#include <iostream>
#include <vector>
using namespace std;

/*
vector<long long> weirdAlgorithm(int n){
    vector<long long> sequence;
    sequence.reserve(1000000); // Preallocate memory for the sequence
    sequence.push_back(n); // Add the first element (n)
    while(n != 1){
        if(n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }
    sequence.push_back(1); // Add the last element (1)
    return sequence;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout<< "Enter a positive integer: ";
    cin >> n;
    vector<long long> ans = weirdAlgorithm(n);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i];
        if(i != ans.size() - 1) cout << " ";
    }
    cout << endl;
        
    return 0;
}
*/ 

int main() {
    long long n; // Use long long to handle larger integers
    cin >> n;
    vector<long long> sequence; // Use long long for sequence elements
    sequence.reserve(1000000); // Preallocate memory for the sequence
    sequence.push_back(n);
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        sequence.push_back(n);
    }
    // Print the sequence
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i];
        if (i != sequence.size() - 1) {
            cout << " ";
        }
    }
    return 0;
}