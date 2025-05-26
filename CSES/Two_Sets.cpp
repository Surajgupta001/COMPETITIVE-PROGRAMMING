/*
Your task is to divide the numbers 1,2,....,n into two sets of equal sum.

Input
The only input line contains an integer n.

Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.

Constraints
1<=n<=10^6

Example 1
Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6
Example 2
Input:
6

Output:
NO
*/

#include <iostream>
using namespace std;
#include <vector>

int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;
    long long totalSum = n * (n + 1) / 2;

    if (totalSum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES"<<endl;
    vector<long long> set1, set2;
    long long halfSum = totalSum / 2;

    for (long long i = n; i >= 1; --i) {
        if (halfSum >= i) { // If the current number can fit into the first set
            set1.push_back(i); // Adding the current number to set1
            halfSum -= i; // Decrease the halfSum by the current number
        }
        else {
            set2.push_back(i); // If the current number cannot fit into set1, add it to set2
        }
    }

    cout << set1.size() << endl;
    for (auto x : set1) cout << x << " ";
    cout << endl << set2.size() << endl;
    for (auto x : set2) cout << x << " ";
    cout << endl;

    return 0;
}