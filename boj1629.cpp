//boj 1629
// 곱셈

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gobsem(ll a, ll b, ll c){
	if(b==0){return 1;}

	ll val = gobsem(a,b/2,c);
	val = val*val%c;

	if(b%2==0){return val;}

	return val*a%c;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a,b,c;
	cin >> a >>  b >> c;

	int ans =gobsem(a,b,c);

	cout << ans << '\n';

	return 0;
}