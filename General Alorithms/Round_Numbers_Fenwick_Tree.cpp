#include<bits/stdc++.h>
#define ll long long 
using namespace std;

void update(ll bit[],ll n,ll x,ll val);
ll checkRound(ll n);
ll query(ll bit[],ll x);


ll checkRound(ll n)
{
	if(n<0) return 0;
	else
	{
		ll a,b;
		a=n%10;

		while(n>0)
		{
			b=n%10;
			n=n/10;
		}
		if(a==b) return 1;
		else return 0;
	}
}


void update(ll bit[],ll n,ll x,ll val)
{
	for(;x<=n;x+=x&-x)
	{
		bit[x]+=val;
	}
}


ll query(ll bit[],ll x)
{
	ll count=0;
	for(;x>0;x-=x&-x)
	{
		count+=bit[x];
	}
	return count;
}


int main()
{
	ll n,q,x,y,queryNo,i;
	
	cin>>n>>q;
	ll input[n+1],bit[n+1];
	input[0]=0;
	for(i=0;i<=n;i++) bit[i]=0;

	for(i=1;i<=n;i++)
	{
		cin>>input[i];
		update(bit,n,i,checkRound(input[i]));
	}


	while(q--)
	{
		cin>>queryNo>>x>>y;
		if(queryNo==1)
		{
			ll result=query(bit,y)-query(bit,x-1);
			cout<<result<<endl;
		}
		else
		{
		//	if(checkRound(input[x])==1 && checkround(y)==1) continue;
			if(checkRound(input[x])==0 && checkRound(y)==1)
			{
				input[x]=y;
				update(bit,n,x,1);
			}
			else if(checkRound(input[x])==1 && checkRound(y)==0)
			{
				input[x]=y;
				update(bit,n,x,-1);
			}
			else
			{
				input[x]=y;
			}
		}
	}
return  0;
}