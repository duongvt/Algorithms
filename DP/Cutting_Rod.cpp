#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
	ll t,n,length,i,j;
	cin>>t;

	while(t--)
	{
		cin>>n;
		ll input[n];
		for(i=0;i<n;i++) cin>>input[i];

		cin>>length;
		ll dp[n][length+1];

		for(i=0;i<n;i++)
		{
			for(j=0;j<=length;j++)
			{
				if(i==0) dp[i][j]=j*input[i];
				else if(j==0) dp[i][j]=0;
				else if(j>=i+1) dp[i][j]=max(dp[i][j-(i+1)]+input[i],dp[i-1][j]);
				else dp[i][j]=dp[i-1][j];
			}
		}
		cout<<dp[n-1][length]<<endl;
	}	
	return 0;
}