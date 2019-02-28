// boj15656
// N과M_7
// 백트래킹

// 수열의 숫자가 별도로 주어짐
// 중복허용

#include <bits/stdc++.h>
using namespace std;
int n,m;
int val[10];
int now = -1;

void func(int* arr, int k){ //포인터로 들어가는건, 들어가는 파라미터 자체를 계속 바꾸고 유지하기 위함.
	//현재 k개 까지 수를 택했음
	if(k==m){
		for(int i=0; i<m; i++){
			cout << val[arr[i]] << ' '; // arr에 기록해둔 수 출력. 1부터 m까지이므로 +1로 보정
		}
		cout << '\n';
		return; // 다 골랐으면 이건 끝남
	}

	int before = now;
	//아직 더 고를 수가 있다면 
	for(int i=0; i<n; i++){ //1부터 n까지 수에 대해 들어갈수 있는거 탐색 
		
		arr[k]=i; // k번째수로 i 선택
		now = i;
		func(arr,k+1); //k번쨰수를 정했으니, 다음수를 정하러감
		now = before;
		//k번째 수를 i로 정한거에 대해선 다 탐색했으니, 다시 복원후 다음 반복문으로 넘어감
		
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	// m size의 순열 만들기

	for(int l=0; l<n; l++){
		cin >> val[l];
	}

	sort(val,val+n);
		

	//아래 배열 두개를 전역변수로 두면 포인터 안써도 됨**

	int arr[m] = {}; // 순열이 들어갈 사이즈 m짜리 배열

	func(arr, 0);

	return 0;
	
}


