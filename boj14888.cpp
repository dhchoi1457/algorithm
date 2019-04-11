// boj 14888
// 연산자 끼워넣기

#include <bits/stdc++.h>
using namespace std;

int N;
int num[12];

int op[4];

int op_arr[12];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> num[i];
		//cout << num[i] <<' ';
	}
	//cout <<'\n';

	int ind=0;
	for(int i=0; i<4; i++){
		cin >> op[i];
		int tmp = op[i];
		while(tmp){
			tmp--;
			op_arr[ind++]=(i+1);
		}	
	}

	// for(int j=0; j<N-1; j++){
	// 	cout << op_arr[j] << ' ';
	// }

	int ret_max= -1e9;
	int ret_min= 1e9;
	do{
		int iter = N;
		int num_ind =0;
		int op_ind =0;

		int tmp1 = num[num_ind];
		int tmp2;
		while(iter){
			//cout << "iter: " << iter << '\n';
			iter--;
			tmp2 = num[++num_ind];
			int now_op = op_arr[op_ind++];

			if(now_op==1){
				tmp1= tmp1 + tmp2;
			}
			else if(now_op==2){
				tmp1= tmp1 - tmp2;
			}
			else if(now_op==3){
				tmp1= tmp1 * tmp2;
			}
			else if(now_op==4){
				tmp1= tmp1 / tmp2;
			}
		}

		if(tmp1 > ret_max) ret_max = tmp1;
		if(tmp1 < ret_min) ret_min = tmp1;

	}while(next_permutation(op_arr,op_arr+N-1));


	cout << ret_max <<'\n';
	cout << ret_min <<'\n';
	return 0;
}