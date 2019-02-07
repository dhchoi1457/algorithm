//boj 10866
//덱 구현 

#include <bits/stdc++.h>
using namespace std;
const int MX = 10000007;
int st[MX];

deque<int> D;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt;
	cin >> cnt;
	
	string S;
	while(cnt>0)
	{
		cin >> S;
		if(S=="push_front")
		{
			int tmp;
			cin >> tmp;
			D.push_front(tmp);
		}
		else if(S=="push_back")
		{
			int tmp;
			cin >> tmp;
			D.push_back(tmp);	
		}
		else if(S=="pop_front")
		{
			if(D.empty())
			{
				cout << "-1" << '\n';
			}
			else
			{
				cout << D.front() <<'\n';
				D.pop_front();
			}
		}
		else if(S=="pop_back")
		{
			if(D.empty())
			{
				cout << "-1" << '\n';
			}
			else
			{
				cout << D.back() <<'\n';
				D.pop_back();
			}
		}
		else if(S=="size")
		{
			cout << D.size() << "\n";
		} 
		else if(S=="empty")
		{
			cout << (int) D.empty() << '\n';
		}
		else if(S=="front") 
		{
			if(D.empty()){cout << -1 << '\n';}
			else{ cout << D.front() <<'\n';}
		}else // back
		{
			if(D.empty()){cout << -1 << '\n';}
			else{ cout << D.back() <<'\n';}
		}
		cnt --;
	}

	return 0;
}
