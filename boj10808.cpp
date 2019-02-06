
//boj 10808
//알파벳 갯수 세기

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	int freq[26] = {}; // 이러면 0으로 초기화?
	for(auto s:S)
	{
		freq[s-'a']+=1;
	}


	for(int i=0; i<26; i++)
	{
		cout << freq[i]<<' ';
	}

	return 0;
}
