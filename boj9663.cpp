// boj 9663
// N-Queen

#include <bits/stdc++.h>
using namespace std;
int N;
int cnt=0;

bool isused1[16]; // 열 체크용 
bool isused2[32]; // 오위 왼아래 대각선 체크용 
bool isused3[32]; // 왼위 오아래 대각선 체크용 

void func(int cur){ // cur번째 row에 말을 놓을것
	if(cur==N){
		cnt++; 
		return;
	}

	for(int i=0; i<N; i++){ // cur,i에 퀸을 놓으려고함
		if(isused1[i] or isused2[i+cur] or isused3[cur-i+N]){
			//세 조건중에 하나라도 걸리면 그자리에 퀸 못놓음
			continue;
		}

		//cur,i에 퀸을 놓는다.
		isused1[i]=1;
		isused2[cur+i]=1;
		isused3[cur-i+N]=1;

		func(cur+1); // 다음 row 진행
		
		//cur i+1에 퀸을 놓으려면, 다시 백트래킹해야함
		isused1[i]=0;
		isused2[cur+i]=0;
		isused3[cur-i+N]=0;

	}	

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	func(0);
	cout << cnt << '\n';
	return 0;
}


