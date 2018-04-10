// Codeforces
// Xor-tree
// http://codeforces.com/problemset/problem/429/A
// DFS

#include <bits/stdc++.h>
using namespace std;
#define MAX                 100100
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

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

vi G[MAX], Ans;
bool cst[MAX], target[MAX];

void dfs(int u, bool eFlip, bool oFlip, int level, int par) {
    //cout << "AT " << u << endl;
    
    if(level%2 and oFlip)
        cst[u] ^= 1;
    
    if(level%2 == 0 and eFlip)
        cst[u] ^= 1;
    
    if(cst[u] != target[u]) {
        cst[u] ^= 1;
        Ans.pb(u);
        if(level%2)
            oFlip ^= 1;
        else
            eFlip ^= 1;
    }
    
    for(auto v : G[u])
        if(par != v)
            dfs(v, eFlip, oFlip, level+1, u);
}

int main() {
    int n, u, v;
    
    cin >> n;
    
    fr(i, 1, n) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    
    for(int i = 1; i <= n; ++i)
        cin >> cst[i];
    
    for(int i = 1; i <= n; ++i)
        cin >> target[i];
    
    dfs(1, 0, 0, 0, -1);
    
    
    cout << Ans.size() << "\n";
    for(auto it : Ans)
        cout << it << "\n";
    
    return 0;
}

