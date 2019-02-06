// boj 2577
// 숫자 세기  --> 배열을 활용
//

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c;
	int result;
	cin >> a >> b >> c;
	result = a*b*c;

	string S;
	S= to_string(result);
	
	int A[10]={};
	int tmp;
	
	for(int i=0; i<S.size(); i++){
		tmp = (int) S[i]-'0';
		A[tmp]++; 
	}

	for(int i=0; i<10; i++){
		cout << A[i] << '\n';
	}
	return 0;
}
