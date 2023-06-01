long long compute_hash(string const& s) {
    const int p = 31;   //se tiver maiúscula, 53 pode ser uma boa opção
    const int m = 1e9 + 7;   //99999996961, 99999999119, 9999997409, 9999997561, 999996307, 999998501, 99999089, 99997769, 9999907, 9993769
    long long hash_value = 0;
    long long p_pow[mxn];
    for(int i=1; i<=n; i++){
        p_pow[i]=(p_pow[i-1]*p)%m;
    }
    for (int i=0; i<s.size(); i++) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow[i]) % m;
    }
    return hash_value;
}

struct Hashing{
    int n;
    int p=31; //se tiver maiúscula, 53 pode ser uma boa opção
    int m=1e9+7;
    ll inv_p=129032259;
    vector<ll> p_pow, inv_pow, h;
    string s;
    
    Hashing(string s) : s(s){
        n=s.size();
        p_pow.resize(n+1);
        inv_pow.resize(n+1);
        h.resize(n+1);

        p_pow[0]=1;
        inv_pow[0]=1;
        for(int i=1; i<n; i++){
            p_pow[i]=(p_pow[i-1]*p)%m;
            inv_pow[i]=(inv_pow[i-1]*inv_p)%m;
        }
        for(int i=1; i<=n; i++){
            h[i]=(h[i-1]+(s[i-1]-'a'+1)*p_pow[i-1])%m;
        }
    }

    // void build(){
    //     p_pow[0]=1;
    //     inv_pow[0]=1;
    //     for(int i=1; i<n; i++){
    //         p_pow[i]=(p_pow[i-1]*p)%m;
    //         inv_pow[i]=(inv_pow[i-1]*inv_p)%m;
    //     }
    //     for(int i=1; i<=n; i++){
    //         h[i]=(h[i-1]+(s[i-1]-'a'+1)*p_pow[i-1])%m;
    //     }
    // }
    ll range(int l, int r){ //index em 0, mesmo h sendo em 1
        return (mod(h[r+1]-h[l], m)*inv_pow[l])%m;
    }
};