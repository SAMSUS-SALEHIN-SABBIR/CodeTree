// LCA
// Least Common Ancestor with sparse table

vl G[MAX], W[MAX];
int level[MAX], parent[MAX], sparse[MAX][20];
ll dist[MAX], DIST[MAX][20];

void dfs(int u, int par, int lvl, ll d) {           // Tracks distance as well (From root 1 to all nodes)
    level[u] = lvl;                                 // parent[] and level[] is necessary
    parent[u] = par;                                
    dist[u] = d;                                    // remove distance if not needed
    
    for(int i = 0; i < SIZE(G[u]); ++i)
        if(parent[u] != G[u][i])
            dfs(G[u][i], u, lvl+1, d+W[u][i]);
}


void LCAinit(int V) {
    // DFS first
    memset(parent, -1, sizeof parent);
    dfs(1, -1, 0, 0);
    // Main initialization of sparse table LCA starts here
    memset(sparse, -1, sizeof sparse);
    for(int u = 1; u <= V; ++u)                 // node u's 2^0 parent
        sparse[u][0] = parent[u];
    
    int v;
    for(int p = 1; (1LL<<p) <= V; ++p)
        for(int u = 1; u <= V; ++u)
            if((v = sparse[u][p-1]) != -1)      // node u's 2^x parent = parent of node v's 2^(x-1) [ where node v : (node u's 2^(x-1) parent) ]
                sparse[u][p] = sparse[v][p-1];
}


int LCA(int u, int v) {
    if(level[u] > level[v])     // v is deeper
        swap(u, v);
    
    int p = ceil(log2(level[v]));
    // Pull up v to same level as u
    for(int i = p ; i >= 0; --i)
        if(level[v] - (1LL<<i) >= level[u])
            v = sparse[v][i];
    // if u WAS the parent
    if(u == v)
        return u;
    // Pull up u and v together while LCA not found
    for(int i = p; i >= 0; --i)
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i])      // -1 check is if 2^i is out of calculated range
            u = sparse[u][i], v = sparse[v][i];
    
    return parent[u];
}

// --------------------------- LCA WITH DISTANCE --------------------------- 
void distDP(int V) {                    // initialiser for LCA_with_DIST, call after LCAinit()
    // NOTE : DIST[u][0] = weight of node u
    for(int u = 1; u <= V; ++u)
        DIST[u][0] = W[u];              // Where W[u] = weight of node u
    for(int p = 1; (1<<p)<=V; ++p)
        for(int u = 1; u <=V; ++u) {
            int v = sparse[u][p-1];
            if(v == -1)
                continue;
            DIST[u][p] += DIST[u][p-1] + DIST[v][p-1];
        }
}

int LCA_with_DIST(int u, int v, long long &w) {           // w retuns distance from u -> v
    w = 0;
    if(level[u] > level[v])     // v is deeper
        swap(u, v);
    int p = ceil(log2(level[v]));
    // Pull up v to same level as u
    for(int i = p ; i >= 0; --i)
        if(level[v] - (1LL<<i) >= level[u]) {
            w += DIST[v][i];
            v = sparse[v][i];
        }
    // if u WAS the parent
    if(u == v) {
        w += DIST[v][0];
        return u;
    }
    // Pull up u and v together while LCA not found
    for(int i = p; i >= 0; --i)
        if(sparse[v][i] != -1 && sparse[u][i] != sparse[v][i])      // -1 check is if 2^i is out of calculated range
            u = sparse[u][i], v = sparse[v][i];
    w += DIST[v][0];            // 
    w += DIST[u][0];
    w += DIST[sparse[v][0]][0];
    return parent[u];
}

ll Distance(int u, int v) {
    int lca = LCA(u, v);
    return dist[v] + dist[u] - 2*dist[lca];
}
