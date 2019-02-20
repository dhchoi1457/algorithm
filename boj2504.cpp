//boj 2504
// 괄호의 값
// 풀이는 이해를 하긴했는데,
// 왜 이렇게 푸는지는 잘 모르겠다.
// 일단 열린괄호:([ 로 파고들어간다는건 안의 값에 2* 3*가 된다는 뜻이므로
// 계속 곱해간다
// 닫힌괄호:])가 나온다는건 일단 값이 한 값이 마무리 지어졌고, 더해진다는 뜻 --> 곱해질건 이미 열면서 다 곱해놨음. 그대로 더해서 반영하면 됨.


#include <bits/stdc++.h>
using namespace std;

stack<char> stk;
string input;
int sum=0;
int tmp=1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> input;

	for(int i=0; i<input.size(); i++ ){
		switch(input[i]){
			case '(': 
				tmp *=2;
				stk.push('(');
				break;
			case ')':
				if(i>=1 and input[i-1]=='(') sum += tmp;
				if(stk.empty()){
					cout << '0'<<'\n'; 
					return 0;}
				if(stk.top()=='(') stk.pop();
				tmp/=2; break;

			case '[': 
				tmp *=3;
				stk.push('[');
				break;
			case ']':
				if(i>=1 and input[i-1]=='[') sum += tmp;
				if(stk.empty()){
					cout << '0'<<'\n'; 
					return 0;
			}
				if(stk.top()=='[') stk.pop();
				tmp/=3; break;
		}

	}

	if(stk.empty()){cout << sum << '\n';}
	else{cout << '0' << '\n';}
	return 0;
}
