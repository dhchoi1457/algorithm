//boj 2490
//윷놀이

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	auto count=4, tmp =0;
	
	for(int i=0; i<3; i++)
	{
		for(int j =0; j<4; j++)
		{
			cin >> tmp;
			count -= tmp;
		}

		switch(count)
		{
			case 0:
				cout << 'E' << '\n';
				break;
			case 1: 
				cout << 'A' << '\n';
				break;
			case 2:
				cout << 'B' << '\n';
				break;
			case 3: 
				cout << 'C' << '\n';
				break;
			case 4:
				cout << 'D' << '\n';
				break;
			default:
				cout << "error" << '\n';
				break;
		}

		count =4;
	}

	return 0;
}
