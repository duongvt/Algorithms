#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
	char str1[100000],str2[100000];
	ll t,i,j;
	cin>>t;

	while(t--)
	{
		cin>>str1;
		cin>>str2;
		ll m=strlen(str1),n=strlen(str2);
		ll dp[m+1][n+1];

		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0 || j==0) dp[i][j]=false;
				else if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=0;
			}
		}

		ll max=-9999999999;
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(max<dp[i][j]) max=dp[i][j];
			}
			
		}

		cout<<max<<endl;

	}
return 0;
}