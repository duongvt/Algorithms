#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,m,sum,i,j;
	cin>>t;

	while(t--)
	{
		cin>>m;
		long long int coins[m];

		for(i=0;i<m;i++)
		{
			cin>>coins[i];
		}

		cin>>sum;
		long long int a[sum+1],b[sum+1];
		long long int Max=99999999;

		a[0]=0;
		for(i=1;i<=sum;i++) a[i]=Max;
		for(i=0;i<=sum;i++) b[i]=-1;


		for(i=0;i<m;i++)
		{
			for(j=1;j<=sum;j++)
			{
				if(j>=coins[i])
				{
					a[j]=min(a[j],a[j-coins[i]]+1);
					b[j]=i;
				}
			}
		}

		cout<<a[sum]<<endl;

		// while(sum!=0)
		// {
		// 	cout<<coins[b[sum]]<<" ";
		// 	sum=sum-coins[b[sum]];
		// 	cout<<sum<<endl;
		// }
	}
	return 0;
}
