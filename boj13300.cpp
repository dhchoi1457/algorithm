// boj 13300
// 수학여행

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, K;

int arr[2][7];

int cnt;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	int cnt = 0;

	for(int i=0; i<2; i++){
		fill(arr[i],arr[i]+7,0);
	}

	for(int i=0; i<N; i++){
		int y,s;
		cin >> s >> y;
		//새로 방 파는 경우1
		if(arr[s][y]==0){
			arr[s][y]=1;
			cnt++;
		}

		else if(arr[s][y]==K){
			arr[s][y]=1;
			cnt++;
		} 

		else{
			arr[s][y]++;
		}

		//cout << "s,y / cnt:" << s << ',' << y << " / " << cnt << '\n';
	}

	cout << cnt << '\n';


	return 0;
} 