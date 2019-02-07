//boj 1919
//애너그램 

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string A,B;
	cin >> A >> B;
	int arr1[26]={};
	int arr2[26]={};
	for(auto s:A){arr1[s-'a']++;}
	for(auto s:B){arr2[s-'a']++;}

	int cnt=0;

	for(int i=0; i<26; i++)
	{
		if(arr1[i]>arr2[i])
		{
			cnt+=arr1[i]-arr2[i]; //gap만큼 늘어난다
			arr1[i]=arr2[i];
		}
		else if(arr1[i]<arr2[i])
		{
			cnt+=arr2[i]-arr1[i];
			arr2[i]=arr1[i];
		}
	}
	cout << cnt <<'\n';
	return 0;
}
