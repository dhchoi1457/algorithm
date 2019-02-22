// boj9466
// 텀프로젝트 
// cycle을 찾아내는 문제이므로 대부분 stack을 쓰는듯
// 후.. 여기서 삽질을 많이했으므로, 일단 skip..ㅠㅜ
// 추후에 다시풀기
// https://barefoot-coder.tistory.com/71
// fig 10에서 4 7 6이 사이클이 생기는데 왜 4 7 6이 다 사이클 구성원으로 인정받는지 몰랐는데,
// 4 -> 7 > 6-> 4-> 7-> 6 한바퀴 더돌면서 check를 갱신함.
// https://blog.encrypted.gg/499 참고함

#include <bits/stdc++.h>
using namespace std;

int board[100005];

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

 		int state[N];
 		fill(state,state+N,0); // 상태 체크 -1이면 팀소속, 0이면 아직 방문X, else 방문O,팀X
 		fill(board+1,board+N+1,0); // 상태 체크 -1이면 팀소속, 0이면 아직 방문X, else 방문O,팀X
 		for(int n=1; n<=N; n++) // 주어진 학생들의 순서
 			cin >> board[n];

 		for(int i=1; i<=N; i++){
 			if(state[i]!=0) continue;
 			int cur =i;
 			state[cur]=i;
 			
 			while(true){
 				cur = board[cur];
 				if(state[cur]==i){
 					state[cur]=-1; // 팀소속
 					int tmp = board[cur];
 					while(tmp!=cur){
 						state[tmp]=-1;
 						tmp=board[tmp];
 						//cnt++; // 이렇게 하면 돌다보니 중복 작업하는 부분이 생김, 그래서 마지막 -1 따로 체크 
 					}
 					break;
 				}
 				if(state[cur]==0){
 					state[cur]=i;
 					continue;
 				}else break;
 			}

		}		
		int cnt=N;
		for(int n=1; n<=N; n++){
			//cout << "n:state[n]" << n <<' ' << state[n] <<'\n';
			if(state[n]==-1){
				cnt--;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}


