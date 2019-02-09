//boj 5430
// AC
// 입력의 고난을 겪어 많이 배웁니다..
// 문제 이름이 AC인 이유는 에이X...
// 틀렸다.. 추후에 고치자ㅠㅠ

#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

// 내용물 확인용
void printQue() {
    for (int i = 0; i < dq.size(); i++) {
        cout << dq.at(i) << " ";
    }
    cout << '\n';
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int k=0; k<T; k++)
	{
		string p,arr;
		
		cin >> p; // 명령어 R , D 
		int len;
		cin >> len; // 숫자길이? 어따쓰지 근데

		if(len >0) cin >> arr; // 내용물 없으면 안돌아야지
		string input;

		for(auto s:arr)
		{	
			
			if(s>='0' & s<='9'){input+=s;}
			else
			{
				if(s==','||s==']')
				{
					dq.push_back(atoi(input.c_str()));
					input.clear();	
				}
			}
		}

		//printQue(); // ok 잘들어감

		int dir = 1; // 방향. 1이면 순방향, -1이면 역방향
		int chk_error=0;

		for(auto s:p)
		{
			if(s=='R')
			{
				dir = -dir;
			}
			if(s=='D')
			{

				if(dq.empty())
				{
					chk_error=1;
					break;
				}
				else if(dir==1)
				{
					dq.pop_front();
					//printQue();
				}
				else if(dir==-1)
				{
					dq.pop_back();
					//printQue();
				}
			}
		}

		if(chk_error==1)
		{
			cout << "error" <<'\n';
		}
		else if(dir ==1)
		{
			cout << "[";
			for(int i=0; i<dq.size(); i++)
			{
				cout <<dq.at(i);
				if(i != dq.size()-1)
				{
					cout << ',';
				}
			}
			cout << ']'<<'\n';
		}
		else if(dir ==-1)
		{
			cout << '[';
			for(int i=dq.size()-1; i>=0; i--)
			{
				cout << dq.at(i);
				if(i != 0)
				{
					cout << ",";
				}
			}
			cout << ']'<<'\n';
		}
		dq.clear();
	}
	return 0;
}
