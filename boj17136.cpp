// boj 17136
// 삼성 A형 - 색종이만들기 


#include <bits/stdc++.h>
using namespace std;

int N, M;

int board[12][12];
int backup[12][12];

int ret;

void back_up(){
	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			board[y][x]=backup[y][x];
		}
	}	
}

void search(int sy, int sx, int size){
	
	int tmp;
	int ok=1;
	
	if(sy+size > N or sx+size >N) return;

	for(int y=sy; y<sy+size; y++){
		for(int x=sx; x<sx+size; x++){
			if(ok==0){tmp=0; break;}
			tmp = board[y][x];
			if(tmp==0){ok= 0; break;}
		}
		if(tmp==0) break;
	}

	if(ok==1){
		
		for(int y=sy; y<sy+size; y++){
			for(int x=sx; x<sx+size; x++){
				board[y][x]=0;
				//cout << board[y][x] <<' ';
			}
			//cout <<"??"<<'\n';
			//cout <<'\n';
		}

		//cout <<"update"<<'\n';
		// for(int y=0; y<N; y++){
		// 	for(int x=0; x<N; x++){
				
		// 		cout << board[y][x] <<' ';
		// 	}
		// 	cout <<'\n';
		// }

		ret++;
		return;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	N=10;

	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			cin >> board[y][x];
			backup[y][x] = board[y][x];
		}
	}

	ret = 0;

	//왼쪽 위 시작
	for(int size = 5; size>=1; size--){
		for(int y =0; y<N; y++){
			for(int x=0; x<N; x++){
				search(y,x,size);
			}
		}
	}


	int tmp = ret;
	//cout <<"tmp1: " << tmp <<'\n';

	ret =0;
	back_up();
	//왼쪽 아래 시작 
	for(int size = 5; size>=1; size--){
		for(int y =N-1; y>=0; y--){
			for(int x=0; x<N; x++){
				search(y,x,size);
			}
		}
	}

	tmp = min(tmp,ret);
	//cout <<"tmp2: " << tmp <<'\n';
	ret=0;
	back_up();
	//오른쪽 아래 시작 
	for(int size = 5; size>=1; size--){
		for(int y =N-1; y>=0; y--){
			for(int x=N-1; x>=0; x--){
				search(y,x,size);
			}
		}
	}

	tmp = min(tmp,ret);
	ret=0;
	back_up();

	//오른쪽 위 시작 
	for(int size = 5; size>=1; size--){
		for(int y =0; y<N; y++){
			for(int x=N-1; x>=0; x--){
				search(y,x,size);
			}
		}
	}

	tmp = min(tmp,ret);

	cout << tmp << '\n';

	return 0;
}

 