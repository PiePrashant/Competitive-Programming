/* 

Maximum Unsorted Subarray

You are given an array (zero indexed) of N non-negative integers, 
A0, A1 ,..., AN-1. Find the minimum sub array Al, Al+1 ,..., Ar 
so if we sort(in ascending order) that sub array, t
hen the whole array should get sorted. If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
 */




# include <iostream>
# include <bits/stdc++.h>

using namespace std;

void generate_matrix(vector <vector <int>> &v, int n);

int main() {

    int test;
    // cin >> test;
    test = 1;
    while (test--) {
        int n; 
        cin >> n;
        vector<int> v = {1, 3, 2, 4, 5};
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        
        // finding the starting point where it is unsorted
        int flag = 1;
        int left = 0;
        int right = 0;
        for (int k = 0; k < n - 1; k++) {
            if (v[k] > v[k + 1]) {
                flag = 0;
                left = k;
                break;
            }
            
        }
        // if array i ssorted then return -1
        //cout << endl <<"flag " << flag << endl << "left " << left;
        if (flag == 1) {
            cout << -1;
            return 0;
        }

        // finding the end point of unsorted array

        for (int j = n - 1; j > 0; j--) {
            if(v[j] < v[j - 1]) {
            right = j;
            break;    
            }
        }
        // cout << endl;
         cout << "starting break point " << left << endl;
         cout << "end break point " << right << endl;

        // Now find the maximum in array unsorted array and leftmost element of left sorted array

        int maxim = v[0];

        for (int i = left; i < right; i++) {
            maxim = max(maxim, v[i]);
        }

        // Now find the minimum in array unsorted array and leftmost element of right sorted array

        int minm = v[n-1];

        for (int i = left + 1; i <= right; i++) {
            minm = min(minm, v[i]);
        }

        // find the place for maxm value in right sorted array
        int ans_right = n-1;
        for(int i = right; i < n; i++) {
            if(maxim <= v[i]) {
                ans_right = i - 1;
                break;
            }
        }

        // find the place for minm value in left sorted array
        int ans_left = 0;
        for(int i = left; i >= 0; i--) {
            if(minm >= v[i]) {
                ans_left = i + 1;
                break;
            }
        }
        cout << "minimum " << minm << endl;
        cout << "maximum " << maxim << endl;
        cout << "left pointer " << ans_left << endl;
        cout << "right pointer " << ans_right << endl;
        cout << "required subarray is ";
        for (int i = ans_left; i <= ans_right ; i++ ) {
            cout<< i << " ";
        }

        cout << endl;


    }

    return 0;
}