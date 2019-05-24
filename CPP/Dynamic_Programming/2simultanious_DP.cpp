/* Give n and m, n denotes that Computer exactly can do n number of cycles and m is maximum number of idle cycles. 
Computer can do only two type odf cycles lets asay A and B, computer can't do two consecutives A's or B's.
Find the total number of different computation sequences*/


#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	int n, m;
	n =3; m = 50;

	vector< vector<int> > dp1(n+1);
	vector <vector<int> > dp2(n+1);
	for(int i = 0; i <= n; i ++) {
		dp1[i].resize(m + 1);
		dp2[i].resize(m + 1);
	}

	dp1[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		dp1[i][0] = 2;
	}

	for(int i = 1; i <= m; i++) {
		dp1[0][i] =  1;
	}

	dp2[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		dp2[i][0] = 1;
	}

	for(int i = 1; i <= m; i++) {
		dp2[0][i] =  1;
	}

	for(int i = 1; i <=n; i++) {
		for(int j = 1; j <=m; j++) {
			dp2[i][j] = (dp2[i - 1][j]  + dp1[i - 1][j - 1] ) ;
			dp1[i][j] = (dp1[i - 1][j - 1]  + (2 * dp2[i - 1][j])) ;
		}
	}

	cout << dp1[n][m];

	return 0;
}
