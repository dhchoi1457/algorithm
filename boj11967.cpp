// boj 11967
// 불켜기

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N,M;

pair<int,int> r[102][102];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int a,b,c,d;
	for(int i=0; i<M; i++){
		cin >> a >> b;
		cin >> c >> d;
		r[a][b]={c,d};
	}

	cout << r[1][1].X << ' ' << r[1][1].Y << '\n'; 

	return 0;
} 