#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long t,i;
	cin>>t;

	while(t--)
	{
		stack<char> s;
		char ch[1000];
		bool res=1;

		cin>>ch;
		long long int size=strlen(ch);

		for(i=0;i<size;i++)
		{
			if(ch[i]=='('||ch[i]=='['||ch[i]=='{')
			{
				s.push(ch[i]);
			}
			else if([ch[i]==')'||ch[i]==']'||ch[i]=='}')
			{
				if(s.empty())
				{
					res=0;
					break;
				}
				if(ch[i]==')')
				{
					if(s.top()=='(')       //last unclosed is first closed
					{
						s.pop();
					}
				}
				if(ch[i]==']')
				{
					if(s.top()=='[')      //last unclosed is first closed
					{
						s.pop();
					}
				}
				if(ch[i]=='}')
				{
					if(s.top()=='{')     //last unclosed is first closed
					{
						s.pop();
					}
			    }
			}	
		}

		if(res==0)
		{
			cout<<"Not balanced"<<endl;
			continue;
		}
		if(s.empty()) cout<<"Balanced"<<endl;
		else cout<<"Not Balanced"<<endl;
	}
return 0;
}