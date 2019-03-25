// boj 15686
// 치킨배달 
// 삼성전자 ds SW역량기출
// next_permutation 조합 이용해서 풀기
// 인덱스 주의(갯수 조심)

// dfs로 푸는게 보통방법인듯 - na982


#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

struct ck_house
{
	int y ,x;
};

const int dx[4] ={1,0,-1,0};
const int dy[4] ={0,1,0,-1};

int board[52][52];
int dist_map[52][52];
int N; // board size 
int M;  //치킨집 갯수

ck_house ckh[15];
int ck_index=0;

void ck_update(ck_house ck){

	//치킨 거리 업데이트. 
	//해당 치킨집으로 계산했을떄가 더 가까우면 갱신 
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(board[i][j]==1){

				int now_dist = abs(ck.y - i)+abs(ck.x-j);

				//처음엔 걍 계산한거 집어넣고
				if(dist_map[i][j]==0){dist_map[i][j]=now_dist;}

				//이미 계산된게 있으면 비교하고 갱신
				if(dist_map[i][j]!=0 and now_dist < dist_map[i][j] ){
					dist_map[i][j]=now_dist;
				}
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M; 

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
			dist_map[i][j]=0;

			//치킨집 입력받아놓기
			if(board[i][j]==2){
				ckh[ck_index].y = i;
				ckh[ck_index].x = j;
				ck_index++;
			}
		}
	}

	// 1개부터 M개일때 까지 시뮬레이션 해야함
	// 걍 M개 골라서 최소값 봐도 됨.
	// 어차피 M개 골랐을때에 최소가 반드시 들어감

	vector<int> v;

	for(int i=0; i<ck_index; i++){
		v.push_back(i); // ck_index-1개 , 실제 ck_index값은 갯수보다 하나 더 있음
	}

	//0과 1을 저장할 벡터 생성
	vector<int> ind;

	int k = M;
	//벡터 한번 정렬(그래야 빼먹은거없이 조합 결과 뽑음)
	
	for(int i=0; i<k; i++){
		ind.push_back(1); //k개
	}

	for(int i=0; i<ck_index-k; i++){
		ind.push_back(0);
	}

	sort(ind.begin(), ind.end());

	int min_output=1e7;

	do{

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++ ){
				dist_map[i][j]=0;
			}
		}

		//치킨집 조합
		for(int i=0; i<ind.size(); i++){
			
			if(ind[i]==1){
				ck_update(ckh[i]);
			}
		}

		int sum=0;
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++ ){
				sum += dist_map[i][j];
			}
		}

		if(sum < min_output){
			min_output=sum;
		}

	}while(next_permutation(ind.begin(),ind.end()));
	//조합으로 할떈 ind 퍼뮤테이션


	cout << min_output << '\n';
	return 0;
}



 