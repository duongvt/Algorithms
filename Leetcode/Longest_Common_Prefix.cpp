#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll findMin(vector<string> v)
{
	ll size=v.size(),i;
	ll min=999999999;
	for(i=0;i<size;i++)
	{
		if(min>v[i].length()) min=v[i].length();
	}
	return min;	
}


bool allHavePrefix(vector<string> v,string str,ll low,ll high)
{
	ll i,j,n=v.size();
	for(i=0;i<n;i++)
	{
		for(j=low;j<=high;j++)
		{
			if(v[i][j]!=str[j]) return false;
		}
	}
	return true;
}


int main()
{
	ll t,n,i;
	cin>>t;

	while(t--)
	{
		cin>>n;
		string s,prefix;
		vector<string> v;

		for(i=0;i<n;i++)
		{
			cin>>s;
			getchar();
			v.push_back(s);
		}

		ll min;
		min=findMin(v);
		
		ll low=0,high=min-1,mid;

		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(allHavePrefix(v,v[0],low,mid))
			{
				prefix+=v[0].substr(low,mid-low+1);
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
			cout<<prefix<<endl;
		}
		cout<<prefix<<endl;
		v.clear();
	}
return 0;
}