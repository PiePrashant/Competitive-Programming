
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


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int k,n;
	    cin>>k>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	   
	    sort(a,a+n);
	   
	    int ans=a[n-1]-a[0];
	    int small=a[0]+k;
	    int big=a[n-1]-k;
	    
	    if(small>big)
	    swap(small,big);
	    
	    
	    
	    for(int i=1;i<(n-1);i++)
	    {
	        int sub= a[i]-k;
	        int add=a[i]+k;
	        
	        if(sub>=small||add<=big)
	        continue;
	        
	        if(big-sub<=add-small)
	         small=sub;
	         else
	         big=add;
	     }
	     cout<<min(ans,(big-small))<<endl;
	}
	return 0;
}
/* A : 4 6 7 10 12 16 22 29 40 41 46 57 67 72 75 75 76 81 85 86 87 89 92 95 97
B : 88
Your function returned the following :
174
The expected returned value :
93 */