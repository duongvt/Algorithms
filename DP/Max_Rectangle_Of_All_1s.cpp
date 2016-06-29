#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll MaxArea(ll dp[],ll n)
{
	stack<ll> s;
	ll area=0,maxArea=0,top,i;

	for(i=0;i<n;)
	{
		if(s.empty() || dp[s.top()]<=dp[i]) s.push(i++);
		else
		{
			top=s.top();
			s.pop();
			if(s.empty()) area=dp[top]*i;
			else area=dp[top]*(i-s.top()-1);

			if(area>maxArea) maxArea=area;
		}
	}

	while(!s.empty())
	{
		top=s.top();
		s.pop();
		if(s.empty()) area=dp[top]*i;
		else area=dp[top]*(i-s.top()-1);

		if(area>maxArea) maxArea=area;
	}
	return maxArea;
}


int main()
{
	ll t,i,j,m,n;
	cin>>t;

	while(t--)
	{
		cin>>m>>n;
		ll input[m][n],result=0;

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>input[i][j];
			}
		}

		ll dp[n];
		for(i=0;i<n;i++) dp[i]=0;

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(input[i][j]==0) dp[j]=0;
				else dp[j]+=input[i][j];
			}
			result=max(result,MaxArea(dp,n));
		}
		cout<<result<<endl;
	}
}