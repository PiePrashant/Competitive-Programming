/*

N/3 Repeat Number

You're given a read only array of n integers.
Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 
 */


#include <bits/stdc++.h>

using namespace std;

int find_answer(const vector<int> &A);
int main() {
    int test = 1;
    while(test--) {
        int n; cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        cout << find_answer(A) << endl;
    }
    return 0;
}

int find_answer(const vector<int> &A) {
    int n = A.size();
    if (n == 1) {
        return A[0];
    }
    
    int m1 = 0, m2 = 1, c1 = 0, c2 = 0;
    
    for (int i = 0; i < n; i++) {
        if (c1 == 0 && m2 != A[i]) {
            m1 = A[i];
            c1++;
        }
        else if (c2 == 0 && m1 != A[i]) {
            m2 = A[i];
            c2++;
        }
        else {
            if (A[i] == m1) {
                c1++;
            }
            else if (A[i] == m2) {
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }
        cout << m1 << " " << m2 << " " << A[i] << " "<< c1 << " " << c2 <<endl;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (m1 == A[i]) count++;
    }
    if (count > n/3) return m1;
    
    count = 0;
    for (int i = 0; i < n; i++) {
        if (m2 == A[i]) count++;
    }
    if (count > n/3) {
        return m2;
    }
    
    return -1;
    
}
