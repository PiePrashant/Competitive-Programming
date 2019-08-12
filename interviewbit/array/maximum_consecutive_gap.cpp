/*
Maximum Consecutive Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 

Return 0 if the array contains less than 2 elements.

    You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    You may also assume that the difference will not overflow.

×
-->  */



#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int return_answer(const vector<int> A) {
    int n = A.size();
    int maxi = A[0], mini = A[0];

    for (int i = 0; i < n; i++) {
        if (A[i] > maxi) {
            maxi = A[i];
        }

        if (A[i] < mini) {
            mini = A[i];
        }
    }
    // corner cases
    if (n < 2) return -1;
    if ( n == 2) return maxi - mini;
    if (maxi == mini) return 0;
    int gap = ceil((double)(maxi - mini) / ( n - 1));
    
    // make buckets of size n
    vector<vector<int>> v(n);
    
    //put the elements of vector A in buckets
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp = (A[i] - mini) / gap;
        v[temp].push_back(A[i]);
    }

    // store the maximum and minimum values of each bucket

    vector< pair<int,int>> p;

    for (int i = 0; i < n; i++) {
        if (v[i].empty()) {
            continue;
        }
        int maxi_n = v[i][0];
        int mini_n = v[i][0];

        for(int j = 0; j < v[i].size(); j++) {
            if (v[i][j] > maxi_n) {
                maxi_n = v[i][j];
            }

            if (v[i][j] < mini_n) {
                mini_n = v[i][j];
            }
            
        }
        //cout << "mini_n" << mini_n << " " << "maxi_n" << maxi_n<<endl; 
        p.push_back(make_pair(mini_n, maxi_n));
    }
    ///==================
    // for  (int i = 0; i < v.size(); i++) {
    //     //cout << p[i].first << " " << p[i].second << endl;
    //     for (int j= 0; j < v[i].size(); j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // now final step
    int ans = gap;
    for (int i = 1; i < p.size(); i++) {
        temp = p[i].first - p[i-1].second;
        //cout << "temp" << temp << endl;
        if (ans < temp) {
            ans = temp;
        }
    }

    // for (int i = 0; i < p.size(); i++) {
    //     cout << p[i].first << " " << p[i].second << endl;
    // }
     return ans;


}
int main() {

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        cout << return_answer(A) << endl;
    }

    return 0;
}