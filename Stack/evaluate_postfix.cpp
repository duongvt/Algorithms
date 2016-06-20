#include<bits/stdc++.h>
using namespace std;

int main()
{
	char a[100000];
	stack<char> s;

	cin>>a;
	int size=strlen(a),num1,num2,res,i;

	for(i=0;i<size;i++)
	{
		if(a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/')
		{
			s.push(a[i]);
		}
		else
		{
			num1=(int)s.top()-'0';
			cout<<num1<<endl;
			s.pop();
			num2=(int)s.top()-'0';
			cout<<num2<<endl;
			s.pop();

			if(a[i]=='+') 
			{
				res=num1+num2;
				cout<<res<<endl;
			}
			else if(a[i]=='-') 
			{
				res=num1-num2;
			}
			else if(a[i]=='*') 
			{
				res=num1*num2;
				cout<<res<<endl;
			}
			else
			{
				res=num1/num2;
			}
			s.push(res);
		}
	}
	cout<<s.top()<<endl;
	return 0;
}