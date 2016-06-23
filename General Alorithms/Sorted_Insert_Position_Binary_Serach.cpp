#include<bits/stdc++.h>
#define ll long long 
using namespace std;


int binarySearch(ll input[],ll n,ll x)
{
	ll low=0,high=n-1,mid;

	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(x==input[mid]) return mid;
		else if(x<input[mid]) high=mid-1;
		else low=mid+1;
	}
	return low;
}

int main()
{
	ll t,n,x,i;
	cin>>t;

	while(t--)
	{
		cin>>n;
		ll input[n];
		for(i=0;i<n;i++) cin>>input[i];
		cin>>x;

		ll index=binarySearch(input,n,x);
		cout<<index<<endl;
	}
return 0;
}