#include<bits/stdc++.h>
#define ll long long 
using namespace std;


int main()
{
	long long t,n,i,j;
	cin>>t;

	while(t--)
	{
		cin>>n;
		ll input[n],dp1[n],dp2[n];
		for(i=0;i<n;i++)
		{
			cin>>input[i];
			dp1[i]=1;
			dp2[i]=1;
		}

		// Finding LIS from left side
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(input[j]<input[i])
				{
					dp1[i]=max(dp1[i],dp1[j]+1);
				}
			}
		}

		//Finding LIS from right side
		for(i=n-2;i>=0;i--)
		{
			for(j=n-1;j>i;j--)
			{
				if(input[j]<input[i])
				{
					dp2[i]=max(dp2[i],dp2[j]+1);
				}
			}
		}

		ll max=-9999999;
		for(i=0;i<n;i++)
		{
			if(dp1[i]+dp2[i]-1>max) max=dp1[i]+dp2[i]-1;
		}
		cout<<max<<endl;
	}
return 0;
}