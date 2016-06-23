#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll BinarySearch(ll input[],ll n,ll x)
{
	ll low=0,high=n-1,mid;

	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(input[mid]==x) return mid;
		else if(input[mid]>x) high=mid-1;
		else low=mid+1;
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

		sort(input,input+n);

		ll index=BinarySearch(input,n,x);
		cout<<index<<endl;	
	}
return 0;
}