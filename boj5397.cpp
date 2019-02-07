//boj 5397
//키로거

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int count;
	cin >> count;

	while(count >0)
	{
		list<char> L = {};
		string init;
		cin >> init;
		//for(auto s:init){L.push_back(s);}
		auto cursor = L.begin(); // 커서는 일단 입력의 맨 처음서 시작. STL vector는 단순 int 형태가 아님. 포인터같은 느낌
		int Q = init.size();
		for(int i=0; i < Q; i++)
		{
			switch(init[i])
			{
				case '<':
					if(cursor!=L.begin()){cursor--;}
					break;
				case '>':
					if(cursor!=L.end()){cursor++;}
					break;
				case '-':
					if(cursor!=L.begin())
					{
						cursor--;
						cursor = L.erase(cursor);
					}
					break;
				default : L.insert(cursor,init[i]);
			}
		}
		for(auto a:L){cout << a;}
		cout << '\n';
		count--;
	}

	return 0;
}
