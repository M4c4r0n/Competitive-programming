struct UnionFind {
	vector<int> d;
	UnionFind(int n=0): d(n,-1) {}
  
  //root of vertex x
	int root(int x) {
	  if (d[x] < 0) return x;
	  return d[x] = root(d[x]);
	}
  
  // unite vertices x and y
	bool unite(int x, int y) {
	  x = root(x); y = root(y);
	  if (x == y) return false;
	  if (d[x] > d[y]) swap(x,y);
	  d[x] += d[y];
	  d[y] = x;
	  return true;
	}
  
  //whether vertices x and y are in same connected component
	bool same(int x, int y) { return root(x) == root(y);}
  
  // get the size of connected component vertex x is belong to
	int size(int x) { return -d[root(x)];}
  };
