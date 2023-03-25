ll expo(ll b, ll e){
    ll res=1;
    while(e){
        if(e&1) res*=b;
        b*=b;
        e >>= 1;
    }
    return res;
}

ll expo(ll b, ll e, ll m){
    ll res=1;
    while(e){
        if(e&1) res=mod(res*b, m);
        res = mod(res,m);
        b=mod(b*b,m);
        b = mod(b,m);
        e >>= 1;
    }
    return res;
}