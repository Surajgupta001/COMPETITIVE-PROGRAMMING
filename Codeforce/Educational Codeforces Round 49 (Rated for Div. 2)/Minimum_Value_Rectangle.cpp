/*
You have n sticks of the given lengths.

Your task is to choose exactly four of them in such a way that they can form a rectangle. No sticks can be cut to pieces, each side of the rectangle must be formed by a single stick. No stick can be chosen multiple times. It is guaranteed that it is always possible to choose such sticks.

Let S be the area of the rectangle and P be the perimeter of the rectangle.

The chosen rectangle should have the value P^2/S minimal possible. The value is taken without any rounding.

If there are multiple answers, print any of them.

Each testcase contains several lists of sticks, for each of them you are required to solve the problem separately.

Input
The first line contains a single integer T (T≥1) — the number of lists of sticks in the testcase.

Then 2T lines follow — lines (2i−1) and 2i of them describe the i-th list. The first line of the pair contains a single integer n (4≤n≤10^6) — the number of sticks in the i-th list. The second line of the pair contains n integers a1,a2,…,an (1≤aj≤10^4) — lengths of the sticks in the i-th list.

It is guaranteed that for each list there exists a way to choose four sticks so that they form a rectangle.

The total number of sticks in all T lists doesn't exceed 10^6 in each testcase.

Output
Print T lines. The i-th line should contain the answer to the i-th list of the input. That is the lengths of the four sticks you choose from the i-th list, so that they form a rectangle and the value P^2S of this rectangle is minimal possible. You can print these four lengths in arbitrary order.

If there are multiple answers, print any of them.

Example

Input
3
4
7 2 2 7
8
2 8 1 4 8 2 1 5
5
5 5 5 5 5

Output
2 7 7 2
2 2 1 1
5 5 5 5

Note
There is only one way to choose four sticks in the first list, they form a rectangle with sides 2 and 7, its area is 2⋅7=14, perimeter is 2(2+7)=18. 18^2/14≈23.143.

The second list contains subsets of four sticks that can form rectangles with sides (1,2), (2,8) and (1,8). Their values are 6^2/2=18, 20^2/16=25 and 18^2/8=40.5, respectively. The minimal one of them is the rectangle (1,2).

You can choose any four of the 5 given sticks from the third list, they will form a square with side 5, which is still a rectangle with sides (5,5)

*/ 

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

// Calculate the value of p^2/s
double calculateRation(int l1, int l2){
    return pow(2 * (l1 + l2), 2) / (1.0 * l1 * l2);
}

int main(){
    int t; // testcase
    cin>>t;

    while(t-- > 0){
        int n; // stick
        cin>>n;

        map<int,int>freq; // store the frequency of each stick length

        for(int i = 0; i < n; i++){
            int l; // length of stick
            cin>>l;
            freq[l]++;
        }

        // Store pairs of stick lengths that can perform a reactangle
        vector<pair<int,int>>makes_pairs;

        // find pairs of stick length that can form a rectangle
        for(auto pair : freq){
            if(pair.second > 1) makes_pairs.push_back(pair);
        }

        int len1 = -1;
        int len2 = -1;

        // check if there is a stack length that appears more than three times
        for(auto pair : makes_pairs){
            if(pair.second > 3){
                len1 = len2 = pair.first;
                break;
            }
        }

        // If no such stick length is found, find the pair that minimize p^2/s
        if(len1 == -1 and len2 == -1){
            double min_ratio = 1e9;
            for(int i=1; i<makes_pairs.size(); i++){
                double ratio = calculateRation(makes_pairs[i].first, makes_pairs[i-1].first);
                if(ratio < min_ratio){
                    min_ratio = ratio;
                    len1 = makes_pairs[i].first;
                    len2 = makes_pairs[i-1].first;
                }
            }
        }
        cout<<len1<<" "<<len1<<" "<<len2<<" "<<len2<<" "<<endl;
    }
    return 0;
}