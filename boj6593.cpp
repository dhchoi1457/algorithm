// boj 6593
// 상범빌딩

#include <bits/stdc++.h>
using namespace std;

int L,R,C;

string board[32][32]; // L R

//3-dim movement
int dx[6]={1,0,0,-1,0,0};
int dy[6]={0,1,0,0,-1,0};
int dz[6]={0,0,1,0,0,-1};

int sl, sr, sc;
int el, er, ec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> R >> C; 

	// L : 상범빌딩 층수
	// R : 한 층의 row
	// C : 한 층의 column
	while(L!=0 and R!=0 and C!=0){

		for(int i=0; i<L; i++){
			for(int j=0; j<R; j++){
				cin >> board[i][j];
				
				for(int k=0; k<C; k++){
					if(board[i][j][k]=='S'){sl=i; sr=j; sc=k;}
					if(board[i][j][k]=='E'){el=i; er=j; ec=k;}
				}
			}	
		}

		cout << sl << ' ' << sr << ' ' << sc <<'\n';
		cout << el << ' ' << er << ' ' << ec <<'\n';
	}


	cout << "use the stairs" << '\n';
	return 0;
} 