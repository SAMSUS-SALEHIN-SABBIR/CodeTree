// Codeforces
// http://codeforces.com/contest/920/problem/F

// Segment Tree / (Fenwick Tree + Set)

#include <bits/stdc++.h>
using namespace std;
#define MAX                 400005
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

//const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};                                                      // Four side 
//const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};                     // Eight side
//----------------------------------------------------------------------------------------------------------

ll tree[MAX];
ll Div[1001000], MaxVal = 300010, val[MAX];
vl Remove;
set<ll>Set;

void update(int idx, int val) {
	while(idx <= MaxVal) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

long long read(int idx) {
	long long sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

long long readSingle(int idx) {
	long long sum = tree[idx];
	if(idx > 0) {
		int z = idx - (idx & -idx);
		--idx;
		while(idx != z) {
			sum -= tree[idx];
			idx -= (idx & -idx);
		}
	}
	return sum;
}


void divGen(int n) {
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; j += i)
            Div[j]++;
}


int main() {
    ll n, m, q, l, r, x;
    divGen(1000010);
    FastRead;
    cin >> n >> m;
    
    fr(i, 1, n+1) {
        cin >> x;
        update(i, x);
        if(Div[x] != x) {
            Set.insert(i);
            //cout << "Inserted " << i << endl;
        }
        val[i] = x;
        //error(i, x, Div[x]);
    }
    
    fr(i, 0, m) {
        cin >> q >> l >> r;
        if(q==2)
            cout << read(r)-read(l-1) << "\n";
        else {
            auto low = Set.lower_bound(l);
            auto hi = Set.upper_bound(r);
            
            while(low != hi) {
                //error(l, r, *low);
                ll pstVal = val[*low];
                ll newVal = Div[pstVal] - pstVal;
                //error(pstVal, newVal);
                update(*low, newVal);
                
                val[*low] = Div[pstVal];
                
                if(Div[val[*low]] == val[*low])
                    Remove.pb(*low);
                low++;
            }
            
            for(auto val : Remove)
                Set.erase(val);
            Remove.clear();
        }
    }
        
    return 0;
}
