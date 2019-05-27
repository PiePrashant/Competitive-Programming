/* 
Wave Array

Given an array of integers, sort the array into a wave like array and return it, In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
 */

#include <bits/stdc++.h>
#include <iostream>

using namespace std;


vector<int> funct(vector<int> &v);

int main() {
    int test = 1;
    while(test--) {
        int n;
        cin >> n;
        vector <int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> asd(n);
        asd = funct(v);
        for ( int i = 0; i < n; i++) {
            cout << asd[i] << " ";
        }
    }
return 0;
}








vector<int> funct(vector<int> &A) {
    sort(A.begin(), A.end());
    int  n = A.size();
    if (n % 2 == 0) {
        for( int i = 0; i < n ; i = i + 2) {
            //swap i and i+1
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
        return A;
    }
    else {
        for( int i = 0; i < n - 1 ; i = i + 2) {
            //swap i and i+1
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
        return A;
    }
}