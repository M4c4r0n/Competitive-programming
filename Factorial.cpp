const int mod = 1000000007;
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
vector<ll> fact,ifact;
void init(int n){
	fact.resize(n);
	ifact.resize(n);
	fact[0] = 1;
	for(int i = 1;i < n;i++)fact[i] = (fact[i-1]*i)%mod;
	rep(i,n)ifact[i] = modpow(fact[i],mod-2,mod);
}
void add(ll &a,ll b){
	a = (a+b)%mod;
	a = (a%mod + mod)%mod;
}
void mul(ll &a,ll b){
	a = (a*b)%mod;
}
ll C(ll x,ll y){
	if(x < 0)return 0;
	if(y < 0)return 0;
	if(x < y)return 0;
	ll ret = fact[x];
	mul(ret,ifact[y]);
	mul(ret,ifact[x-y]);
	return ret;
}
ll H(ll x,ll y){
	return C(x+y-1,y);
}