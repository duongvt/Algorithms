#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll t,n,i,j,x,sum;
	vector<ll> result;
	cin>>t;

	while(t--)
	{
		cin>>n;
		ll input[n];
		for(i=0;i<n;i++)
		{
			cin>>input[i];
		}

		cin>>sum;

		vector<ll> temp(input,input+n);

		sort(temp.begin(),temp.end());

		ll low=0,high=temp.size()-1;

		while(low<high)
		{
			if(temp[low]+temp[high]>sum) high--;
			else if(temp[low]+temp[high]<sum) low++;
			else if(temp[low]+temp[high]==sum)
			{
				for(i=0;i<n;i++)
				{
					if(input[i]==temp[low]||input[i]==temp[high])
					{
						result.push_back(i);
					}
				}
			}
		}

		if(result.size()<2) cout<<"-1"<<endl;
		else cout<<result[0]<<" "<<result[1]<<endl;
		result.clear();      temp.clear();
	}
return 0;
}