// boj1759
// 암호

#include <bits/stdc++.h>
using namespace std;
int L,C;
int mo, ja; // 자음모음 갯수 체크용
int now = -1; // 나보다 큰것만 사용가능 

char val[17];

void check_arr(char* arr){
	cout << "view : ";
	for(int i=0; i<6; i++ ){
		cout << arr[i] <<' ';
	}
	cout <<'\n';
}

void func(int* arr, bool* isused, int k){
	if(k==L and mo>=1 and ja>=2){
		for(int i=0; i<k; i++){
			cout << val[arr[i]];
		}
		cout << '\n';
		return;
	}

	int before = now;
	for(int i=0; i<C; i++){
		if(isused[i] or i<now) continue;
		arr[k] = i;
		now = i;
		if(val[i] == 'a' or val[i] == 'e' or val[i] == 'i' or val[i] == 'o' or val[i] == 'u' ){
			mo++;
		}else{
			ja++;
		}
		isused[i]=1;
		func(arr,isused,k+1);
		if(val[i] == 'a' or val[i] == 'e' or val[i] == 'i' or val[i] == 'o' or val[i] == 'u' ){
			mo--;
		}else{
			ja--;
		}
		isused[i]=0;
		now = before;
	}

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;

	for(int i=0; i<C; i++){
		cin >> val[i];
		//cout << arr[i] << ' '; //input 체크
	}

	//암호길이는 최소 3,
	// 모음 1개이상, 자음 2개 이상 
	mo = 0;
	ja = 0;

	sort(val,val+C); //사전순으로 정렬
	//check_arr(arr) 정렬 체크

	bool isused[17]={};
	int arr[17]={};

	//가자 백트래킹
	func(arr,isused,0);
	return 0;
	
}


