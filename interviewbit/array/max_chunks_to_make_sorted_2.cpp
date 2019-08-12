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
    vector<int> left_max(n); 
    vector<int> right_min(n);
    int l_max = A[0], r_min = A[n - 1]; 

    for (int i = 0; i  < n; i++) {
        if (l_max < A[i]) {
            l_max = A[i];
        }
        left_max[i] = l_max;
    } 

    for (int i = n - 1; i >= 0; i--) {
        if (A[i] < r_min) {
            r_min = A[i];
        }
        right_min[i] = r_min;
    }

    int chunks = 0;
    for (int i = 0; i < n - 1; i++) {
        if (left_max[i] <= right_min[i + 1]) {
            chunks++;
        }
    }
    // if (A[n-1] == left_max[n-1]) {
    //     chunks++;
    // }

    return chunks + 1;
}