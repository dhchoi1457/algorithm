// SWEA 2112
// 보호필름

// 세로 방향으로 진행하면서
// 같은게 연달아서 있는지를 체크한다.
// 같은게 K개 이상 있어야만 검사 통과.
// 이게 모든 컬럼에 적용되어야함

// 통과를 위한 최소 약품투여 횟수
// 약품투여는 row방향을 통일시키는걸로 진행됨
// bfs를 이용하면 될거같다

#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second



const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};
	// up 0
	// right 1
	// down 2
	// left 3


int board[22][22];

int D,W,K;
int main()
{
	int testnum;
	cin >> testnum;

	for(int k=1; k<=testnum; k++)
	{
		cin >> D >> W >> K;

		for(int y=0; y<D; y++){
			for(int x=0; x<W; x++){
				cin >> board[y][x];
				cout << board[y][x] << ' ';
			}
			cout <<'\n';
		}


		//cout << "#" << k << " " << ans <<'\n';
	}

	return 0;
}