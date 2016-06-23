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

		ll dp[n+1];
		dp[0]=1;
		dp[1]=1;

		for(i=2;i<=n;i++)
		{
			dp[i]=0;
			for(j=0;j<i;j++)
			{
				dp[i]+=dp[j]*dp[i-j-1];
			}
		}
		cout<<dp[n]<<endl;
	}
return 0;
}
