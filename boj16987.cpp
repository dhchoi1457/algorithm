// boj 16987
// 계란으로 계란치기 
// 풀이는 갓킹독님 소스 참고 https://www.acmicpc.net/source/share/550e5f94d9504613971281134eebaeae

// self 피드백
// good : 거의 모든 로직이 풀이와 비슷.

// 개선해야할 점 
// 1. 함수에 대한 문제 정의가 애매함.
// - 그냥 풀다보니 어느정도 가닥은 잡혔지만,
//   이게 정확하게 어떠한 상황에서 어떻게 작용하는지가 부족함.
//   내가 만든 함수의 인자가 정확하게 무얼 의미하는지를 알아야한다.
// - 내구도와 무게가 계속 헷갈리는데, 이걸 다른 변수 배열로 각각 잡아버리면 덜헷갈린다.

// 2. 불필요한 요소들이 존재 
//  - 깨진 것을 체크하는 변수는 필요가 없다. 왜냐면 내구도가 0이하인지만 보면 되므로.
// 3. 백트래킹이 제대로 안되었던 이유는 for문 안에 존재하지 않아야할 재귀가 있어서..
// continue꺼 다음에 나오는 재귀가 제대로 백트래킹을 안먹음



#include <bits/stdc++.h>
using namespace std;


int n;
int s[10];
int w[10];
int mx=0;
int cnt=0;

void solve(int a){ // 현재 a번째 계란을 손에 쥐고 있다.
	if(a == n){
		mx = max(mx,cnt);
		return;
	}

	if(s[a]<=0 or cnt == n-1){ //현재 손에 있는 계란이 꺠져있거나, 나머지 계란이 전부 꺠져있는 경우 다음으로 넘어간다.
		solve(a+1);
		return;
	}

	for(int t=0; t<n; t++){
		if(t==a or s[t]<=0) continue; //나랑 같은거 or 깨져있는거 스킵
		
		s[a] -= w[t];
		s[t] -= w[a];
		if(s[a] <= 0){cnt++;}
		if(s[t] <= 0){cnt++;}
		
		solve(a+1);
		
		//백트래킹 
		// 백트래킹시에 다른 변수를 써서 백트래킹해주면
		// 그 변수가 계속 다른 값으로 선언되어서 꼬이는듯
		if(s[a]<=0){cnt--;}
		if(s[t]<=0){cnt--;}
		s[a] += w[t];
		s[t] += w[a];		
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> s[i] >> w[i];
	}

	//제일 왼쪽에 있는거부터 돌아가면서 들고 계란깨기를 시도한다.
	//이미 깨져있는건 넘긴다.

	//0번쨰 계란부터 손에 쥐고 계란치기를 시도
	solve(0);
	cout << mx;
	return 0;
}
