#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,i,n;
	cin>>t;

	while(t--)
	{
		cin>>n;
		long long int input[n],area=0,maxarea=0,top;

		for(i=0;i<n;i++) cin>>input[i];
		stack<long long int> s;

		for(i=0;i<n;)
		{
			if(s.empty()||input[i]>=input[s.top()]) s.push(i++);
			else
			{
				top=s.top();
				s.pop();

				if(s.empty())
				{
					area=i*input[top];
				}
				else
				{
					area=input[top]*(i-s.top()-1);
				}
				if(area>maxarea) maxarea=area;
			}
		}
		while(!s.empty())
		{
			top=s.top();
			s.pop();
			if(s.empty())
			{
				area=i*input[top];
			}
			else
			{
				area=input[top]*(i-s.top()-1);
			}
			if(area>maxarea) maxarea=area;
		}
		cout<<maxarea<<endl;
	}
	return 0;
}