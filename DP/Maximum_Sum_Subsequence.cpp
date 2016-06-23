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
		ll input[n],dp[n];

		for(i=0;i<n;i++)
		{
			cin>>input[i];
			dp[i]=input[i];
		}

		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(input[j]<input[i])
				{
					dp[i]=max(dp[i],dp[j]+input[i]);
				}
			}
		}


		cout<<endl;
		sort(dp,dp+n);
		cout<<dp[n-1]<<endl;
	}
}