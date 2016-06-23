#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll binarySearch(ll a[],ll n,ll x)
{
	ll low=0,high=n-1,mid;

	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(a[mid]==x) return mid;
		else if(a[mid]<a[high])
		{
			if(x>a[mid] && x<a[high]) low=mid+1;
			else high=mid-1;
		}
		else
		{
			if(x>a[low] && x<a[mid]) high=mid-1;
			else low=mid+1;
		}
	}
	return -1;
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

		ll result=binarySearch(input,n,x);
		cout<<result<<endl;
	}
return 0;
}