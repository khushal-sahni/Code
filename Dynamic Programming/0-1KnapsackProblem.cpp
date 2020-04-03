#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int w;
        cin>>w;
        int val[n];
        int wt[n];
        for(int i=0;i<n;i++)
        cin>>val[i];

        for(int i=0;i<n;i++)
        cin>>wt[i];


        for(int i=0;i<=n;i++)
        {

            for(int j=0;j<=w;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else if(wt[i-1]<=j)
                {
                    dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[n][w]<<endl;
       // memset(dp,0,sizeof(dp));

    }
	return 0;
}
