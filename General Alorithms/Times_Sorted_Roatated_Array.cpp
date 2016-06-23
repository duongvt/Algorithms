#include<bits/stdc++.h>
#define ll long long 
using namespace std;


ll binarySearch(ll a[],ll n)
{
	ll low=0,high=n-1,mid,next,prev;

	while(low<=high)
	{
		if(a[low]<a[high]) return low;

		mid=low+(high-low)/2;
		next=(mid+1)%n;
		prev=(mid+n-1)%n;

		if(a[mid]<a[next] && a[mid]<a[prev]) return mid;
		else if(a[mid]<a[high]) high=mid-1;
		else if(a[mid]>a[low]) low=mid+1;
	}
}


int main()
{
	ll t,n,i;
	cin>>t;

	while(t--)
	{
		cin>>n;
		ll input[n];
		for(i=0;i<n;i++) cin>>input[i];

		ll result=binarySearch(input,n);
		cout<<result<<endl;
	}
return 0;
}