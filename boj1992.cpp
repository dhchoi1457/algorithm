// boj 1992
// 쿼드트리

// boj1074 Z와 유사
// 1/4사이즈에 맞추어 계속 탐색을 해간다.
// 1/4 사이즈에 맞추었으므로, 탐색시 사이즈를 맞춰 갱신한다.

#include <bits/stdc++.h>
using namespace std;

int N;
string board[65];

void quad_tree(int n, int r, int c){
	char ch= board[r][c]; // start n  , r=0, c=0
	bool same=1;
	//cout <<"ch , n , r , c:"<<ch <<' ' << n <<' ' << r << ' '<< c   << '\n'; 
	//해당영역이 전부다 같은지 탐색
	for(int i=r; i<r+n; i++){
		for(int j=c; j<c+n; j++){
			//cout << "i,j:" << i << ' ' << j << '\n';
			//cout << "ch vs board:" << ch << " vs " << board[i][j] << '\n';
			if(ch!=board[i][j]){
				//cout << "break;"<<'\n';
				same=0;
				break;
			} 
		}
		if(same==0) break;	
	}

	//cout << "same :" << same << '\n';

	if(same==1){
		cout << ch;
		return;
	}
	else{
	cout << '(';
	quad_tree(n/2,r,c); //4등분 에서 0,0
	quad_tree(n/2,r,c+n/2); // 4등분 에서 0,1
	quad_tree(n/2,r+n/2,c); // 4등분 에서 1,0
	quad_tree(n/2,r+n/2,c+n/2); // 4등분에서 1,1
	cout << ')';
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; // 2^N * 2^N input
	
	for(int i=0; i<N; i++){
		cin >> board[i];
	}

	quad_tree(N,0,0);
}