#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	char str[100000],pat[100000];
	ll t,i,j;
	cin>>t;

	while(t--)
	{
		cin>>str;
		cin>>pat;
		ll m=strlen(str),n=strlen(pat);
		bool dp[m+1][n+1];

		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0 && j==0) dp[i][j]=true;
				//else if(i==0 && pat[j-1]=='*') dp[i][j]=true;
				else if(i==0 || j==0) dp[i][j]=false;
				else if(str[i-1]==pat[j-1] || pat[j-1]=='?') dp[i][j]=dp[i-1][j-1];
				else if(pat[j-1]=='*') dp[i][j]=dp[i-1][j]||dp[i][j-1];
				else dp[i][j]=false;
			}
		}


		// for(i=0;i<=m;i++)
		// {
		// 	for(j=0;j<=n;j++)
		// 	{
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }


		cout<<dp[m][n]<<endl;
	}
}