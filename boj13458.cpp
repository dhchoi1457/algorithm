// boj 13458
// 시험감독
// 자료형범위 조심

#include <bits/stdc++.h>
using namespace std;

long long  N, B, C;
long long A[2000002];
long long ret;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; //시험장 갯수 

	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	cin >> B >> C;


	ret =0;
	for(int i=0; i<N; i++){
		long long tmp=A[i];
		tmp = tmp - B; //정감독관 보는수 빼기
		ret++;
		if(tmp <=0 ) continue; 
		if(tmp >0){
			if(tmp%C ==0){
				ret = ret + tmp/C;
			}else{
				ret = ret + (tmp/C +1);
			}
		}
	}
	cout << ret <<'\n';


	return 0;
}
  