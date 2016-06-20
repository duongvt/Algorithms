#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,n,i,j;
	cin>>t;

	while(t--)
	{
		cin>>n;
		long long int a[n],b[n];

		for(i=0;i<n;i++) cin>>a[i];

		b[0]=0;

		for(i=1;i<n;i++) b[i]=9999999;

		for(i=1;i<n;i++) 
		{
			for(j=0;j<i;j++)
			{
				if(j+a[j]>=i) b[i]=min(b[i],b[j]+1);
			}
		}

		for(i=0;i<n;i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
		cout<<b[n-1]<<endl;
	}
}