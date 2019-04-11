// boj 14889
// 스타트와링크
#include <bits/stdc++.h>
using namespace std;

int board[502][502];

int N;

int gap;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int y=0; y<N; y++){
		for(int x=0; x<N; x++){
			cin >> board[y][x];
			//cout << board[y][x] << ' ';
		}
		//cout <<'\n';
	}

	gap = 1e7;

	// 1. N명 중에 N/2명을 뽑는 '조합'을 구해서 / 그럼 다른팀 조합은 구해진다.
	int arr[N]={0,};

	for(int i=N/2; i<N; i++){
	 	arr[i]=1;
	}



	do{

		vector<int> team1;
		vector<int> team2;
		
		for(int i=0; i<N; i++){
			if(arr[i]==0){
				team1.push_back(i);
			}
			if(arr[i]==1){
				team2.push_back(i);
			}
		}

		int arr2[N/2]={0,};
		//2개만 고를것, 2개만 0이 들어있어야함
		for(int i=2; i<N/2; i++){
		 	arr2[i]=1;
		}

		int team1_sum =0;
		int team2_sum =0;
		
		//cout << "team1 2 select" <<'\n';
		do{
			vector<int> t1;
			vector<int> t2;
			for(int i=0; i<N/2; i++){
				//cout << arr2[i] <<' ';
				if(arr2[i]==0){
					t1.push_back(team1[i]);
					t2.push_back(team2[i]);
				}
			}
			team1_sum += board[t1[0]][t1[1]] + board[t1[1]][t1[0]];
			team2_sum += board[t2[0]][t2[1]] + board[t2[1]][t2[0]]; 
		}
		while(next_permutation(arr2,arr2+N/2));



		// cout << "gap :" << gap << ", now abs:" <<  abs(team1_sum - team2_sum) <<'\n';
		// cout << "team1_sum: " << team1_sum <<'\n';
		// cout << "team2_sum: " << team2_sum <<'\n';
		// cout <<"team1: ";
		// for(int i=0; i<N/2; i++){
		// 	cout << team1[i] << ' ';
		// }
		// cout <<'\n';
		// cout <<"team2: ";
		// for(int i=0; i<N/2; i++){
		// 	cout << team2[i] << ' ';
		// }
		// cout <<'\n';
		// cout <<'\n';


		if(gap > abs(team1_sum - team2_sum)) gap = abs(team1_sum - team2_sum);

	 }while(next_permutation(arr,arr+N));

	//각 팀에 제대로 들어갔는지 체크 OK
		
	// 2.각 팀 조합에서 2명씩 짝짓는 '순열'을 만들어 팀 점수를 더한다 
 	// 넥퍼뮤 이용해서 nPr 방법찾거나


 	// 아니면 걍 2개 뽑아서 점수더하면 된다.(이건당장 가능 )
	
	// 3.gap을 비교하여 최소일떄 갱신한다

	cout << gap <<'\n';

	return 0;
}
 