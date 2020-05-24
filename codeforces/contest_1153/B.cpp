#include<bits/stdc++.h>
using namespace std;

int A[100],B[100];
int main()
{
	int m,n,b;
	cin>>m>>n>>b;
	for(int i=0;i<n;i++)cin>>B[i];
	for(int i=0;i<m;i++)cin>>A[i];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>b;
			if(b)cout<<min(A[i],B[j]);
			else cout<<0;
			cout<<' ';
		}
		cout<<endl;
	}
}
