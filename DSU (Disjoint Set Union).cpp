Without Struct:

int connected;
int root[N], sz[N];

void init()
{
	for(int i=1;i<=n;i++)
	{
		root[i]=i;
		sz[i]=1;
	}
	connected=n;
}

int rt(int k)
{
	while(k!=root[k])
	{
		root[k]=root[root[k]];
		k=root[k];
	}
	return k;
}

void merge(int u, int v)
{
	int rt1=rt(u);
	int rt2=rt(v);

	if(rt1==rt2)
		return;

	connected--;

	if(sz[rt1]>sz[rt2])
		swap(rt1, rt2);

	sz[rt2]+=sz[rt1];
	sz[rt1]=0;
	root[rt1]=root[rt2];
}

---
 
Struct Implementation:

struct DSU
{
	int connected;
	int par[N], sz[N];

	DSU() {} 

	DSU(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
		connected=n;
	}

	int getPar(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}

	int getSize(int k)
	{
		return sz[getPar(k)];
	}

	void unite(int u, int v)
	{
		int par1=getPar(u), par2=getPar(v);

		if(par1==par2)
			return;

		connected--;

		if(sz[par1]>sz[par2])
			swap(par1, par2);

		sz[par2]+=sz[par1];
		sz[par1]=0;
		par[par1]=par[par2];
	}
};

//Another DSU template

struct DSU {
	vector<int> par;
	int comps;
	DSU(int n) {
		par.resize(n);
		iota(par.begin(), par.end(), 0);
		comps = n;
	}
	int find(int u) {
		if (par[u] == u) return u;
		return par[u] = find(par[u]);
	}
	void merge(int u, int v) {
		u = find(u), v = find(v);
		if (u != v) {
			par[u] = v;
			comps--;
		}
	}
};

DSU dsu(n) , n = initial size of components

//Another one 
class DisjointSet{ 

public:

    vector<int> parent;

    DisjointSet(int n): parent(n) { for(int i=0; i<n; i++) parent[i] = i; }

    void join(int a, int b) { parent[find(b)] = find(a); }

    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

    bool check(int a, int b){ return find(a) == find(b); }

};

//Problem 1 (DSU + Divide and Conquer): https://codeforces.com/contest/813/problem/F
//Solution 1: https://codeforces.com/contest/813/submission/48548930
