// boj 1074
// Z

// 1/4사이즈에 맞추어 계속 탐색을 해간다.
// 1/4 사이즈에 맞추었으므로, 탐색시 사이즈를 맞춰 갱신한다.

#include <bits/stdc++.h>
using namespace std;

int N,R,C;
int cnt=0;

void z_search(int n, int r, int c){
	if(n==2){ //작은 z
		if(r==R and c==C) // z에서 0,0
		{
			cout << cnt << '\n'; // 0부터 시작하므로, 이전에 카운트된 상태에서 cout
			return;
		}
		cnt++; //못찾아도 cnt는 ++

		if(r==R and c+1==C) // z에서 0,1
		{
			cout << cnt << '\n';
			return;
		}
		cnt++; ////못찾아도 cnt는 ++

		if(r+1==R and c==C) // z에서 1,0
		{
			cout << cnt << '\n';
			return;
		}
		cnt++; ////못찾아도 cnt는 ++

		if(r+1==R and c+1==C) // z에서 1,1
		{
			cout << cnt << '\n'; 
			return;
		}
		cnt++; ////못찾아도 cnt는 ++
		return; // 못찾고 쭉 지나갔으면 return을 해야함**** 안하면 함수가 제대로 안끝나서 재귀가 제대로 안됨.
	} 

	z_search(n/2,r,c); //큰 z에서 0,0
	z_search(n/2,r,c+n/2); // 큰 z에서 0,1
	z_search(n/2,r+n/2,c); // 큰 z에서 1,0
	z_search(n/2,r+n/2,c+n/2); // 큰 z에서 1,1
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N; // 2^N * 2^N input
	cin >> R >> C;
	z_search((1<<N),0,0); // 1<<N 은 2^N
}