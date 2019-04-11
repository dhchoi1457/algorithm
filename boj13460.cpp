// boj 13460
// 구슬탈출2

#include <bits/stdc++.h>
using namespace std;

string board[12];

int N, M;

struct POSI{
	int y,x;
};

POSI red;
POSI blue;

const int dy[4]= {-1,0,1,0};
const int dx[4]= {0,1,0,-1};

bool red_out=false;
bool blue_out=false;

int ret;

void check(){
	for(int y=0; y<N; y++){
		cout << board[y] <<'\n';
	}
}

void move(int dir){

	bool is_update = true;

	while(is_update){
		//cout<< "moving.." <<'\n'; 
		is_update=false;

		//red move
		while(1){
			int ry = red.y;
			int rx = red.x;
			//cout<< "red moving.." <<'\n'; 
			//check();
			//cout <<"ry, rx" << ry << ',' << rx <<'\n';
			ry = ry + dy[dir];
			rx = rx + dx[dir];
			//cout <<"next ry, rx" << ry << ',' << rx <<'\n'; 
			if(ry<0 or ry>=N or rx<0 or rx>=M ) break;
			if(board[ry][rx]=='#') break;
			if(board[ry][rx]=='B') break;
			if(board[ry][rx]=='O'){
				red_out= true; 
				board[red.y][red.x]='.';
				red.y= ry;
				red.x= rx;
				//is_update=false;
				break;
			}
			board[red.y][red.x]='.';
			red.y= ry;
			red.x= rx;
			board[red.y][red.x]='R';
			is_update=true;

		}

		//blue move
		while(1){
			int by = blue.y;
			int bx = blue.x;
			//cout<< "blue moving.." <<'\n'; 
			//check();
			//cout <<"by, bx" << bx << ',' << by <<'\n';
			by = by + dy[dir];
			bx = bx + dx[dir]; 
			//cout <<"next  by, bx" << bx << ',' << by <<'\n';
			if(by<0 or by>=N or bx<0 or bx>=M ) break;
			if(board[by][bx]=='#') break;
			if(board[by][bx]=='R') break;
			if(board[by][bx]=='O'){
				blue_out= true; 
				board[blue.y][blue.x]='.';
				blue.y=by;
				blue.x=bx;
				//is_update=false;
				break;
			}		
			board[blue.y][blue.x]='.';
			blue.y=by;
			blue.x=bx;
			board[blue.y][blue.x]='B';
			is_update=true;	
		}
	}
	//check();
}


void dfs(int count, int bd){
	if(count >= ret ) return;
	if(blue_out) return;
	if(red_out){
		ret = count;
		return;
	}
	string backup[12];
	
	for(int y=0; y<N; y++){
		backup[y]=board[y];
	}
	bool tr = red_out;
	bool tb = blue_out;
	for(int dir=0; dir<4; dir++){
		if(dir==bd) continue;
		move(dir);
		dfs(count+1, dir);
		
		//백트래킹
		for(int y=0; y<N; y++){
			board[y]=backup[y];

			//red, blue 위치를 백트래킹 해줘야함... 이걸로 1시간날렸네 하하
			for(int x=0; x<M; x++){
				if(board[y][x]=='B'){
					blue.y=y;
					blue.x=x;
				}
				if(board[y][x]=='R'){
					red.y=y;
					red.x=x;
				}
			}
		}
		red_out = tr;
		blue_out = tb;
		//cout<<'\n';
	}

}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	

	for(int y=0; y<N; y++){
		cin >> board[y];
		for(int x=0; x<M; x++){
			if(board[y][x]=='B'){
				blue.y=y;
				blue.x=x;
			}
			if(board[y][x]=='R'){
				red.y=y;
				red.x=x;
			}
		}
	}

	// cout << blue.y << ',' << blue.x <<'\n';
	// cout << red.y << ',' << red.x <<'\n';
	
	
	//판기울이기 시뮬레이션 구현 move

	// check();
	// move(1);
	// cout<<'\n';
	// cout << red_out <<'\n';
	// check();

	ret =11;

	dfs(0,-100);

	if(ret == 11) ret=-1;
	cout << ret <<'\n';

	return 0;
}
  