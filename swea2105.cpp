//SWEA 2105. 디저트카페

// 상하좌우로 이동이 가능한지만 체크할수있으면,
// 단순 bfs

// 진행방향이 대각선 사각형이다
// --> dir을 선택할떄, 현재랑 같은 방향이거나, 사각형을 이루는 다음방향만 진행가능
// --> 끝날때는 반드시 사각형을 이뤄야함
// visited 체크
// 디저트 종류 체크 

#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second



const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};
	// up 0
	// right 1
	// down 2
	// left 3


int board[52][52];
int dist[52][52];


int N; // 맵너비 

int ans; //answer

int visited[101]; //desert방문여부 체크용 

void visited_clear(){
	for(int i=0; i<101; i++){
		visited[i]= 0;
	}
}

//처음시작시 초기화
void init(){
	visited_clear();
	ans = -1;
}

void solve(){
	//y,x에서 탐색시작, 시계방향으로 영역 구함(시계나 반시계나 동일)
	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){

			//사각형 변의길이 세팅 a,b
			for(int a=1; a<=N; a++){
				for(int b=1; b<=N; b++){
					//ans는 현재까지 제일 많이 먹을수있는 디저트갯수 젖아
					//OOB를 확인,
					//현재 둘레가 ans보다 작으면 진행안함. 어차피 작음(중복값 안되므로)
					

					//범위 왜 이렇게 잡는지 좀 헷갈리네
					if(x+a <= N-1 // 오른쪽 범위 
						and y+a+b <= N-1 // 아래범위 
						and x-b >=0 //왼쪽 범위
						and (a+b)*2 > ans )//지금까지 구했던거보다 커야 진행 
					{	
						visited_clear();
						bool able =true;

						int cur_y = y;
						int cur_x = x;

						//우측하단 확인
						for(int n=0; n<a; n++){
							cur_y++;
							cur_x++;

							//먹지않은 간식이면 먹었다고 표시
							if(visited[board[cur_y][cur_x]]!=1){visited[board[cur_y][cur_x]]=1;}
							else{
								//먹은거면 불가. 빠개고 담꺼 진행 
								able = false;
								break;
							}
						}
						if(able==false) continue; 

						// 좌측 하단 확인 
						for(int n=0; n<b; n++){
							cur_y++;
							cur_x--;

							//먹지않은 간식이면 먹었다고 표시
							if(visited[board[cur_y][cur_x]]!=1){visited[board[cur_y][cur_x]]=1;}
							else{
								//먹은거면 불가. 빠개고 담꺼 진행 
								able = false;
								break;
							}
						}
						if(able==false) continue; 

						//좌측 상단 확인 
						for(int n=0; n<a; n++){
							cur_y--;
							cur_x--;

							//먹지않은 간식이면 먹었다고 표시
							if(visited[board[cur_y][cur_x]]!=1){visited[board[cur_y][cur_x]]=1;}
							else{
								//먹은거면 불가. 빠개고 담꺼 진행 
								able = false;
								break;
							}
						}
						if(able==false) continue; 


						//우측 상단 확인 
						for(int n=0; n<b; n++){
							cur_y--;
							cur_x++;

							//먹지않은 간식이면 먹었다고 표시
							if(visited[board[cur_y][cur_x]]!=1){visited[board[cur_y][cur_x]]=1;}
							else{
								//먹은거면 불가. 빠개고 담꺼 진행 
								able = false;
								break;
							}
						}
						if(able==false) continue; 

						//살아남았으면 최대 갯수인것
						ans = 2*(a+b);

					}
				}
			}

		}
	}

}




int main()
{
	int testnum;
	cin >> testnum;

	for(int k=1; k<=testnum; k++)
	{

		init();
		cin >> N;

		for(int y=0; y<N; y++){
			for(int x=0; x<N; x++){
				cin >> board[y][x];
			}
		}

		solve();

		cout << "#" << k << " " << ans <<'\n';
	}

	return 0;
}