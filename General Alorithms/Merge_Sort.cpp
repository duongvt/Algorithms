#include<bits/stdc++.h>
#define ll long long 
using namespace std;

void merge(ll A[],ll left[],ll lsize,ll right[],ll rsize)
{
	ll i=0,j=0,k=0;
	while(i<lsize && j<rsize)
	{
		if(left[i]<right[j])
		{
			A[k]=left[i];
			i++;
		}
		else
		{
			A[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<lsize)
	{
		A[k]=left[i]; i++; k++;
	}

	while(j<rsize)
	{
		A[k]=right[j]; j++; k++;
	}

	for(i=0;i<k;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}


void mergeSort(ll A[],ll n)
{
	if(n<2) return;

	ll mid=n/2,i;
	ll left[mid],right[n-mid];

	for(i=0;i<mid;i++) left[i]=A[i];
	for(i=mid;i<n;i++) right[i-mid]=A[i];
	
	mergeSort(left,mid);
	mergeSort(right,n-mid);	
	merge(A,left,mid,right,n-mid);
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

			mergeSort(input,n);
			for(i=0;i<n;i++) cout<<input[i]<<" ";
			cout<<endl;
		}
return 0;
}