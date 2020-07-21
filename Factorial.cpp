const int mod = 1000000007;
// a^n mod を計算
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
vector<int> f = {1},fi = {1};
//x!%modを計算
int fact(int x){
	while((int)f.size() <=x)f.push_back((f.back()*f.size())%mod);
	return f[x];
}
//x!の逆元%modを計算
int ifact(int x){
	return modpow(fact(x),mod-2,mod);
}
//xCy %modを計算
int C(int x,int y){
	if(x < y)return 0;
	return fact(x)*ifact(y)%mod*ifact(x-y)%mod;
}
//xHy = x+y-1Cyを計算
int H(int x,int y){
  return C(x+y-1,y);
}
