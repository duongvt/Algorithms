#include<bits/stdc++.h>
#define ll long long 
using namespace std;


ll MaxArea(ll input[],ll n)
{
		stack<ll> s;
		ll area=0,maxArea=0,top,i;
		for(i=0;i<n;)
		{
			if(s.empty() || input[s.top()]<=input[i]) s.push(i++);
			else
			{
				top=s.top();
				s.pop();
				if(s.empty()) area=i*input[top];
				else area=input[top]*(i-s.top()-1);
				if(area>maxArea) maxArea=area;
			}
		}

		while(!s.empty())
		{
			top=s.top();
			s.pop();
			if(s.empty()) area=i*input[top];
			else area=input[top]*(i-s.top()-1);
			if(area>maxArea) maxArea=area;
		}

		return maxArea;
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

		ll result=MaxArea(input,n);
		cout<<result<<endl;
	}

return 0;
}