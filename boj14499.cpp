// boj 14499
// 주사위굴리기
// 문제에 있는 업데이트 조건 하나를 빼먹어서 오래걸리고 틀림
// 조건 잘읽자, 행번호 열번호
// if else 분기 나누는거 잘 체크, 앞에서 수정된거 떄매 뒤에 조건 안에도 들어가서 틀림  

#include <bits/stdc++.h>
using namespace std;

//동 서 북 남
const int dy[4]={0,0,-1,1};
const int dx[4]={1,-1,0,0};

int board[20][20];
int dice[7];
int N,M,K;

void move(int dir){
	//서
	if(dir == 1){
		//cout << "서" <<'\n';
		int tmp = dice[6];
		dice[6]= dice[4];
		dice[4]= dice[1];
		dice[1]= dice[3];
		dice[3]= tmp;
	}

	//동 
	else if(dir == 0){
		//cout << "동" <<'\n';
		int tmp = dice[3];
		dice[3]= dice[1];
		dice[1]= dice[4];
		dice[4]= dice[6];
		dice[6]= tmp;
	}

	//남 
	else if(dir == 3){
		//cout << "남" <<'\n';
		int tmp = dice[6];
		dice[6]= dice[5];
		dice[5]= dice[1];
		dice[1]= dice[2];
		dice[2]= tmp;
	}

	//북 
	else if(dir == 2){
		//cout << "북" <<'\n';
		int tmp = dice[2];
		dice[2]= dice[1];
		dice[1]= dice[5];
		dice[5]= dice[6];
		dice[6]= tmp;
	}

}

// void check(){
// 	for(int y=0; y<N; y++){
// 		for(int x=0; x<M; x++){
// 			cout << board[y][x] <<' ';
// 		}
// 		cout <<'\n';
// 	}	
// 	cout <<'\n';
// }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//주사위 초기화

	int sy, sx;

	cin >> N >> M;
	cin >> sy >> sx;
	cin >> K;
	
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++){
			cin >> board[y][x];
		}
	}

	//명령어 입력
	

	for(int i=0; i<K; i++){
		int cmd;
		cin >> cmd;
		cmd = cmd-1;//인덱스조절

		//좌표로 움직이는것  
		int ny = sy + dy[cmd];
		int nx = sx + dx[cmd];
		
		//OOB는 무시
		if(ny <0 or ny >= N or nx<0 or nx>=M){
			//cout << "skip ny,nx:" << ny <<"," << nx <<'\n';
			continue;
		}
		
		//주사위 굴려서 움직임 
		sy = ny;
		sx = nx;
		move(cmd);

		//cout << "board:" << board[ny][nx] <<'\n';
		if(board[ny][nx]==0){
			board[ny][nx] = dice[6];
		}
		//if(board[ny][nx]!=0){ 
		// ***이렇게하면 위에서 바꾼거 떄문에 아래로 다시들어감.. 
		else{
			dice[6]= board[ny][nx];
			board[ny][nx]=0;
		}

		//cout << "cmd : " << cmd << '\n';
		//cout << "ny, nx :" << ny <<',' << nx <<'\n';	
		//cout << "dice: "; 
		// for(int j=1; j<7; j++){
		// 	cout << dice[j] << ' ';
		// }
		//cout << '\n';
		//cout << "map:" <<'\n';
		//check();
		
		cout << dice[1] <<'\n';
		//cout <<'\n';
		//cout <<'\n';
	}

	return 0;
}