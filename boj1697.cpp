#include <bits/stdc++.h>
using namespace std;

int dx[3]={-1,1,0}; //이동 방향
//여기서 dist = -1로 초기화하고 조건주면 문제 생김.
// dist로 조건걸때 방문체크가  안되서 겹침.
// 이전에 2차원일땐 이걸로 어떻게 했었는데.. 그건 왜됐지?
//이렇게 해도 되는거 맞는데.. 뭐에서 틀리는거지?
// 맞 왜 틀 ㅠㅜㅜ


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int dist[100002];
	fill(dist,dist+100000,-1); // fill쓰는거 연습하자
	queue<int> Q;
	Q.push(N);
	dist[N]=0;
	int n = 100;
	while(n>0)
	{
		int now = Q.front(); Q.pop();
		if(now ==K)
		{
			cout << dist[now]<<'\n';
			break;
		}
		for(int dir=0; dir<3; dir++)
		{
			int next = now + dx[dir];
			if(dir==2) next = 2*now; 
			if(next<0 or next >=100000) continue;
			if(dist[next]>=0) continue; // 시작 조건에 따라.. ㅠㅜ 이거 조심  > or >=.. 일단 이거 고쳤는데 안되네 
			cout << "now : "<< now << "now_dist:"<<dist[now]<<'\n';
			Q.push(next);
			dist[next] = dist[now]+1;
			cout << "next : "<< next <<"next_dist:"<<dist[next]<<'\n'; 
		}
		n--;
	}

	return 0;
}
