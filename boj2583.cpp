#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // 여기에 ;붙이면 에러남. 주의

int K,N,M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[102][102]; // map 이거 input 형태에 따라 조절해야됨. string할지 int할지. 이거떄매 틀렸었음.
int vis[102][102]; // visited check
int area[10002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> K;
	// M 이 y축
	// N이 x축
	// K가 직사각형 갯수

	for(int l=0; l<N; l++)
		fill(board[l],board[l]+M,0);


	for(int k=0; k<K; k++)
	{
		int nx1, ny1, nx2, ny2;
		cin >> nx1 >> ny1 >> nx2 >> ny2;

		for(int x=nx1; x<nx2; x++){
			for(int y= ny1; y<ny2; y++){
				board[x][y]=1;
			}
		}

	}

	//map 확인용 
	// for(int x=0; x<N; x++)
	// {
	// 	for(int y=0; y<M; y++)
	// 	{
	// 		cout << board[x][y] << '\t';
	// 	}
	// 	cout << '\n';
	// }


	int cnt=0;
	
	for(int i=0; i<N; i++){ // x,y 축이 각각 N, M 인지 조심하자.. 이거때매 삽질함ㅠ
		for(int j =0; j<M; j++){
			if(board[i][j]!=0 or vis[i][j]==1) continue;
			queue<pair<int,int>> Q;
			Q.push({i,j});
			vis[i][j]=1;

			cnt++; // 새로운 시작점이 생길때마다 cnt ++; 단지수.
			int h = 0; // 단지내 집 수 

			while(!Q.empty())
			{
				auto cur = Q.front(); Q.pop();
				h++;

				for(int dir=0; dir<4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if(nx<0 or nx>=N or ny <0 or ny>=M) continue;
					if(board[nx][ny]!=0 or vis[nx][ny]==1) continue;
					Q.push({nx,ny});
					vis[nx][ny]=1;
				}
			}
			area[cnt-1]=h;
		}
	}


// ----------------

	sort(area,area+cnt);
	cout << cnt << '\n';
	for(int z=0; z<cnt; z++)
	{
		cout << area[z] << ' ';
	}
	cout << '\n';
	return 0;
}