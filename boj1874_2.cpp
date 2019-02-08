//boj 1874
// 스택수열
// 못푼거. 못푼 이유?
// --> 얼추 비슷하게 왔으나,
// 명확한 수식(규칙)을 도출해내느냐/ 아니냐가 중요. + flow를 더 깔끔하게 짤수있느냐 없느냐.
// 이건 많이 시도해보고, 다른 사람 코드 많이 하면 늘것. 걱정 ㄴㄴ


#include <bits/stdc++.h>
using namespace std;
const int MX = 10000007;
int st[MX];

stack<int> S1;
deque<char> S2;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num, tmp, cp;

	cin >> num;

	num=2; // test 용

	cp=0; // 간격조절용 
	
	for(int i=0; i<num; i++)
	{
		cin >> tmp;

		if(S1.empty())
		{
			for(int i=cp+1; i<=tmp; i++)
			{
				S1.push(i);
				S2.push_back('+');
				cp++; // S2에 +가 쌓이는 갯수를 체크
			}
		}

		if(S1.top()==tmp)
		{
			S1.pop();
			S2.push_back('-');
		}
		else if(S1.top()<tmp)
		{
			for(int i=cp; i<=tmp; i++)
			{
				S1.push(i);
				S2.push_back('+');
				cp++; // S2에 +가 쌓이는 갯수를 체크
			}
		}else
		{
			S2.push_back('N');
			break;
		}

	}

	if(S2.back()=='N'){cout <<"NO"<<'\n';}
	else
	{
		for(int j=0; j<S2.size(); j++)
		{
			cout << S2.front() << '\n';
			S2.pop_front();
		}
	}
	return 0;
	
}
