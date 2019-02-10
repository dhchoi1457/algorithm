//boj 10799
// 쇠자르기

#include <bits/stdc++.h>
using namespace std;

stack<char> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	int razer[50001];
	int ri=0;
	int cnt=0; // output. 잘린갯수 count

	cin >> input;

	//cout << input << '\n';
	//cout << input.at(0) <<','<< input.size() <<  '\n';

	char tmp;
	for(int i=0; i<input.size(); i++)
	{
		tmp = input.at(i);

		if(i==0){st.push(tmp);}
		else
		{
			if(tmp==')')
			{
				if(input.at(i-1)=='(') //직전이 (이어야 레이저
				{
					//razer
					st.pop(); // 팝해야 레이저 짝 맞춤
					cnt += st.size();
				}else
				{
					// 레이저 아닌 경우에는 쇠막대기 갯수 +1 하고 팝
					cnt+=1;
					st.pop();
				}
			}
			else if(tmp=='(')
			{
				st.push('(');
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
