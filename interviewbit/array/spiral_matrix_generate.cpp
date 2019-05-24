/* 
Spiral Order Matrix II

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]
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
        vector< vector <int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i].resize(n);
        }

        generate_matrix(v, n);
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;

        } 
    }

    return 0;
}


void generate_matrix(vector< vector <int>> &v, int n) {
    int count = 1;
    int i = 0, j = 0;

    while (count <= n * n) {

        while (j < n && v[i][j] == 0) {
           v[i][j] = count;
           j++;
           count++;
        }
        j--;//n
        i++;//0
        cout << endl << i << " "<< j << " " << count << endl;
        while(i < n && v[i][j] == 0) {
            v[i][j] = count;
            i++;
            count++;
        }
        i--;//n
        j--;//n-1
         // cout << endl << i << " "<< j << " " << count << endl;
        while( j >= 0 && v[i][j] == 0) {
            v[i][j] = count;
            j--;
            count++;
        }
        j++;//0
        i--;
        while( i >= 0 && v[i][j] == 0) {
            v[i][j] = count;
            i--;
            count++;
        }
        i++;
        j++;
   }

    return;
}


