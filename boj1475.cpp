//boj 1475
//방번호

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	int a[10];
	fill_n(a,10,1); // 1로 초기화 
	a[9]++; // 6, 9는 9로 통일
	a[6]--;

	int count=1;

	int tmp; // 입력 숫자 체크용 

	for(auto s:S)
	{
		tmp = s - '0';
		if(tmp ==6){tmp=9;}

		if(a[tmp]<1)
		{

			count++;
			for(int i=0; i<10; i++)
			{
				a[i]++;
			}
			a[9]++;
			a[6]--;
		}
		a[tmp]--;
	}

	cout << count << '\n';

	return 0;
}
