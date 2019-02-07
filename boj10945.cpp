//boj 10845
//큐 구현 

#include <bits/stdc++.h>
using namespace std;
const int MX = 10000007;
int st[MX];

queue<int> Q;


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
		if(S=="push")
		{
			int tmp;
			cin >> tmp;
			Q.push(tmp);
		}
		else if(S=="pop")
		{
			if(Q.empty())
			{
				cout << "-1" << '\n';
			}
			else
			{
				cout << Q.front() <<'\n';
				Q.pop();
			}
		}
		else if(S=="size")
		{
			cout << Q.size() << "\n";
		} 
		else if(S=="empty")
		{
			cout << (int) Q.empty() << '\n';
		}
		else if(S=="front") 
		{
			if(Q.empty()){cout << -1 << '\n';}
			else{ cout << Q.front() <<'\n';}
		}else // back
		{
			if(Q.empty()){cout << -1 << '\n';}
			else{ cout << Q.back() <<'\n';}
		}
		cnt --;
	}

	return 0;
}
