#include<bits/stdc++.h>
using namespace std;
long long int sparse[500][500];


long long int rmq(long long int x,long long int y,long long int a[])
{
	if(x==y) return a[x];

	long long int l=y-x+1;
	long long int k=int(log2(l));
	//cout<<k<<endl;

	return min(a[sparse[x][k]],a[sparse[x+l-(1<<k)][k]]);
}



int main()
{
	long long int t,m,n,i,j,q,x,y;
	cin>>t;

	while(t--)
	{
		cin>>m;
		long long int a[m];
		for(i=0;i<m;i++) cin>>a[i];


		// n=ceil(log(m))+1;	
		// long long int sparse[m][n];




		//Building the sparse table
		for(i=0;i<m;i++) sparse[i][0]=i;
		for(j=1;(1<<j)<=m;j++)
		{
			for(i=0;i+(1<<j)-1<m;i++)
			{
				if(a[sparse[i][j-1]]<a[sparse[i+(1<<(j-1))][j-1]]) sparse[i][j]=sparse[i][j-1];
				else sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
			}
		}



		//Queries
		cin>>q; 
		long long int result;  
		while(q--)
		{
			cin>>x>>y;
			result=rmq(x,y,a);
			cout<<result<<endl;
		}
	}

	return 0;
}


