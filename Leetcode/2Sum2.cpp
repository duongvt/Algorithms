#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll t,n,i,sum;
	vector<ll> result;

	cin>>t;

	while(t--)
	{
		cin>>n;
		ll input[n];

		for(i=0;i<n;i++) cin>>input[i];
		cin>>sum;

		map<ll,ll> m;

		for(i=0;i<n;i++)
		{
			if(m.count(sum-input[i]))
			{
				result.push_back(m[sum-input[i]]);
				result.push_back(i);
				break;
			}
			else
			{
				m[input[i]]=i;
			}
		}

		if(result.size()<2) cout<<"-1"<<endl;
		else cout<<result[0]<<" "<<result[1]<<endl;
	}
return 0;
}