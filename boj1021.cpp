//boj 1021
// 회전하는 큐
// 이건 Deque를 쓴다는것만 생각하면 아주 쉬워짐
// 는 쉬워지지 않았다..

#include <bits/stdc++.h>
using namespace std;

deque<int> dq;


// void printQue() {
//     for (int i = 0; i < dq.size(); i++) {
//         cout << dq.at(i) << " ";
//     }
//     cout << '\n';

// }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N,M;
	cin >> N >> M; // N <= 50,  M >= N;


	// deque에 입력
	for(int i=0; i<N; i++)
	{
		dq.push_back(i+1); // N은 자연수 
	}

	//현재는 출력지점의 위치
	auto it = dq.begin(); // 원래 표현은 deque<int>::iterator it = dq.begin();
	int cnt=0; // 왼,오 이동 횟수  count
	int point ; // 지금 출력하고자 하는 원소의 위치. 여기서는 거의 값처럼 사용
	for(int j=0; j<M; j++)
	{
		cin >> point;
		//cout << point << '\n';

		int check_pop = 0;

		//현재 dq의 front가 뽑고자 하는 것과 같으면 바로 출력
		if(point == *it)
		{
			dq.pop_front();
			check_pop=1;
			it = dq.begin(); // 현재 dq의 맨앞 위치 update
		}
		//아니면 그거의 위치 찾고, 왼쪽 오른쪽 중에 가까운 쪽 판단해서 이동
		else
		{

			int index = 0;
			for(it = dq.begin(); it <=dq.end(); it++)
			{
				if(*it == point) // dq 내에서 point값의 위치를 찾는다
				{
					break;
				}
				index++;
			}
			
			// 방향에 따른 이동거리 측정
			int cnt_l = index;
			int cnt_r = dq.size()- index;
		//	cout << cnt_l << ' ' << cnt_r << '\n';

			//이동거리 사이즈에 맞추어 cnt 업데이트
			if(cnt_l <= cnt_r)
			{
				for(int i=0; i<cnt_l; i++)
				{
					dq.push_back(dq.front());
					dq.pop_front();
				}

				dq.pop_front(); // 찾는거 팝
				// printQue();
				cnt += cnt_l;
			}
			else
			{
				for(int j=0; j<cnt_r; j++)
				{
					dq.push_front(dq.back());
					dq.pop_back();
				}
				dq.pop_front(); //찾는거 팝
				//printQue();
				cnt += cnt_r;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}
