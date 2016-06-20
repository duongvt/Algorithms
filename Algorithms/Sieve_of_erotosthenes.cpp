#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,n,i,j;
	cin>>t;

	while(t--)
	{
		cin>>n;
		long long int prime[n+1];

		for(i=0;i<=n;i++) prime[i]=1; //Initially suppose all are prime.
		prime[0]=0;
		prime[1]=0;

		long long int sqr=sqrt(n);

		for(i=2;i<=sqr;i++)
		{
			if(prime[i]==1)
			{
				for(j=2;i*j<=n;j++)
				{
					prime[i*j]=0;
				}
			}
		}

		for(i=2;i<=n;i++)
		{
			if(prime[i]==1) cout<<i<<" ";
		}		
		cout<<endl;
	}
	return 0;
}