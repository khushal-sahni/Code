#include <iostream>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    int m,n; cin>>m; int a[m];
	    for(int i=0;i<m;i++) cin>>a[i];
	    cin>>n;
	    int dp[m+1][n+1];
	    for(int i=0;i<=m;i++){
	        for(int j=0;j<=n;j++){
	            if(i==0 && j==0) dp[i][j]=1;
	            else if(j==0) dp[i][j]=1;
	            else if(i==0) dp[i][j]=0;
	            else if(j>=a[i-1]) dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]];
	            else dp[i][j]=dp[i-1][j];
	        }
	    }
	    cout<<dp[m][n]<<endl;
	}
	return 0;
}
 ///////////////////////////////////////////////////??????Explanatory code

// C++ program for coin change problem.
#include<bits/stdc++.h>

using namespace std;

int count( int S[], int m, int n )
{
	int i, j, x, y;

	// We need n+1 rows as the table
	// is constructed in bottom up
	// manner using the base case 0
	// value case (n = 0)
	int table[n + 1][m];

	// Fill the enteries for 0
	// value case (n = 0)
	for (i = 0; i < m; i++)
		table[0][i] = 1;

	// Fill rest of the table entries
	// in bottom up manner
	for (i = 1; i < n + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			// Count of solutions including S[j]
			x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;

			// Count of solutions excluding S[j]
			y = (j >= 1) ? table[i][j - 1] : 0;

			// total count
			table[i][j] = x + y;
		}
	}
	return table[n][m - 1];
}

// Driver Code
int main()
{
	int arr[] = {1, 2, 3};
	int m = sizeof(arr)/sizeof(arr[0]);
	int n = 4;
	cout << count(arr, m, n);
	return 0;
}

// This code is contributed
// by Akanksha Rai(Abby_akku)
