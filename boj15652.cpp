// boj15652
// N과M_4

#include <bits/stdc++.h>
using namespace std;
int n,m;

void func(int* arr, int k){ //포인터로 들어가는건, 들어가는 파라미터 자체를 계속 바꾸고 유지하기 위함.
	//현재 k개 까지 수를 택했음
	if(k==m){
		for(int i=0; i<m; i++){
			cout << arr[i]+1 << ' '; // arr에 기록해둔 수 출력. 1부터 m까지이므로 +1로 보정
		}
		cout << '\n';
		return; // 다 골랐으면 이건 끝남
	}

	int st = 0;  //이게 비 내림차순 관리용
	if(k!=0){st = arr[k-1];} // 이전에 골라놓은 숫자 이상부터 시작
	
	for(int i=st; i<n; i++){ //1부터 n까지 수에 대해 들어갈수 있는거 탐색 
		arr[k]=i; // k번째수로 i 선택
		func(arr,k+1); //k번쨰수를 정했으니, 다음수를 정하러감
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	//1~n까지의 자연수로
	// m size의 순열 만들기

	//아래 배열 두개를 전역변수로 두면 포인터 안써도 됨**

	int arr[m] = {}; // 순열이 들어갈 사이즈 m짜리 배열
	func(arr,0);

	return 0;
}


