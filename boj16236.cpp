// boj 16236
// 아기상어
// 2018 하반기 삼성전자 ce/im SW역량기출

#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];

int sx, sy;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
			if(board[i][j]==9){
				sx=i;
				sy=j;
			}
		}
	}	

	cout << sx << sy <<'\n';

	return 0;
}



 