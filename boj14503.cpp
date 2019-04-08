// boj 14503
// 로봇청소기

// 삼성 기출

#include <bits/stdc++.h>
using namespace std;


//방향 북, 동, 남, 서 순서
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};


struct ROBOT
{
	int y,x,dir;
};

int board[52][52];

int N, M;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	ROBOT robot;

	cin >> robot.y >> robot.x >> robot.dir;

	for(int y =0; y<N; y++){
		for(int x=0; x<M; x++){
			cin >> board[y][x];
			//cout << board[y][x] << ' ';
		}
		//cout << '\n';
	}

	queue<ROBOT> q;

	q.push(robot);

	int cnt=0;
	while(!q.empty()){
		ROBOT cur = q.front(); q.pop();

		//현재 칸을 청소 
		if(board[cur.y][cur.x]==0){
			board[cur.y][cur.x] = 2;
			cnt++;
		}

		//cout << "cur :" << cur.y << ", "<< cur.x <<"/ dir:" <<cur.dir << '\n';

		//현재방향의 왼쪽부터 탐색
		for(int dir=0; dir<4; dir++){

			int nd =(cur.dir+3+3*dir)%4;
			int ny = cur.y + dy[nd];
			int nx = cur.x + dx[nd];

			if(ny <0 or ny>= N or nx<0 or nx >=M) continue;
			if(board[ny][nx]!=0) continue;


			cur.y = ny;
			cur.x = nx;
			cur.dir = nd;
			//cout << "nxt :" << ny << ", "<< nx <<"/ dir:" <<nd << '\n';
			q.push(cur);
			break;
		}

		if(q.empty()){
			//후진
			int ny = cur.y + dy[(cur.dir+2)%4];
			int nx = cur.x + dx[(cur.dir+2)%4];
			//방향은 그대로

			if(ny <0 or ny>= N or nx<0 or nx >=M) break;
			if(board[ny][nx]==1) break;

			//cout << "back :" << ny << ", "<< nx <<"/ dir:" << cur.dir << '\n';
			cur.y = ny;
			cur.x = nx;

			q.push(cur);
		}
	}

	cout << cnt << '\n';
	return 0;
}



 