#include<bits/stdc++.h>
#define ll long long 
using namespace std;



ll merge(ll A[],ll left[],ll lsize,ll right[],ll rsize)
{
	ll i=0,j=0,k=0,count=0;

	while(i<lsize && j<rsize)
	{
		if(left[i]<=right[j]) A[k++]=left[i++];
		else
		{
			A[k++]=right[j++];
			count+=lsize-i;
		}
	}

	while(i<lsize) A[k++]=left[i++];
	while(j<rsize) A[k++]=right[j++];

	return count;
}


ll mergeSort(ll A[],ll n)
{
	if(n<2) return 0;

	ll mid=n/2;
	ll left[mid],right[n-mid],count=0,i;

	for(i=0;i<mid;i++) left[i]=A[i];
	for(i=mid;i<n;i++) right[i-mid]=A[i];

	count=mergeSort(A,mid);
	count+=mergeSort(A,n-mid);
	count+=merge(A,left,mid,right,n-mid);
	return count;	
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
		ll inversions=mergeSort(input,n);
		cout<<inversions<<endl;
	}
return 0;
}