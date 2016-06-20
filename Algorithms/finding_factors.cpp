#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,i,n;
	cin>>t;

	while(t--)
	{
		cin>>n;
		long long int sqr=sqrt(n);
		vector<long long int> v;

		for(i=1;i<=sqr;i++)
		{
			if(n%i==0)
			{
				v.push_back(i);
				if(sqr!=i) v.push_back(n/i);
			}
		}

		long long int size=v.size();

		for(i=0;i<size;i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
}