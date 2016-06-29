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
		ll a[n],temp,low,high;
		vector< vector<ll> > v1;
		vector<ll> v2;
		for(i=0;i<n;i++) cin>>a[i];

		sort(a,a+n);
		for(i=0;i<n-2;i++)
		{
			temp=a[i];
			low=i+1;
			high=n-1;
			while(low<high)
			{
				if(a[low]+a[high]+temp>0) high--;
				else if(a[low]+a[high]+temp<0) low++;
				else if(a[low]+a[high]+temp==0)
				{
					v2.push_back(a[low]);
					v2.push_back(a[high]);
					v2.push_back(a[i]);
					break;
				}
			}
			if(!v2.empty())
			{
				v1.push_back(v2);
				v2.clear();
			}
		}

		for(i=0;i<v1.size();i++)
		{
			for(j=0;j<v2.size();j++)
			{
				cout<<v1[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}