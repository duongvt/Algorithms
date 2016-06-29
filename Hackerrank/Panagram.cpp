#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	char ch[100000];
	cin.getline(ch,sizeof(ch));

	ll n=strlen(ch),i;
	ll a[52];
	for(i=0;i<52;i++)
	{
		a[i]=0;
	}

	for(i=0;i<n;i++)
	{
		if(ch[i]>=97 && ch[i]<=122)
		{
			a[ch[i]-97]++;
			a[ch[i]-97+26]++;
		}
		else if(ch[i]>=65 && ch[i]<=90)
		{
			a[ch[i]-65+26]++;
			a[ch[i]+32-97]++;
		}
	}

	ll res=1;
	for(i=0;i<52;i++)
	{
		if(a[i]==0) 
		{
			res=0; 
			break;
		}
	}

	if(res==1) cout<<"panagram"<<endl;
	else cout<<"not panagram"<<endl;
 }	