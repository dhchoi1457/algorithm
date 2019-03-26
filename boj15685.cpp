// boj15685
// 드래곤커브 
// 삼성전자 SW역량기출

// 알고리즘 풀이원칙1.
// 일단 인풋 아웃풋부터 파악하고,
// 인풋이 제대로 작동하는지 테스트할것

// 2. 그다음 펜들고 풀이 방법을 고민해본다.
// 규칙만 찾으면 의외로 쉬운 문제가 만핟.

// 3. 적절한 자료 구조를 활용하자. 큐든 스택이든 배열이든.

// 4. 지레 겁먹지말고일단 짜보자. 컴터 안터진다.

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

//처음에 오른쪽,
//그다음에 계속 
const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};

int board[102][102]={0,};

int N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0; i<N; i++){

		int curve_size =0;
		int curve[1024]={0,};
		
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		
		curve[curve_size++]= d; // curve 방향기록
		board[y][x]=1;

		//드래곤커브 세대 업데이트
		for(int j=0; j<g; j++){
			//스택처럼 역순으로, 방향은 90도 회전
			for(int k=curve_size-1; k>=0; k--){ 	
				curve[curve_size++] = (curve[k]+1)%4;
			}
		}

	 	//드래곤커브 기반으로 맵 업데이트
	 	for(int j=0; j<curve_size; j++){
	 		x+=dx[curve[j]];
	 		y+=dy[curve[j]];

	 		if(x<0 or x>=101 or y<0 or y>=101) continue;

	 		board[y][x]=1;
	 	}

	}

	//드래곤 커브별로 맵에 다 그리고 나서
	//사각형 갯수 세기

	int ret=0;

	for(int y=0; y<100; y++){
		for(int x=0; x<100; x++){
			if(board[y][x]==1 and board[y][x+1]==1 and board[y+1][x]==1 and board[y+1][x+1]==1) ret++;
		}
	}

	cout << ret << '\n';
	return 0;
}



 