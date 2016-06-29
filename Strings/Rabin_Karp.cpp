#include<bits/stdc++.h>
#define ll long long
using namespace std;

char text[5000000],pattern[5000000];


ll prime=101;


ll createHash(char str[],ll n)
{
	ll i,hash=0;

	for(i=0;i<=n;i++)
	{
		hash+=str[i]*(pow(prime,i));
	}
	return hash;
}

ll recreateHash(char str[],ll oldHash,ll oldIndex,ll newIndex,ll len)
{
	ll newHash=oldHash-str[oldIndex];
	newHash=newHash/prime;
	newHash+=str[newIndex]*pow(prime,len-1);
	return newHash;
}


bool check(char text[],ll start1,ll end1,char patt[],ll start2,ll end2)
{
	if(end1-start1!=end2-start2) return false;

	while(start1<=end1 && start2<=end2)
	{
		if(text[start1]!=patt[start2]) return false;
		start1++;
		start2++;
	}
	return true;
}

int main()
{
	ll t,i,n;
	// cin>>t;

	while(scanf("%lld",&n)!=EOF)
	{
	
		cin>>pattern;
		cin>>text;

		ll m=strlen(text);
	//	ll n=strlen(pattern);
		if(n>m)
		{
			cout<<endl;
			continue;
		}
		ll texthash=createHash(text,n-1);
		ll patternhash=createHash(pattern,n-1);
		ll result=-1;

		for(i=1;i<=m-n+1;i++)
		{
			if(texthash=patternhash)
			{
				bool a=check(text,i-1,i+n-2,pattern,0,n-1);
				if(a==1)
				{
					result=i-1;
					cout<<result<<endl;
				}
			}
			if(i<m-n+1) texthash=recreateHash(text,texthash,i-1,i+n-1,n);
		}
		//cout<<result<<endl;

	}
return 0;
}