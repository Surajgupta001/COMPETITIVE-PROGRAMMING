/*
B. Blackslex and Showering

After his IMO medalist friend showered for two hours so that "he doesn't have to shower this again this week," Blackslex will be late for class!

In order to get to class, Blackslex must take the crowded elevator to many floors in a certain order. Because he is a hacker, he can skip visiting up to one floor without the other people knowing. His time taken is the sum of the absolute differences between consecutive floor numbers. Find the minimum time taken, given that he can skip up to one floor.

More formally, given an array a=[a1,a2,…,an] of n integers, you can choose up to one index k∈{1,2,…,n} to erase such that the sum

is minimized, where b=[a1,…,ak−1,ak+1,…,an] is the array after erasing element ak. Report the minimum sum.

Input
The first line contains one integer t (1≤t≤10^4) — the number of test cases.

The first line of each test case contains one integer n (3≤n≤2⋅10^5) — the size of the array.

The second line contains n integers a1,a2,…,an (1≤ai≤100).

It is guaranteed that the sum of n does not exceed 2⋅10^5 over all test cases.
Output
For each test case, output a single real number — the minimum time taken.

Example

Input
3
5
4 15 1 7 9
3
2 4 8
6
11 13 17 19 23 29

Output
11
2
12

Note
For the first test case, one optimal index to remove from [4,15,1,7,9] is k=2. The array becomes [4,1,7,9] and the time taken is 11. For the second test case, the optimal index to remove is k=3.
*/ 

#include <iostream>
#include <vector>
using namespace std;
    
int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        // Step 1: Original total time
        long long total_time = 0;
        for(int i=1; i<n; i++){
            total_time += llabs(a[i] - a[i-1]);
        }

        // Step 2: Find Maximum saving
        long long max_saving = 0;

        // Middle elements
        for(int i=1; i<n-1; i++){
            long long saving = llabs(a[i] - a[i-1]) + llabs(a[i+1] - a[i]) - llabs(a[i+1] - a[i-1]);

            max_saving = max(max_saving, saving);
        }

        // Edge elements
        max_saving = max(max_saving, llabs(a[1] - a[0]));
        max_saving = max(max_saving, llabs(a[n-1] - a[n-2]));

        // Edge elements
        cout<<total_time - max_saving<<endl;
    }
        
    return 0;
}