
// boj5014
// 스타트링크

#include <bits/stdc++.h>
using namespace std;

int F,S,G,U,D;
int dist[1000002];
int dx[2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;

	// 전체 건물 층수 F
	// 현재 S
	// 목적지 G
	// U층위로
	// D층 아래로

	queue<int> Q;
	Q.push(S);

	dx[0]= U;
	dx[1]= -D;

	fill(dist+1,dist+F+1,-1); // 1층부터 시작하므로, 초기화시에 주의
	dist[S]=0;
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();

		if(cur==G){
			cout << dist[G] << '\n';
			return 0;
		}
		for(int i=0; i<2; i++){
			int nxt = cur+dx[i];
			if(nxt<=0 or nxt > F) continue;
			if(dist[nxt]>=0) continue;
			dist[nxt]= dist[cur]+1;
			Q.push(nxt);
		}
	}

	cout << "use the stairs" << '\n';
	return 0;
} 