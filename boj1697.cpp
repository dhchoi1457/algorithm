//boj 1697
// 숨바꼭질

// Q.
// int dist[200001]; // 10만일떄 안되다가, 20만일떄 통과.. 왜지?

#include <bits/stdc++.h>
using namespace std;

int dx[3]={-1,1,0}; //이동 방향

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	if(N>=K){
		cout << N-K << '\n';
		return 0;
	}

	int dist[200001]; // 10만일떄 안되다가, 20만일떄 통과.. 왜지?
	fill(dist,dist+200000,-1); // fill쓰는거 연습하자
	queue<int> Q;
	Q.push(N);
	dist[N]=0;


	while(!Q.empty())
	{
		int now = Q.front(); Q.pop();
		if(now ==K)
		{
			cout << dist[now]<<'\n';
			break;
		}
		//cout << "now : "<< now << "now_dist:"<<dist[now]<<'\n';
		for(int dir=0; dir<3; dir++)
		{
			int next = now + dx[dir];
			if(dir==2) next = 2*now; 
			if(next<0 or next >100000) continue; //범위 항상 잘 체크
			if(dist[next]>=0) continue; // 시작 조건에 따라.. ㅠㅜ 이거 조심  > or >=.. 일단 이거 고쳤는데 안되네 
			Q.push(next);
			dist[next] = dist[now]+1;
		//	cout << "next : "<< next <<"next_dist:"<<dist[next]<<'\n'; 
		}
	}
	return 0;
}

