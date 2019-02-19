// boj 1074
// 별찍기_10
// https://dhpark.kr/entry/BOJ-2447-%EB%B3%84%EC%B0%8D%EA%B8%B0-10 참고
// 복습할것.
// 1/3사이즈에 맞추어 계속 탐색을 해간다.
// 1/3 사이즈에 맞추었으므로, 탐색시 사이즈를 맞춰 갱신한다.


#include <bits/stdc++.h>
using namespace std;

const int N = 3000; //이것도 사이즈에 따라 답이 틀렸다 맞았다 하네..
// 내 코드스타일에 뭐 연관이 있는듯
// 이거떄매 틀리면 진짜 억울하겠다. 고치자 

int n;
bool star[N][N];

void st(int, int, int);

int main() {
  cin >> n;

  st(n, 0, 0);
  
  for (int i=0; i<n; i++) {
    for (int j=0; j<=n; j++) {
    	if(star[i][j]!=true){cout <<' ';}
    	else{cout<<'*';}
    }
    cout<<'\n';
  }
  return 0;
}

void st(int n, int x, int y) {
  if (n == 1) {
    star[x][y] = true;
    return;
  }
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (i == 1 && j == 1) continue;
      st(n/3, x + (n/3)*i, y + (n/3)*j); 
      // 9등분하면, N(가로 세로 길이)는 1/3로 줄어들고,
      // 나머지 9영역에 대해 i,j로 로테이션
      // 가운데 영역 제외
    }
  }
}