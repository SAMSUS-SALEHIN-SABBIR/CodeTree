#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


inline ll lcm(ll a, ll b) {
	return (a*b)/__gcd(a, b);
}


int main() {
	
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	ll m, n, t, v[20], ans;
	scanf("%lld", &t);
	
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%lld%lld", &n, &m);
		for(int i = 0; i < m; ++i)
			scanf("%lld", &v[i]);
		ans = 0;
		int l = 1 << m;
		for(int i = 1; i < l; ++i) {
			ll Lcm = 1;
			for(int j = 0; j < m; ++j)
				if(i & (1 << j))
					Lcm = lcm(Lcm, v[j]);
			//cout << n/Lcm << " - " << 
			
			if(__builtin_popcount(i) & 1)
				ans += (n/Lcm);
			else
				ans -= (n/Lcm);
			
			//cout << "ans " << ans << endl;
		}
		//cout << "last " << ans << endl; 
		printf("Case %d: %lld\n", Case, n-ans);
	}
	
	return 0;
}
