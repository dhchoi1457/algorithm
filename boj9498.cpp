//boj 9498 
//시험성적

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	auto g=0;
	cin >> g;

	if(g/10 >= 9)
	{
		cout << 'A' << '\n';
	}
	else if(g/10>=8)
	{
		cout << 'B' << '\n';
	}
	else if(g/10>=7)
	{
		cout << 'C' << '\n';
	}
	else if(g/10>=6)
	{
		cout << 'D' << '\n';
	}
	else{cout << 'F'<< '\n';}

	return 0;
}
