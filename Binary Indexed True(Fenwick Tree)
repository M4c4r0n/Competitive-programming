template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  //区間和関係
  //一点更新、区間和取得どちらもO(logN)
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {//sum of [0,i]
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {// sum of [l,r)
    return sum(r-1) - sum(l-1);
  }
  
};
