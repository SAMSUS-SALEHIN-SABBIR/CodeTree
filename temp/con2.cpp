
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define ui unsigned int
#define vi vector<int>
#define ii pair<int, int>
#define iii pair<ii, int>
#define vii vector<pair<int, int> >
#define ull unsigned long long
#define N 50000
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

/*using namespace std;

int dr[] ={-1, 0, 0, +1}, dc[] = {0, -1, +1, 0}, lim;
int g[10001][10001], dis[10001][10001];

int dikjstra(int x, int y, int m, int n)
{
    //int dis[m+2][n+2];
    fr(i, 0, m+2) fr(j, 0, n+2) dis[i][j] = inf;
    dis[x][y] = 0;
    priority_queue<iii>pq;
    pq.push(mp(mp(-x, -y), dis[x][y]));
    wh(!pq.empty()) {
        iii u = pq.top();
        pq.pop();
        for(int i = 0; i < 4; i++) {
            int r = (-u.first.first) + dr[i];
            int c = (-u.first.second) + dc[i];
            if(r >= 0 && r < m && c >= 0 && c < n) {
                //pf("r : %d, c: %d\n", r, c);
                if(dis[r][c] > dis[-u.fi.fi][-u.fi.se] + g[r][c]) {
                    //pf("entering r: %d c: %d from %d %d", r, c, u.fi.fi, u.fi.se);
                    dis[r][c] = dis[-u.fi.fi][-u.fi.se] + g[r][c];
                    //pf(" dis : %d\n", dis[r][c]);
                    pq.push(mp(mp(-r, -c), dis[r][c]));
                }
            }
        }
    }
    return dis[m-1][n-1];
}

int main()
{
    frein;
    freout;
    ri t, m, n, c;
    sf("%d", &t);
    wh(t--) {
        sf("%d %d", &m, &n);
        lim = m*n;
        //g.resize(lim+3);
        fr(i, 0, m)
            fr(j, 0, n) {
                sf("%d", &c);
                g[i][j] = c;
            }

        pf("%d\n", dikjstra(0, 0, m, n)+g[0][0]);
        //g.clear();
    }
    return 0;
}*/
