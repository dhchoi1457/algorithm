//boj 1406
//에디터

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> L = {};
	string init;
	cin >> init;

	for(auto s:init){L.push_back(s);}
	auto cursor = L.end(); // 커서는 일단 입력의 맨 끝네서 시작. STL vector는 단순 int 형태가 아님. 포인터같은 느낌
	int Q; // 명령어 갯수
	cin >> Q;

	string op;
	getline(cin,op);
	
	while(Q--)
	{
		getline(cin,op);
		//cout << op << '\n';
		switch(op[0])
		{
			case 'P':
				L.insert(cursor,op[2]);
				break;
			case 'L':
				if(cursor!=L.begin()){cursor--;}
				break;
			case 'D':
				if(cursor!=L.end()){cursor++;}
				break;
			case 'B':
				if(cursor!=L.begin())
				{
					cursor--;
					cursor = L.erase(cursor);
				}
				break;
			default: cout << "Check error" << '\n';
				break;
		}
	} // while 문 끝

	for(auto a:L){cout << a;}

	return 0;
}
