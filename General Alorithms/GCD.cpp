#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long int t,n,a,b;
	cin>>t;

	while(t--)
	{
		cin>>a>>b;
		long long int dividend=a>=b?a:b;
		long long int divisor=a<=b?a:b;
		long long int remain;

		while(divisor!=0)
		{
			remain=dividend%divisor;
			dividend=divisor;
			divisor=remain;
		}

		cout<<dividend<<endl;
	}
}