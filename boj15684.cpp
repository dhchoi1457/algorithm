// boj 15684
// 사다리조작

#include <bits/stdc++.h>
using namespace std;

int board[32][12];

int N, M, H, ret;

bool check(){
	bool ch = true;

	//세로선 돌면서 같은 인덱스로 가나 판단 
	for(int x=1; x<=N; x++){
		int pos = x;	

		for(int y=0; y<=H; y++){
			if(board[y][pos]==1){
				pos++;
			}
			else if(board[y][pos-1]==1){
				pos--;
			}
		}
		if(pos != x) return ch= false;
	}
	return ch;
}

void dfs(int count, int y, int x){
	//cout << "dfs( " << count << ','<< y << ',' << x << ") \n";
	//cout << "ret:" <<  ret <<'\n';
	//cout << "count:" <<  count <<'\n';
	if(count >= ret) return; 
		//라인을 지금보다 더그어야되면 할필요 없음.
		//어차피 최소 라인갯수 구하는것

	if(check()){
		ret=count;
		return;
	}

	//3개인데 체크해서 안되면 걍 리턴해야함
	//최대 3개까지만 가능
	if(count ==3) return;
	//3개까지 돌았으면 다음은 4개이므로 break;

	//선긋기 dfs
	for(int i=y; i<=H; i++){
		for(int j=x; j<N; j++){
			if(board[i][j]==0 and board[i][j-1]==0 and board[i][j+1]==0){
				board[i][j]=1;
				dfs(count+1,i,j);
				board[i][j]=0;
			}
		}
		//한줄 넘어가면
		//다시 맨앞에서부터 인덱스 시작해야함
		x=1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> H;

	for(int i=0; i<M; i++){
		int a,b;
		cin >> a >> b;
		board[a][b]=1;
	}

	// // 맵테스트
	// for(int y=0; y<=H; y++){
	// 	for(int x=0; x<=N; x++){
	// 		cout << board[y][x] << ' ';
	// 	}
	// 	cout <<'\n';
	// }

	//세로선따라 돌면서 dfs
	
	ret =4;

	dfs(0,1,1);

	if(ret==4) ret = -1;
	cout << ret <<'\n';
	return 0;
}
  