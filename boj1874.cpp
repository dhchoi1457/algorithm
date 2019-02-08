//boj 1874
// 스택수열

#include <bits/stdc++.h>
using namespace std;
const int MX = 10000007;
char output[MX];

stack<int> S;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int num;

	int out_top=0;
	int in = 0 ; // in : stack에 삽입할 자연수

	for(int i=0; i<N; i++)
	{
		cin >> num;

		if(num > N) // cnt보다 큰 값을 받을수는 없음
		{
			cout << "NO" << '\n';
			return 0;
		}

		
		if(in < num) // stack에 당장 들어갈 값이 num(현재 수열의 입력 값)보다 작으면, push해서 더들어간다음에 pop 가능
		{
			for(int j= in; j<num; j++)
			{
				S.push(in+1); // in은 0부터 시작하므로 +1 을 더함
				in++;  // 순차적으로 in을 넣으므로 다음건 커져야함
				output[out_top++]='+';
			}
		}
		
		if(S.top()== num) // 현재 stack에서 pop시킬 값과 현재 수열의 값이 같으면 pop!
		{
			S.pop();
			output[out_top++]='-';
		}
		else // stack에서 pop시킬 값보다 현재 수열의 값이 작으면, --> 아까 부족한만큼 push했는데도 다르다는 것이니, 불가능 
			// 커도 마찬가지.
		{
			cout << "NO" << '\n';
			return 0;
		}

	}


	for (int i=0; i<out_top; i++)
	{
		cout << output[i] << '\n';
	}

	return 0;
}
