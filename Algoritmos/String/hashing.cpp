long long compute_hash(string const& s) {
    const int p = 31;   //se tiver maiúscula, 53 pode ser uma boa opção
    const int m = 1e9 + 9;   //99999996961, 99999999119, 9999997409, 9999997561, 999996307, 999998501, 99999089, 99997769, 9999907, 9993769
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