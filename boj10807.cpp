
//boj 10807
//개수 세기

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num, n, index;
	cin >> num;
	int freq[201] = {}; // 이러면 0으로 초기화?
	for(int i=0; i<num; i++)
	{
		cin >> n; 
		freq[n+100]++;
	}

	cin >> index;
	cout << freq[index+100]<<'\n';

	return 0;
}
