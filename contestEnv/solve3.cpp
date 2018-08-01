#include <bits/stdc++.h>
using namespace std;
#define MAX                 100009
#define EPS                 1e-9
#define INF                 1e17
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


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

struct point {          // In Double
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
}};

// Parametric Line ------------------------------
struct ParaLine {                                       // Line in Parametric Form
    point a, b;                                         // points must be in DOUBLE
    ParaLine() { a.x  = a.y = b.x = b.y = 0; }
    ParaLine(point _a, point _b) : a(_a), b(_b) {}      // {Start, Finish} or {from, to}

    point getPoint(double t) {                          // Parametric Line : a + t * (b - a)    t = [-inf, +inf]
        return point(a.x + t*(b.x-a.x), a.y + t*(b.y-a.y));
}};

vector<point>p1, p2;

double dist(point p1, point p2) {
	double x = p1.x-p2.x;
	double y = p1.y-p2.y;
	return sqrt(x*x + y*y);
}

/*
double ternarySearch(ll low, ll high) {
    ll ret = -INF;
    for(int i = 0; i < 100; ++i) {
        ll mid1 = low + (high - low) / 3;
        ll mid2 = high - (high - low) / 3;
        ll cost1 = f(mid1);
        ll cost2 = f(mid2);
        if(cost1 < cost2) {
            low = mid1;
            ret = max(cost2, ret);
        }
        else {
            high = mid2;
            ret = max(cost1, ret);
    }}
    for(int i = low; i <= high; ++i)
        ret = max(ret, f(i));
    return ret;
}*/

int main() {
    int n, m;
    point pp;
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> pp.x >> pp.y;
        p1.push_back(pp);
    }
    
    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> pp.x >> pp.y;
        p2.push_back(pp);
    }
    
    //int sz = min(m, n);
    double ans = INF;
    
    for(int i = 1, j = 1; i < n and j < m; ) {
        double d1 = dist(p1[i-1], p1[i]);
        double d2 = dist(p2[j-1], p2[j]);
        
        ParaLine l1(p1[i-1], p1[i]);
        ParaLine l2(p2[j-1], p2[j]);
        
        //cerr << i << " " << j << endl;
        //cerr << "v1 " << p1[i-1].x << ", " << p1[i-1].y << " -> " << p1[i].x << ", " << p1[i].y << endl;
        //cerr << "v2 " << p2[j-1].x << ", " << p2[j-1].y << " -> " << p2[j].x << ", " << p2[j].y << endl;
        
        double low = 0, high = min(d1, d2), ret = INF;
        for(int i = 0; i < 100; ++i) {
            double dd1 = low + (high - low) / 3;
            double dd2 = high - (high - low) / 3;
            
            point n11 = l1.getPoint(dd1/d1), n12 = l2.getPoint(dd1/d2);
            point n21 = l1.getPoint(dd2/d1), n22 = l2.getPoint(dd2/d2);
            
            if(dist(n11, n12) > dist(n21, n22)) {
                low = dd1;
                ret = min(ret, dist(n21, n22));
                //if(abs(ret-1) <= EPS)
                    //cerr << "+++++++GOT " << ret << " : " << n21.x << ", " << n21.y << " : " << n22.x << ", " << n22.y << endl;
            }
            else {
                high = dd2;
                ret = min(ret, dist(n11, n12));
                //if(abs(ret-1) <= EPS)
                    //cerr << "*******GOT " << ret << " : " << n11.x << ", " << n11.y << " : " << n12.x << ", " << n12.y << endl;
            }
        }
        
        
        //cerr << "GOT " << ret << endl;
        ans = min(ans, ret);
        
        if(abs(d1-d2) <= EPS) {
            //cerr << "same\n";
            i++, j++;
        }
        else if(d1 - d2 > EPS) {        // d1 is bigger, assign new p1 and go for next p2
            //cerr << "1 greater than 2\n";
            double per = d2/d1;
            p1[i-1] = l1.getPoint(per);
            ++j;
        }
        else {                          // d2 is bigger
            //cerr << "2 greater than 1\n";
            double per = d1/d2;
            p2[j-1] = l2.getPoint(per);
            ++i;
        }
        
        //cerr << "---------------------" << endl;
    }
    
    cout << ans << endl;
    return 0;
}
