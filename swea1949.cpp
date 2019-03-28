//SWEA 1. 등산로 조성

// 시작점은 몇군데 없다.
// 최대 봉우리 위치에서만 시작
// 공사할때 제일 길게하려면 현재 높이 -1로만 공사해야함

// 백트래킹시 아직 안익숙하다.
// 언제 return하는지, 언제 갱신하는지 잘체크
// 구조체 잘 사용하기

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second


struct info{
	int y,x,height,len;
	bool used_k;
};

const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};


int board[10][10];
int visited[10][10];
int N, K;

int ans;

void sol(info cur){

	if(ans<cur.len) ans = cur.len; //최대높이 갱신 

	for(int dir =0; dir<4; dir++)
	{
		info nxt = cur;
		nxt.y += dy[dir];
		nxt.x += dx[dir];
		nxt.height = board[nxt.y][nxt.x];
		
		//OOB
		if(nxt.x <0 or nxt.x >=N or nxt.y <0 or nxt.y>=N) continue;
		//방문한 경우는 못감
		if(visited[nxt.y][nxt.x]==1) continue;

		if(nxt.height < cur.height){
			visited[nxt.y][nxt.x]=1;
			nxt.len++;
			sol(nxt);
			visited[nxt.y][nxt.x]=0;
		}

		if(nxt.height >= cur.height){
			if(cur.used_k==false and abs(cur.height-nxt.height)<K){
				nxt.height = cur.height-1;
				nxt.used_k = true; //공사했음
				visited[nxt.y][nxt.x]=1;
				nxt.len++;
				sol(nxt);
				visited[nxt.y][nxt.x]=0;
			}
		}
	}

	return;
}


int main()
{
	int testnum;
	cin >> testnum;

	for(int k=1; k<=testnum; k++)
	{	
		ans =-1e7;

		cin >> N >> K;

		//cout << "test:"<< ans <<','<< N << ',' << K <<'\n';
		// map 입력
		int top=0;

		for(int y=0; y<N; y++){
			for(int x=0; x<N; x++){
				cin >> board[y][x];
				visited[y][x]=0;

				if(board[y][x]>top){
					top = board[y][x];
				}
			}
		}	

		//top이면 dfs
		for(int y=0; y<N; y++){
			for(int x=0; x<N; x++){
				if(board[y][x]==top){
					visited[y][x]=1;

					info cur;
					cur.y= y;
					cur.x= x;
					cur.height = board[y][x];
					cur.len = 1;
					cur.used_k = false;

					sol(cur);

					visited[y][x]=0;
				}
			}
		}

		cout <<"#"<<k<<" "<< ans << '\n';
	}
	return 0;
}