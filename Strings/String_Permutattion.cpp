#include<bits/stdc++.h>
#define ll long long 
using namespace std;


void print(char result[])
{
	int i,size=strlen(result);
	for(i=0;i<size;i++)
	{
		cout<<result[i];
	}
	cout<<endl;
}



void permute(char ch[],ll count[],char result[],ll level,ll mapSize,ll inputSize)
{
	ll i;
	if(inputSize==level)
	{
		print(result);
		return;
	}

	for(i=0;i<mapSize;i++)
	{
		if(count[i]==0) continue;
		
		result[level]=ch[i];
		count[i]--;
		permute(ch,count,result,level+1,mapSize,inputSize);
		count[i]++;
	}
}



int main()
{
	ll t,i,j;
	char str[100000];
	cin>>t;

	while(t--)
	{
		cin>>str;
		ll size=strlen(str);
		char result[size];

		map<char,ll> m;
		for(i=0;i<size;i++) m[str[i]]++;

		char ch[m.size()];
		ll count[m.size()];	

		map<char,ll>::iterator it=m.begin();

		i=0,j=0;
		while(it!=m.end())
		{
			ch[i++]=it->first;
			count[j++]=it->second;
			it++;
		}

		permute(ch,count,result,0,m.size(),size);
	}
	return 0;
}