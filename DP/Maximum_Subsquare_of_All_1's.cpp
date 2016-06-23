#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
	ll t,m,n,i,j;
	cin>>t;

	while(t--)
	{
		cin>>m>>n;
		ll input[m][n];

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>input[i][j];
			}
		}

		ll dp[m+1][n+1];

		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0||j==0) dp[i][j]=0;
				else if(input[i-1][j-1]==1) dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
				else dp[i][j]=0;
			}
		}

		ll max=-999999999;

		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(dp[i][j]>max) max=dp[i][j];
			}
		}
		cout<<max<<endl;
	}
return 0;	
}