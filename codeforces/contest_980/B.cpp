#include<bits/stdc++.h>
using namespace std;


bool grid[4][100];
int main(){
	int N,K;cin>>N>>K;
	int mid = N>>1;
	if(K == 2*(N-2)){
		grid[1][mid] = grid[2][mid] = true;
		K -= 2;
	}else if(K&1){
		grid[1][mid] = true;
		K -= 1;
	}

	for(int i=1;i<=2 && K > 0;i++) for(int j=1;j<mid && K > 0;j++){
		grid[i][j] = true;
		grid[i][N-j-1] = true;
		K -= 2;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<4;i++,cout<<endl) for(int j=0;j<N;j++) cout<<(grid[i][j]?'#':'.');
	return 0;
}
