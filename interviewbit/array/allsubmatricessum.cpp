/*Given a 2D Matrix of dimensions N*N, 
    we need to return sum of all possible submatrices. Example
    [ [1,1],
      [1,1] ]
    Example Output

        16

    Explanation

    Number of submatrices with 1 elements = 4, so sum of all such submatrices = 4*1 = 4
    Number of submatrices with 2 elements = 4, so sum of all such submatrices = 4*2 = 8
    Number of submatrices with 3 elements = 0
    Number of submatrices with 4 elements = 1, so sum of such submatrix = 4

    Total Sum = 4+8+4 = 16
                                */ 


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long find_sum(vector <vector <int>> &v, int n);

int main() {

    int test;
    // cin >> test;
    test = 1;

    while(test--) {
        int n;
        cin >> n;
        vector <vector <int>> v(n);

        for (int i = 0; i < n; i++) {
            v[i].resize(n + 1);
        }

        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> v[i][j]; 
            }
        }

    // Now solution

    cout << find_sum(v, n) << endl; 
}

return 0;
}

long long find_sum(vector< vector <int>> &v, int n) {
    if (n == 0) {
        cout << "size of the matrix can't be zero ";
        return 0;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += (long long) v[i][j] * (i + 1) * (j + 1) * (n - j) * (n - i);
        }
    }
    return ans;
}