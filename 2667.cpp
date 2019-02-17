// boj9466
// 텀프로젝트 
// cycle을 찾아내는 문제이므로 대부분 stack을 쓰는듯
// 후.. 여기서 삽질을 많이했으므로, 일단 skip..ㅠㅜ
// 추후에 다시풀기

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string board[27]; // string 이므로 1 / '1' 주의 
int visit[27][27]; // 방문여부 
int house[700];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; //map size

	int ind; // house index

	cin >> N;
	for(int n=0; n<N; n++)
	{
		cin >> board[n];
	}

	int cnt=0;
	for(int i=0; i<N; i++){
		for(int j =0; j<N; j++){
			if(board[i][j]=='0' or visit[i][j]==1) continue;
			queue<pair<int,int>> Q;
			Q.push({i,j});
			visit[i][j]=1;

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

					if(nx<0 or nx>=N or ny <0 or ny>=N) continue;
					if(board[nx][ny]=='0' or visit[nx][ny]==1) continue;
					Q.push({nx,ny});
					visit[nx][ny]=1;
				}
			}
			house[cnt-1]=h;
		}
	}

	cout << cnt <<'\n';

	sort(house,house+cnt);	//오름차순 정렬
	for(int tt=0; tt<cnt; tt++)
	{
		cout << house[tt] <<'\n';
	}

	return 0;
}


