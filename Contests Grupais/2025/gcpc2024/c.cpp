#include <bits/stdc++.h>
#include <sys/time.h>
 
using namespace std;

#define f first
#define s second
#define pb push_back
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;
const int mxn = 1e5+5;
const int mxm = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// Returns -1 if a < b, 0 if a = b and 1 if a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

static int C;

template<int M, class B> struct A{
    int x;
    B b;
    A(int x = 0) : x(x), b(x) {}
    A(int x, B b) : x(x), b(b) {}
    A operator+(A o) {int y = x+o.x; return {y - (y>=M)*M, b+o.b};}
    A operator-(A o){int y = x-o.x; return {y + (y<0)*M, b-o.b};}
    A operator *(A o){return {(int)(1LL*x*o.x%M), b*o.b};}
    explicit operator ull() {return x^(ull) b << 21;}
    bool operator==(A o) const {return (ull)*this == (ull)o;}
    bool operator<(A o) const {return (ull)*this < (ull)o;}
};

typedef A<1000000007, A<1000000009, unsigned> > H;

struct Hashing{
    int n;
    vector<H> ha, pw;
    Hashing(string &str) : n((int)str.size()), ha(n+1), pw(n+1) {
        pw[0] = 1;
        for(int i=0; i<n; i++){
            ha[i+1] = ha[i] * C + str[i];
            pw[i+1] = pw[i]*C;
        }
    }
};

H hashString(string &str) {H h{}; for(char c:str) h=h*C+c; return h;}

signed cases(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    map<ull, int> freqs;
    for(int i=0; i<n; i++){
        string atual = "";
        map<char, int> freq;
        int cont = 0;
        for(int j=i; j<n; j++){
            string a = v[j];
            if(sz(a) == 1){
                int nao = 0;
                for(char c:a) if(!isalpha(c)) nao = 1;
                if(!nao){
                    //cout << a[0] << ' ' << freq[a[0]] << endl;
                    if(!freq.count(a[0])) freq[a[0]] = cont, a = (char)'('+cont++;
                    else a = (char)'('+freq[a[0]];
                }
            }
            if(atual.empty()) atual+=a;
            else {atual+=" "; atual+=a;}

            //cout << atual << endl;

            auto hash = (ull)hashString(atual);
            freqs[hash] = 1;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        map<char, int> freq;
        string atual = "";
        int cont = 0;
        for(int i=0; i<n; i++){
            string a = v[i];
            int nao = 0;
            if(sz(a) == 1){
                int nao = 0;
                for(char c:a) if(!isalpha(c)) nao = 1;
                if(!nao){
                    if(!freq.count(a[0])) freq[a[0]] = cont, a = (char)'('+cont++;
                    else a = (char)'('+freq[a[0]];
                }
            }
            if(atual.empty()) atual+=a;
            else {atual+=" "; atual+=a;}
        }
        auto hash = (ull)hashString(atual);
        if(freqs[hash]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

    }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t=1;

    timeval tp;
    gettimeofday(&tp, 0);
    C = (int)tp.tv_usec;
    assert((ull)(H(1)*2+1-3) == 0);

    //cin >> t;

    for(int i=1; i<=t; i++){
        //cout << "Case #" << i << ": ";
        cases();
    }
    return 0;
}