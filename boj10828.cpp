//boj 10828
//스택 구현 

#include <bits/stdc++.h>
using namespace std;

void push(int val);
void pop();
int top();

const int MX = 10000007;
int st[MX];
int pos=0;

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
			push(tmp);
		}
		else if(S=="pop")
		{
			if(pos==0)
			{
				cout << "-1" << '\n';
			}
			else
			{
				pop();
			}
		}
		else if(S=="size")
		{
			cout << pos << "\n";
		} 
		else if(S=="empty")
		{
			cout << (int) (pos == 0) << '\n';
		}
		else // top
		{
			if(pos==0){cout << -1 << '\n';}
			else{ cout << top() <<'\n';}
		}
		cnt --;
	}

	return 0;
}



// stack 함수 만들기

void push(int val)
{
	st[pos]= val;
	pos++;
}

void pop()
{
	if(pos!=0)
	{
		pos--;
		cout << st[pos] <<"\n";
	}
}

int top()
{
	if(pos!=0)
	{
		return st[pos-1];
	}
}
