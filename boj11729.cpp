//boj 11729
// 하노이 탑 이동순서 

#include <bits/stdc++.h>
using namespace std;

int N;
int cnt=0;

void hanoi(int a, int b, int n){

	//1개 옮길떄는 걍 옮기면 됨
	if(n==1){
		cout << a << ' ' << b<<'\n';
		cnt++;
		return; // else가 아니라 return으로 끝내기 
	} 
	int c = 6-a-b; // a,b외의 다른 판 위치(판 3개 순서대로 1 2 3 하면 총합 6이니까 )
	//여러개 옮길때는 무조건 출발지, 목적지 외의 1개 경유. 그게 c판
	hanoi(a,c,n-1);
	hanoi(a,b,1);
	hanoi(c,b,n-1);

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N; //원판 갯수 
	cout <<(1<<N)-1<<'\n'; // 2의 n승 -1 
	hanoi(1,3,N);
	return 0;
}