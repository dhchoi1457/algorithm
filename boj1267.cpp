
//boj 1267
//핸드폰 요금 

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	auto num =0, tmp=0, Y=0, M=0;

	cin >> num;
	for (int i=0; i<num; i++)
	{
		cin >> tmp;
		Y+=(tmp/30 +1)*10;
		M+=(tmp/60 +1)*15;
	}

	if(Y>M){cout << "M "<< M << '\n';}
	if(Y<M){cout << "Y "<< Y << '\n';}
	if(Y==M){cout << "Y M "<< M << '\n';}

	return 0;
}
