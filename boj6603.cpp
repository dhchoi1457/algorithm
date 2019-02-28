// boj6603
// 로또

#include <bits/stdc++.h>
using namespace std;
int n,m;
int now;

void va(int* arr){
	cout << "view : ";
	for(int i=0; i<6; i++ ){
		cout << arr[i] <<' ';
	}
	cout <<'\n';
}

void func(int* val, int* arr,  bool* isused, int k){

	if(k==6){
		for(int i=0; i<6; i++){
			cout << val[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	int before = now;
	for(int i=0; i<n; i++){
		if(isused[i]) continue;
		if(i<now) continue;
		isused[i]=1;
		arr[k]=i;
		now=i;
		func(val,arr,isused,k+1);
		isused[i]=0;
		now=before;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while(n!=0){
		int val[51]={};
		bool isused[51]={};
		int arr[51]={};

		for(int i=0; i<n; i++){
			cin >> val[i];
		}

		//va(val);
		func(val,arr,isused,0);

		cout << '\n'; //간격조절
		now = -1;
		cin >> n; // 다음 n 사이즈 입력, 0이면 테케 종료
	}
	// m size의 순열 만들기

	return 0;
	
}


