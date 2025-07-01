#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

const int mxn = 1e5+5;

typedef long long ll;
typedef unsigned long long ull;

struct SA{
    int n;
    string s;
    vector<int> sa, lcp, pos, rpos;
    
    vector<int> suffix_array(){
        s.push_back('$');
        int n = (int)s.size(), N = max(n, 260);
        vector<int> sa(n), rank(n);

        for(int i=0; i<n; i++) sa[i]=i, rank[i]=s[i];

        for(int k=0; k<n; k?k*=2:k++){
            vector<int> nsa(sa), nrank(n), cnt(N);

            for(int i=0; i<n; i++) nsa[i]=(nsa[i]-k+n)%n, cnt[rank[i]]++;
            for(int i=1; i<N; i++) cnt[i]+=cnt[i-1];
            for(int i=n-1; i+1; i--) sa[--cnt[rank[nsa[i]]]] = nsa[i];

            for(int i=1, r=0; i<n; i++) nrank[sa[i]] = r += rank[sa[i]] != rank[sa[i-1]] || rank[(sa[i]+k)%n] != rank[(sa[i-1]+k)%n];

            rank = nrank;
        }
        s.pop_back();
        return vector<int>(sa.begin()+1, sa.end());
    }

    SA(string s) : s(s), n((int)s.size()), pos(n), rpos(n) {
        sa = suffix_array();
        for(int i=0; i<n; i++) pos[sa[i]] = i;
    }

    int bb(int atual, string &x){
        int l = 0, r = n-1, resp = 0;
        int m = (int)x.size();
        while(l<=r){
            int mid = (l+r)>>1;

            int who = sa[mid];
            
            int eval = 0, cont = 0;// 1 maior, -1 menor e 0 igual
            for(int i=0; who+i<n && atual+i<m; i++){
                if(x[atual+i]>s[who+i]){
                    eval = 1;
                    break;
                }else if(x[atual+i]<s[who+i]){
                    eval = -1;
                    break;
                }else{
                    cont++;
                }
            }
            resp = max(resp, cont);
            if(eval==-1){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return resp;
    }
};

static int C;
template<int M, class B> struct A{
    int x;
    B b;
    A(int x=0) : x(x), b(x) {}
    A(int x, B b) : x(x), b(b) {}
    A operator+(A o) {int y = x+o.x; return {y - (y>=M)*M, b+o.b};}
    A operator-(A o) {int y = x-o.x; return {y + (y<0)*M, b-o.b};}
    A operator*(A o) {return {(int) (1LL*x*o.x%M), b*o.b};}
    explicit operator ull() {return x ^ (ull) b << 21; }
    bool operator==(A o) const {return (ull)*this == (ull)o;}
    bool operator<(A o) const {return (ull)*this<(ull)o;}
};
typedef A<1000000007, A<1000000009, unsigned> > H;

struct Hashing{
    int n;
    vector<H> ha, pw;
    Hashing(string &str) : n((int)str.size()), ha(n+1), pw(n+1) {
        pw[0]=1;
        for(int i=0; i<n; i++){
            ha[i+1] = ha[i]*C + str[i];
            pw[i+1] = pw[i] * C;
        }
    }
    H range(int a, int b){
        return ha[b] - ha[a] * pw[b-a];
    }
};

#include<sys/time.h>

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    timeval tp;
    gettimeofday(&tp, 0);
    C = (int)tp.tv_usec;
    string ss;

    cin >> ss;

    SA sa = SA(ss);

    int q;
    cin >> q;

    while(q--){
        string a;
        cin >> a;

        //auto ha = Hashing(a);

        int atual = 0, resp=0;
        //set<ull> sla;
        while(atual<(int)a.size()){
            auto ans = sa.bb(atual, a);

            //cout << ans.first << ' ' << ans.second << endl;
            if(!ans){
                resp = -1;
                break;
            }

            //sla.insert((ull)ha.range(atual, atual+ans));
            resp++;
            atual+=ans;
        }
        if(resp==-1) cout << -1 << endl;
        else cout << resp << endl;
        // sa.bb(2, a);
        // cout << sa.bb(2, a).f << endl;


    }

    return 0;
}