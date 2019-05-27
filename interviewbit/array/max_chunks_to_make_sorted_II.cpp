/*

Max Chunks To Make Sorted II

Given an array of integers (not necessarily distinct) A, if we split the array into some number of "chunks" (partitions), and individually sort each chunk. After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?


Input Format

The only argument given is the integer array A.

Output Format

Return the maximum number of chunks that we could have made.

Constraints

1 <= N <= 100000
-10^9 <= A[i] <= 10^9

For Example

Input 1:
    A = [3, 2, 3, 4, 0]
Output 1:
    1

Input 2:
    A = [2, 0, 1, 2]
Output 2:
    2
*/



#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int funct(vector<int> &v);

int main() {
    int test = 1;
    while(test--) {
        int n;
        cin >> n;
        vector <int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        cout << funct(v) << endl;
    }
return 0;
}

int funct(vector<int> &A) {
    int n;
    n = A.size();
    vector<pair<int,int>> v(n);
    
    for (int i = 0; i < A.size(); i++) {
        v[i] = make_pair(A[i], i);
    }
    
    sort(v.begin(), v.end());
    
    int ans = 0;
    int max_i = 0;
    for (int i = 0; i < n; i++) {
        max_i = max(v[i].second, max_i);
        if(max_i == i) {
            ans++;
        }
        
    }
    return ans;
}