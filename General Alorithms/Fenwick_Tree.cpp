#include<bits/stdc++.h>
#define ll long long	
using namespace std;


void update(ll bit[],ll n,ll x,ll val)
{
	for(;x<=n;x+=x&-x)
	{
		bit[x]+=val;
	}
}


ll query(ll bit[],ll n,ll x)
{
	ll sum=0;
	for(;x>0;x-=x&-x)
	{
		sum+=bit[x];
	}
	return sum;
}


int main()
{
	ll t,n,queries,q,x,y,i;
	cin>>t;

	while(t--)
	{
		cin>>n;
		ll input[n+1],sum;
		ll bit[n+1];
		input[0]=0;

		for(i=0;i<=n;i++) bit[i]=0;
		for(i=1;i<=n;i++) 
		{
			cin>>input[i];
			update(bit,n+1,i,input[i]);
		}


		cin>>queries;

		while(queries--)
		{
			cin>>q>>x>>y;

			if(q==1)
			{
				ll val=input[x];
				cout<<val<<endl;
				update(bit,n+1,x,y-val);
			}
			if(q==2)
			{
				sum=query(bit,n,y)-query(bit,n,x-1);
				cout<<sum<<endl;
			}
		}
	}
return 0;
}