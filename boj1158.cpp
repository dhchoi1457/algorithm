//boj 1158
//조세퍼스

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> v;

	for(int i=0; i<N; i++)
	{
		v.push_back(i+1);
	}

	cout <<'<';

	int index=0;
	while(v.size()>0)
	{
		index = (index + M - 1) % v.size();
		// 없어진 것 다음거가 (혹은 시작점이) 1번째이므로, 더할떄 M-1을 더해준다.
		// array를 쓸 때랑 다르게, index가 알아서 맞춰지므로 이렇게 해도 됨.
		// -- array는 삭제표시를 해도, index는 알아서 맞춰지지 않으므로 일일히 넘어가야함

		cout << v.at(index);
		v.erase(v.begin()+index);

		if(v.size()>0)
		{
			cout << ", ";
		}  
	}

	cout << ">";

	return 0;
}
