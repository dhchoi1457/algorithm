// boj9466
// 텀프로젝트 
// cycle을 찾아내는 문제이므로 대부분 stack을 쓰는듯
// 후.. 여기서 삽질을 많이했으므로, 일단 skip..ㅠㅜ
// 추후에 다시풀기

#include <bits/stdc++.h>
using namespace std;

int board[100002];
int visit[100002]; // 방문여부 
int fin[100002]; // 사이클 체크용. 진짜 다시 방문할지 안할지?


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int t=0; t<T; t++) // test case 갯수만큼 반복
 	{
 		int N;
 		cin >> N;
 		
 		for(int n=1; n<=N; n++ )
 			cin >> board[n];

 		queue<int> Q;

 		int cnt = 0;
 		for(int i=1; i<=N; i++ )
 		{
			if(visit[i]==1) continue; // 이미 방문했던건 다시 안함. 이전에 사이클찾다가 확인했을 것.
			Q.push(i);
			visit[i]=1;
			while(!Q.empty())
			{
				auto cur = Q.front(); Q.pop();
				int nxt = board[cur];
				if(visit[nxt]!=1) //기존에 방문했던적이 없다면
				{
					Q.push(nxt);
					fin[cur]=1; // 이게 여기들어가는게 맞나
					continue;
				}

				if(fin[nxt]!=1) // visit 1 이면서 fin 0 인경우. 사이클
				{
					for(int x = nxt; cur !=x; x=board[x]){cnt++;}
					cnt++;

				}
				fin[cur]=1;
			}

			cout << N - cnt << "\n";
 		} 		
	}

	return 0;
}


