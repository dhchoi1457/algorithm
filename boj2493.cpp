//boj 2493
// 탑

#include <bits/stdc++.h>
using namespace std;

stack<pair<int,int>> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int now;
	for(int i =1; i<=N; i++)
	{
		cin >> now;
		while(!st.empty())
		{
			if(st.top().second > now) // 현재보다 왼쪽에 큰게 있으면 수신가능
			{
				cout << st.top().first << ' ';
				break; 
				// while문 탈출해서 넘어감. 일단 계속적으로 반복해야하는 경우는, 이렇게 
				// 예외케이스에 break로 탈출. 
			}
			
			st.pop(); // pop해서 다음거의 확인으로 넘어감
		}
		if(st.empty()){cout << "0 ";}
		st.push(make_pair(i,now)); // 수신해서 넘어간 경우에도 현재건 push
	}
	cout << '\n';
	return 0;
}