// bkd 3/2 모의고사 A
// 계란으로 계란치기 

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;
int max_ans=-9999999;

int egg[10][2];
bool bk[10]; //부서졌는지 아닌지 체크
int cnt;


void upd(int i,int j){
	//내구도 업데이트
	egg[i][0] -= egg[j][1];
	if(egg[i][0]<=0){bk[i]=false; cnt++;}
	egg[j][0] -= egg[i][1];
	if(egg[j][0]<=0){bk[j]=false; cnt++;}

	cout << "update!" << '\n';
	cout << "i:" <<egg[i][0]<<'\n';
	cout << "j:" <<egg[j][0]<<'\n';
	cout << "cnt :" << cnt << '\n';
	cout << "\n";
}

void func(int now){
	cout << "now: " << now <<'\n';
	if(now == N){
		max_ans = max(max_ans,cnt);
		cout << "cnt : " << cnt << '\n';
		cout << "-----" << '\n';
		return;
	}

	if(!bk[now]){ //깨져있으면 다음으로 넘어감
		cout <<"깨져있어서 pass " << now << '\n';  
		func(now+1);
	}

	for(int k=0; k<N; k++){
		cout << "k search" <<'\n';
		cout << "now / k / bk[k] :" <<now << " / "<< k <<" / "<< bk[k] << "\n";
		if( k==N-1 and (now==k or bk[k]==false)) func(now+1);
		if(now==k) continue; //나랑 같은건 스킵
		if(bk[k]==false) continue; //깨져있는것도 스킵
		int before_now = egg[now][0];
		int before_k = egg[k][0];
		int before_cnt = cnt;
		cout << "before cnt : " << before_cnt << '\n';
		upd(now,k);
		func(now+1);
		cout <<"다음 k" <<'\n';
		//백트래킹 
		egg[now][0] = before_now;
		egg[k][0] = before_k;
		cnt = before_cnt;
		cout << "백트래킹 cnt : " << cnt << '\n';
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> egg[i][0] >> egg[i][1];
		bk[i]= true;
	}

	//제일 왼쪽에 있는거부터 돌아가면서 들고 계란깨기를 시도한다.
	//이미 깨져있는건 넘긴다.

	cnt = 0; //처음엔 깨진거 없다
	func(0);

	cout << max_ans <<'\n';
	return 0;
}
