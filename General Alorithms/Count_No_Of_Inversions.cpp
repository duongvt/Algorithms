#include<bits/stdc++.h>
#define ll long long 
using namespace std;



ll merge(ll input[],ll aux[],ll low,ll mid,ll high)
{
	ll i,j,k,count=0;
	i=low; j=mid; k=low;

	while(i<=mid-1 && j<=high)
	{
		if(input[i]<=input[j])
		{
			aux[k++]=input[i++];
		}
		else
		{
			aux[k++]=input[j++];
			count+=(mid-i);
		}
	}

	while(i<=mid-1) aux[k++]=input[i++];
	while(j<=high) aux[k++]=input[j++];


	for (i=low; i <= high; i++)
    input[i] = aux[i];

	return count;
}


ll mergeSort(ll input[],ll aux[],ll low,ll high)
{
	ll mid,count=0;
	if(high>low)
	{
		mid=(low+high)/2;
		count=mergeSort(input,aux,low,mid);
		count+=mergeSort(input,aux,mid+1,high);
		count+=merge(input,aux,low,mid+1,high);
	}
	return count;
}

int main()
{
	ll t,n,i;
	cin>>t;

	while(t--)
	{
		cin>>n;
		ll input[n],aux[n];
		for(i=0;i<n;i++) cin>>input[i];
		ll inversions;

		inversions=mergeSort(input,aux,0,n-1);
		cout<<inversions<<endl;
	}
return 0;
}