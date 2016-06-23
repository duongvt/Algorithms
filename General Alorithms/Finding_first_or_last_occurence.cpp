#include<bits/stdc++.h>
#define ll long long 
using namespace std;


ll find_first_last_occurrence(ll input[],ll n,ll x,bool y)
{
	ll low=0,high=n-1,mid,result=-1;

	while(low<=high)
	{
		mid=(low+high)/2;
		if(input[mid]==x)
		{
			result=mid;
			if(y==0) high=mid-1;
			else low=mid+1;
		}
		else if(input[mid]>x) high=mid-1;
		else low=mid+1;
	}
	return result;
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

		ll first_occurrence=find_first_last_occurrence(input,n,x,0);
		ll last_occurrence=find_first_last_occurrence(input,n,x,1);

		cout<<first_occurrence<<" "<<last_occurrence<<endl;
	}
	return 0;
}