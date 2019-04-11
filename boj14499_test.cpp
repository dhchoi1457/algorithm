#include <bits/stdc++.h>
using namespace std;
int n, m;
int x, y;
int k;
int mat[20][20];
// 1 2 3 4 5 6
int dice[7]={0, 0, 0, 0, 0, 0, 0};
int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}

void move(int dir){
	
	//동 
	if(dir == 0){
		//cout << "동" <<'\n';
		int tmp = dice[3];
		dice[3]= dice[1];
		dice[1]= dice[4];
		dice[4]= dice[6];
		dice[6]= tmp;
	}
	
	//서
	if(dir == 1){
		//cout << "서" <<'\n';
		int tmp = dice[6];
		dice[6]= dice[4];
		dice[4]= dice[1];
		dice[1]= dice[3];
		dice[3]= tmp;
	}


	//북 
	if(dir == 2){
		//cout << "북" <<'\n';
		int tmp = dice[2];
		dice[2]= dice[1];
		dice[1]= dice[5];
		dice[5]= dice[6];
		dice[6]= tmp;
	}

	//남 
	if(dir == 3){
		//cout << "남" <<'\n';
		int tmp = dice[6];
		dice[6]= dice[5];
		dice[5]= dice[1];
		dice[1]= dice[2];
		dice[2]= tmp;
	}

}

int main(){
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &mat[i][j]);
	for(int i=0;i<k;i++){
		int order;
		scanf("%d", &order);
		order--;
		int nx=x+dx[order];
		int ny=y+dy[order];
		if(!safe(nx, ny))
			continue;
		move(order);
		if(mat[nx][ny]==0){
			mat[nx][ny]=dice[6];
		}
		else{
			dice[6]=mat[nx][ny];
			mat[nx][ny]=0;
		}
		printf("%d\n", dice[1]);
		
		x=nx;
		y=ny;
	}
	return 0;
}