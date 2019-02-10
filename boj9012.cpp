//boj 9012
// 괄호

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; // Test case number
	cin >> T;

	string input;

	for(int i=0; i<T; i++) // Test case iteration
	{
		stack<char> st;
		cin >> input;
		int ans = 0;

		for(auto s:input)
		{
			//cout << s << '\n';

			if(s=='(')
			{
				st.push(s);
				//cout << "after push, top:"<< st.top() << '\n';
			}
			if(s==')')
			{
				if(st.empty())
				{
					ans =1;
					break;
				}
				else if(st.top()=='(')
				{
					//cout << "now top:"<<st.top() << '\n';
					st.pop();
				}
				else
				{
					ans =1;
					break;
				}
			}

		}

		if(!st.empty())
		{
			for(int j =0; j<st.size(); j++)
			{
				st.pop();
			}
			ans =1;
		}
		if(ans==1){cout << "NO" << endl;}
		else{cout << "YES" << endl;}

	}
	return 0;
}
