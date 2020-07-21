vector<int> trans(int n,int k){//nをk進数表記
    vector<int> ret;//ret[i]:nをk進数表記した時のk^iの位の値
    while(n){
        n--;
        ret.push_back(n%k);
        n /= k;
    }
    return ret;
}
