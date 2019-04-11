	// boj 14500
	// 테트로미노
	#include <bits/stdc++.h>
	using namespace std;

	int board[502][502];
	int visited[502][502]={0,};
	int N, M;

	const int dy[4] ={-1,1,0,0};
	const int dx[4]={0,0,1,-1};
	int ret;

	bool OOB(int y, int x){
		return(y<0 or y>=N or x<0 or x<=M);
	}

	void dfs(int y, int x, int dep, int sum){
		if(dep==4){
			if(sum > ret) ret=sum;
			//cout <<"end~~ sum: "<<sum << ", ret:" <<ret <<'\n';
			return;
		}

		for(int dir=0; dir<4; dir++){
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if(ny<0 or ny>= N or nx<0 or nx>=M) continue;
			if(visited[ny][nx]==1) continue;

			visited[ny][nx]=1;
			//cout <<"ny,nx, board[ny][nx]" << ny <<',' << nx <<',' << board[ny][nx] <<'\n';
			dfs(ny,nx,dep+1,sum+board[ny][nx]);
			visited[ny][nx]=0;
		}
	}

	void T_search(int y, int x){

		if(OOB(y,x) and OOB(y,x+1) and OOB(y,x+2) and OOB(y-1,x+1)){
			int ans = board[y][x] + board[y][x+1] + board[y][x+2] + board[y-1][x+1]; 
			if(ans>ret) ret=ans;
		}

		if(OOB(y,x) and OOB(y,x+1) and OOB(y,x+2) and OOB(y+1,x+1)){
			int ans = board[y][x] + board[y][x+1] + board[y][x+2] + board[y+1][x+1]; 
			if(ans>ret) ret=ans;
		}

		if(OOB(y,x) and OOB(y,x+1) and OOB(y-1,x+1) and OOB(y+1,x+1)){
			int ans = board[y][x] + board[y][x+1] + board[y-1][x+1] + board[y+1][x+1]; 
			if(ans>ret) ret=ans;
		}


		if(OOB(y,x) and OOB(y-1,x) and OOB(y+1,x) and OOB(y,x+1)){
			int ans = board[y][x] + board[y-1][x] + board[y+1][x] + board[y][x+1]; 
			if(ans>ret) ret=ans;
		}

		// case 1
		// y,x
		// y,x+1
		// y-1,x+1;
		// y,x+2


		return;
	}

	int main(){
		ios::sync_with_stdio(0);
		cin.tie(0);

		cin >> N >> M;

		for(int y=0; y<N; y++){
			for(int x=0; x<M; x++){
				cin >> board[y][x];
				//cout << board[y][x] << ' ';
			}
			//cout <<'\n';
		} 

		ret = -1e7;
		
		//그냥 depth 4짜리 dfs
		for(int y=0; y<N; y++){
			for(int x=0; x<M; x++){
			//cout << "*******************start : " << y << ',' << x << ',' << board[y][x] <<'\n';
			visited[y][x]=1;
			dfs(y,x,1,board[y][x]);
			T_search(y,x);
			visited[y][x]=0;
			}
		}


		cout << ret <<'\n';
		//T search

		return 0;
	}
	 