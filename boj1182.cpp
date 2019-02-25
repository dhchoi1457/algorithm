// boj 1182
// 부분집합의 합

// 각 부분집합의 합을 구하면 됨
// 이걸 이진수로 표현하면 
// 1~2^n까지의 표기중에
// 특정 원소가 포함되어있는지를 0, 1로 표시
// 0이면 이 부분집합에는 안들어가있는거고,
// 1이면 들어가있는것.  

#include <bits/stdc++.h>
using namespace std;
int n,s;
int cnt = 0;
int a[24];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for(int i=0; i<n; i++)
		cin >> a[i];

	for(int i=1; i<(1<<n); i++){ // 1<<n = 2^n, 
		//공집합이 아닌 부분집합에 대한 것이므로 i=1부터
		int tmp = i;
		int tot = 0;

		for(int j=0; j<n; j++){
			if(tmp%2==1) tot += a[j]; 
			tmp/=2;
		}
		if(tot==s) cnt++;
	}

	cout << cnt << '\n';
	return 0;
}
