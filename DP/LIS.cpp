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

		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}

		for(i=0;i<n;i++) b[i]=1;   //Initially for a single element LIS can be 1.


		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[j]<a[i])
				{
					if(b[j]+1>b[i]) b[i]=b[j]+1;
				}
			}
		}	

		sort(b,b+n);
		cout<<b[n-1]<<endl;
	}
}