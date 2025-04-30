/*
A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

1     2     9     10     25
4     3     8     11     24
5     6     7     12     23
16    15    14    13     22
17    18    19    20     21

Your task is to find out the number in row y and column x.

Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, each containing integers y and x.

Output
For each test, print the number in row y and column x.
Constraints

1 ≤ t ≤ 10^4
1 ≤ y, x ≤ 10^9

Example

Input:
3
2 3
1 1
4 2

Output:
8
1
15
*/

#include <iostream>
using namespace std;

int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--){
        long long x, y;
        cin >> y >> x;

        long long maxIndices = max(x, y);
        long long square = (maxIndices - 1) * (maxIndices - 1);
        
        if (maxIndices % 2 == 0){
            if(x > y){
                cout << square + y << endl;
            }
            else{
                cout << (maxIndices * maxIndices) - x + 1 << endl;
            }
        }
        else{
            if(x > y){
                cout << (maxIndices * maxIndices) - y + 1 << endl;
            }
            else{
                cout << square + x << endl;
            }
        }
    }
    
    return 0;
}