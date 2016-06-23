#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
	ll t,m,n,i,j,k;
	cin>>t;

	while(t--)
	{
		cin>>m>>n;
		ll arr1[m],arr2[n],arr3[m+n];
		for(i=0;i<m;i++) cin>>arr1[i];
		for(i=0;i<n;i++) cin>>arr2[i];
		
		i=0,j=0,k=0;

	    while(i<m && j<n)
	    {
	    	if(arr1[i]<=arr2[j])
	    	{
	    		arr3[k]=arr1[i];
	    		i++;
	    	}
	    	else
	    	{
	    		arr3[k]=arr2[j];
	    		j++;
	    	}
	    	k++;
	    }

	    while(i<m)
	    {
	    	arr3[k]=arr1[i];
	    	k++;
	    	i++;
	    }

	    while(j<n)
	    {
	    	arr3[k]=arr2[j];
	    	k++;
	    	j++;
	    }

	    for(i=0;i<m+n;i++)
	    {
	    	cout<<arr3[i]<<" ";
	    }
	    cout<<endl;
	}
return 0;
}