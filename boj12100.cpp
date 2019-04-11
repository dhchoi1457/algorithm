// boj12100
// 2048 easy

#include <bits/stdc++.h>
using namespace std;



const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};


int N;
int board[22][22];
int updated[22][22];

int ret;

int search_max(){
	int maxx=-1;
	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			if(board[y][x] > maxx) maxx = board[y][x];
		}
	}	
	return maxx;
}

void move(int dir){
	//updated 초기화
	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			updated[y][x]=0;
		}
	}

	if(dir==0){//위로 합치기
		//1번쨰줄 부터 
		int is_update = true;
		while(is_update){
			is_update = false;

			for(int y=1; y<N; y++){
				for(int x=0; x<N; x++){
					if(board[y][x]==0) continue;
					
					if(board[y-1][x]==0){
						board[y-1][x]= board[y][x];
						board[y][x]=0;
						is_update= true;
					}


					if(updated[y][x]==0 and updated[y-1][x]==0 and board[y][x]==board[y-1][x]){
						board[y-1][x] = 2*board[y][x];
						board[y][x]=0;
						updated[y-1][x]=1;
						is_update= true;			
					}
				}
			}
		}		
	}

	if(dir==2){//아래로 합치기
		//1번쨰줄 부터 
		int is_update = true;
		while(is_update){
			is_update = false;

			for(int y=N-2; y>=0; y--){
				for(int x=0; x<N; x++){
					if(board[y][x]==0) continue;
					
					if(board[y+1][x]==0){
						board[y+1][x]= board[y][x];
						board[y][x]=0;
						is_update= true;
					}


					if(updated[y][x]==0 and updated[y+1][x]==0 and board[y][x]==board[y+1][x]){
						board[y+1][x] = 2*board[y][x];
						board[y][x]=0;
						updated[y+1][x]=1;
						is_update= true;			
					}
				}
			}
		}		
	}

	if(dir==1){//왼쪽으로 합치기
		//1번쨰줄 부터 
		int is_update = true;
		while(is_update){
			is_update = false;

			for(int x=N-2; x>=0; x--){
				for(int y=0; y<N; y++){
					if(board[y][x]==0) continue;
					
					if(board[y][x+1]==0){
						board[y][x+1]= board[y][x];
						board[y][x]=0;
						is_update= true;
					}


					if(updated[y][x]==0 and updated[y][x+1]==0 and board[y][x]==board[y][x+1]){
						board[y][x+1] = 2*board[y][x];
						board[y][x]=0;
						updated[y][x+1]=1;
						is_update= true;			
					}
				}
			}
		}		
	}

	if(dir==3){//오른쪽으로 합치기
		//1번쨰줄 부터 
		int is_update = true;
		while(is_update){
			is_update = false;

			for(int x=1; x<N; x++){
				for(int y=0; y<N; y++){
					if(board[y][x]==0) continue;
					
					if(board[y][x-1]==0){
						board[y][x-1]= board[y][x];
						board[y][x]=0;
						is_update= true;
					}


					if(updated[y][x]==0 and updated[y][x-1]==0 and board[y][x]==board[y][x-1]){
						board[y][x-1] = 2*board[y][x];
						board[y][x]=0;
						updated[y][x-1]=1;
						is_update= true;			
					}
				}
			}
		}		
	}

}

void check(){
	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			cout <<  board[y][x] << ' ';
		}
		cout <<'\n';
	}	
	cout<<'\n';
}


void dfs(int count){
	if(count == 5){
		//search max find;
		int candi;
		candi = search_max();
		if(candi > ret) ret =candi;

		return;
	}

	//map backup
	int backup[22][22];
	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			backup[y][x] = board[y][x];
		}
	}	

	for(int dir=0; dir<4; dir++){

		move(dir);
		dfs(count+1);
		
		for(int y=0; y<N; y++){
			for(int x=0; x<N; x++){
				board[y][x]=backup[y][x];
			}
		}	
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			cin>> board[y][x];
		}
	}
	
	ret= -1;

	dfs(0);

	//move(3);
	//move(3);
	//move(2);
	//check();
	cout << ret <<'\n';
}