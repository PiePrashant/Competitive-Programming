
/* Minimise the maximum difference between the heights

Given an array of integers A representing heights of towers and a positive integer B. 
It is allowed to either increase or decrease the height of every tower by B (only once).

Find and return the minimum possible difference between the heights of the longest and the shortest tower after modifications.

Note: It is mandatory to either increase or decrease the height of every tower.


Constraints

2 <= length of the array <= 100000
-10^9 <= A[i] <= 10^9 
1 <= B <= 10^9


For Example

Input 1:
    A = [1, 2, 3, 4, 5]
    B = 2
Output 1:
    3

Input 2:
    A = [5, 17, 100, 11]
    B = 10
Output 2:
    75

*/


#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int minm_diff(vector <int> &v, int c);


int main() {
    int test = 1;
    while(test--) {
        int n;
        cin >> n;
        vector <int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int b;
        cin >> b;

        cout << minm_diff(v, b) << endl;
    }
    return 0;
} 

int minm_diff(vector <int> &A, int k) {
    
    sort(A.begin(), A.end());
    int n = A.size();
    int gap = A[n-1] - A[0] ;
    
    if (gap <= k) {
        return gap;
    }
    
    int global_small = min(A[0] + k, A[n-1] - k);
    int global_big =max(A[0] + k, A[n-1] - k);
    
    for ( int i = 1; i < n - 1; i++) {

        int local_small = A[i] - k;
        int local_big = A[i] + k;

        if (local_small > global_small) {
            cout << '-' << " " << global_small<<" " << global_big << " " << endl;
            continue;
        }

        if (local_big < global_big) {
            cout << '+' << " " << global_small<<" " << global_big << " " << endl;
            continue;
        }

        if (abs(local_big - global_small ) < abs(global_big - local_small ) ){
            global_big = local_big;
            cout << '+' << " " << global_small<<" " << global_big << " " << endl;
        }

        else {
            global_small = local_small;
             cout << '-' << " " << global_small<<" " << global_big << " " << endl;
        }
        
    }

    return global_big - global_small;
        
}


/* A : 4 6 7 10 12 16 22 29 40 41 46 57 67 72 75 75 76 81 85 86 87 89 92 95 97
B : 88
Your function returned the following :
174
The expected returned value :
93 */