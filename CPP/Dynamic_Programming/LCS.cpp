#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
 {  
    int Test; 
	cin >> Test;
    while(Test--) {
        int n, m;
        cin >> n >> m;
        vector<char> v1(n), v2(m);
        for ( int i = 0; i < n; i++) {
            cin >> v1[i];
        }
        
        for ( int i = 0; i < m; i++) {
            cin >> v2[i];
        }
        
        vector< vector< int>> dp(n+1);
        for (int i = 0; i <= n; i++) {
            dp[i].resize(m+1);
        }
        
        for ( int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        for ( int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ( v1[i-1] == v2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; 
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);   
                }
            }
        }
        
        int ans = -1;
        for ( int i = 0; i <= m; i++) {
            ans = max(ans, dp[n][i]);
            cout << dp[n][i] << " ";
        }
        
        cout << endl << ans << endl;
	}
	return 0;
}