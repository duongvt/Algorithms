#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll t,n,i,j,sum;
	cin>>t;

	while(t--)
	{
		cin>>n;
		ll input[n];

		for(i=0;i<n;i++)
		{
			cin>>input[i];
		}

		cin>>sum;

		bool dp[n][sum+1];
		for(i=0;i<n;i++)
		{
			for(j=0;j<=sum;j++)
			{
				if(j==0) dp[i][j]=true;
				else if(i==0&&j!=0)
				{
					if(j==input[i]) dp[i][j]=true;
					else dp[i][j]=false;
				}
 				else if(input[i]>j) dp[i][j]=dp[i-1][j];
				else
				{
					if(dp[i-1][j]==true) dp[i][j]=true;
					else dp[i][j]=dp[i-1][j-input[i]];
				}
			}
		}
		cout<<dp[n-1][sum]<<endl;
	}
return 0;
}