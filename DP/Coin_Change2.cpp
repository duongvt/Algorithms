#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,n,i,j,sum;
	cin>>t;

	while(t--)
	{
		cin>>n;
		long long int a[n];

		for(i=0;i<n;i++) 
		{
			cin>>a[i];
		}

		cin>>sum;

		long long int b[n][sum+1];

		for(i=0;i<n;i++)
		{
			for(j=0;j<=sum;j++)
			{
				if(i==0||j==0) b[i][j]=1;
			 	else if(j>=a[i]) b[i][j]=b[i-1][j]+b[i][j-a[i]];
				else b[i][j]=b[i-1][j];
			}
		}
		cout<<b[n-1][sum]<<endl;
	}
	return 0;
}