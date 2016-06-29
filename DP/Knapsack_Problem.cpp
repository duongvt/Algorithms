#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
	ll t,n,i,j;
	cin>>t;

	while(t--)
	{
		cin>>n;
		ll weight[n],cost[n];
		for(i=0;i<n;i++) cin>>weight[i];
		for(i=0;i<n;i++) cin>>cost[i];
		ll totalWeight;
	 	cin>>totalWeight;

	 	ll dp[n][totalWeight+1];

	 	for(i=0;i<n;i++)
	 	{
	 		for(j=0;j<=totalWeight;j++)
	 		{
	 			if(j==0) dp[i][j]=0;
	 			else if(i==0)
	 			{
	 				if(weight[i]>j) dp[i][j]=0;
	 				else dp[i][j]=weight[i];
	 			}
	 			else if(weight[i]>j) dp[i][j]=dp[i-1][j];
	 			else dp[i][j]=max(dp[i-1][j-weight[i]]+cost[i],dp[i-1][j]);
	 		}
	 	}

	 	ll result=-99999999999;

	 	for(i=0;i<n;i++)
	 	{
	 		for(j=0;j<=totalWeight;j++)
	 		{
	 			// cout<<dp[i][j]<<" ";
	 			if(result<dp[i][j]) result=dp[i][j];
	 		}
	 		// cout<<endl;
	 	}

	 	cout<<result<<endl;
	}
}