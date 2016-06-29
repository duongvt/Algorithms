#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
	ll t,m,n,i,j;
	cin>>t;

	while(t--)
	{
		cin>>m>>n;
		ll a[m],b[n];
		vector<ll> v;
		for(i=0;i<m;i++) cin>>a[i];
		for(i=0;i<n;i++) cin>>b[i];
		
		i=0,j=0;

		while(i<m && j<n)
		{
			if(a[i]<b[j]) i++;
			else if(a[i]>b[j]) j++;
			else if(a[i]==b[j])
			{
				v.push_back(a[i]);
				i++;
				j++;
			}
		}

		ll size=v.size();
		for(i=0;i<size;i++)
		{
			cout<<v[i]<<" ";
		}	
		cout<<endl;
		v.clear();
	}
}