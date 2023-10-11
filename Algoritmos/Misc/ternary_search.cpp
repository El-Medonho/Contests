//ternary search in integer
//USAGE: int ind = ternSearch(0,n-1,[&](int i){return a[i];});

template<class F>
int ternSearch(int a, int b, F f) {
    assert(a <= b);
    while (b - a >= 5) {
        int mid = (a + b) / 2;
        if (f(mid) < f(mid+1)) a = mid; // (A)
        else b = mid+1;
    }
    for(int i = a+1; i <= b; ++i)
        if (f(a) < f(i)) a = i; // (B)
    return a;
}

double ternary(double l, double r){
    int cont=200;
    while(cont--){
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
        double f1=f(m1);
        double f2=f(m2);
        if(f1<f2){
            l=m1;
        }else{
            r=m2;
        }
    }
    return l;
}