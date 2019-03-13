// boj 16985
// Maaaaaaaze
// 바킹독님 풀이 참고했음.
// 왤캐 안대지 오늘.. 

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

class coor{
public:
	int x, y, z;
	coor(int _x, int _y, int _z):x(_x),y(_y),z(_z){};
}



board[4][5][5][5]; // 회전방향 / 층 / x / y

int maze[5][5][5]; // 완성된 미로 
int dist[5][5][5]; // 거리탐색

int dx[6]={1,0,0,-1,0,0,0};
int dy[6]={0,1,0,0,-1,0};
int dz[6]={0,0,1,0,0,-1};


int solve(){
	if(maze[0][0][0]==0 or maze[4][4][4]==0) return 999;
	
	//dist 초기화 
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			for(int k=0; k<5; k++)
				dist[i][j][k]=-1;

	queue<coor> q;
	q.push(coor(0,0,0));
	while(!q.empty()){
		auto cur = q.front(); q.pop();

		if(int dir=0; dir <6; dir++){
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int nz = cur.z + dz[dir];

			if(nx<0 or nx >=5 or ny<0 or ny >=5 or nz<0 or nz >=5) continue;
			if(dist[nx][ny][nx]!=-1 or maze[nx][ny][nz]==0) continue;
			if(nx==4 and ny ==4 and nz ==4) return dist[cur.x][cur.y][cur.z] +1;
			dist[nx][ny][nx] = dist[cur.x][cur.y][cur.z] +1;
			q.push(coor(nx,ny,nz));
		}
	}
	return 9999;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//입력
	for(int i=0; i<5; i++){
		
		//기본 입력 
		for(int j=0; j<5; j++){
			for(int k=0; k<5; k++){
				cin >> board[0][i][j][k]

		//회전 입력1 
		for(int j=0; j<5; j++){
			for(int k=0; k<5; k++){
				board[1][i][4-k][j] = borad[0][i][j][k];

		//회전 입력2
		for(int j=0; j<5; j++){
			for(int k=0; k<5; k++){
				board[2][i][4-k][j] = borad[1][i][j][k];

		//회전 입력3
		for(int j=0; j<5; j++){
			for(int k=0; k<5; k++){
				board[3][i][4-k][j] = borad[2][i][j][k];

	}

	int order = {0,1,2,3,4} //판 쌓는 순서

	int ans = 999;


	//판순서 순열에 따라서 메이즈 bfs
	do{

		for(int tmp =0; tmp <1024; tmp++){ //4의 5승 방향이 4개가 될수있는 판이 5개
		//이게 1024가 제대로 되는건지 이해가 잘안됨.
		// dir은 계속 4로 나눈 나머지가 되는데..

			int brute = tmp; // 5개 판에 대해 dir의 정해주는 변수

			for(int i=0; i<5; i++){
				int dir = brute % 4; // 4진법 활용

				for(int j=0; j<5; j++){
					for(int k=0; k<5; k++){
						maze[i][j][k]=board[dir][order[i]][j][k];
					}
				}

			}
			ans = min(ans,solve());
		}

	}while(next_permutation(order,order+5));

	if(ans ==9999) ans= -1;
	
	return 0;
}
