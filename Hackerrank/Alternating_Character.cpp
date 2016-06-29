#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll t,i;
	char ch[100000];
	cin>>t;

	while(t--)
	{
		cin>>ch;
		ll size=strlen(ch);

		if(size==1)
		{
			cout<<"0"<<endl;
		}

		ll count=0;
		for(i=0;i<size;i++)
		{
			if(ch[i]==ch[i+1]) count++;
		}
		cout<<count<<endl;
	}
	return 0;
}