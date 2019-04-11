// boj 14891
// https://www.acmicpc.net/problem/14891
// 톱니바퀴 
// 제대로 안돌아갈땐 인덱스의 문제다.

#include <bits/stdc++.h>
using namespace std;


string top[4];
int N;

void update(int ind, int dir){
	//시계방향 
	if(dir == 1 ){
		char tmpp = top[ind][7];

		for(int i=7; i>=1; i--){
			top[ind][i]=top[ind][i-1];
		}
		top[ind][0]=tmpp;
	}

	if(dir == -1){
		char tmpp = top[ind][0];

		for(int i=0; i<=6; i++){
			top[ind][i]=top[ind][i+1];
		}
		top[ind][7]=tmpp;	
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int y=0; y<4; y++){
		cin >> top[y];
	}

	cin >> N;

	int top_num, rot;
	

	for(int i=0; i<N; i++){
		int rotated[4]={0,};//이번 명령시에 전체적으로 어떻게 회전되는지

		cin >> top_num >> rot; 
		top_num--; // 인덱스조절용	
		rotated[top_num]= rot;

		
		int tmp = top_num;
		int tmp_rot = rot;
		

		// 왼쪽 회전 업데이트 
		for(int tmp=top_num; tmp>=1; tmp--){
			if(top[tmp][6] == top[tmp-1][2]){
				rotated[tmp-1]=0;
				break;
			}else{
				rotated[tmp-1]=-tmp_rot; //반대 방향으로 움직임
				tmp_rot = -tmp_rot;
			}
		}
		
		tmp = top_num;
		tmp_rot = rot;
		
		// 오른쪽 회전 업데이트
		for(int tmp=top_num; tmp<3; tmp++){
			//cout << "tmp+1:" << tmp+1 <<'\n';
			if(top[tmp][2] == top[tmp+1][6]){
				rotated[tmp+1]=0;
				break;
			}else{
				rotated[tmp+1]=-tmp_rot; //반대 방향으로 움직임
				tmp_rot = -tmp_rot;
			}
		}

		//회전에 따라서 각 톱니바퀴 업데이트 

		for(int t=0; t<4; t++){
			//cout << "rotate:" << rotated[t] <<'\n';
			update(t,rotated[t]);
		}
	}

	int ret=0;
	for(int t=0; t<4; t++){
		//cout << top[t] <<'\n';
		int grade = (1<<t);
		if(top[t][0]=='1') ret+= grade;
	}

	cout << ret <<'\n';

	return 0;
}
 