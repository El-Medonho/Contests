// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄

#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

template<typename T> T minv(T a, T m) {
	a %= m; assert(a);
	return a == 1 ? 1 : T(m - ll(minv(m, a)) * m / a);
}
template<unsigned M_> struct modnum {
	static constexpr unsigned M = M_; using num = modnum;
	using ll = long long; using ull = unsigned long long; unsigned x;
	num& norm(unsigned a){x = a<M ? a:a-M;return *this;}
	constexpr modnum() : x(0U) {}
	constexpr modnum(unsigned a) : x(a % M) {}
	constexpr modnum(ull a) : x(a % M) {}
	constexpr modnum(int a) : x(((a %= int(M))<0) ? (a+int(M)):a) {}
	constexpr modnum(ll a) : x(((a %= ll(M))<0) ? (a+ll(M)):a) {}
	explicit operator int() const { return x; }
	num& operator+=(const num& a){ return norm(x+a.x); }
	num& operator-=(const num& a){ return norm(x-a.x+M); }
	num& operator*=(const num& a){ return norm(unsigned((ull(x)*a.x) % M)); }
	num& operator/=(const num& a){ return (*this *= a.inv());}
	template<typename T> friend num operator+(T a, const num& b){ return (num(a) += b); }
	template<typename T> friend num operator-(T a, const num& b){ return (num(a) -= b); }
	template<typename T> friend num operator*(T a, const num& b){ return (num(a) *= b); }
	template<typename T> friend num operator/(T a, const num& b){ return (num(a) /= b); }
	num operator+() const { return *this; }
	num operator-() const { return num() - *this; }
	num pow(ll e) const {
		if (e < 0) { return inv().pow(-e); } num b = x, xe = 1U;
		for (; e; e >>= 1) { if (e & 1) xe *= b; b *= b; }
		return xe;
	}
	num inv() const { return minv(x, M); }
	friend num inv(const num& a) { return a.inv(); }
	explicit operator bool() const { return x; }
	friend bool operator==(const num& a, const num& b){return a.x == b.x;}
	friend bool operator!=(const num& a, const num& b){return a.x != b.x;}
};

template <typename T> struct root_of_unity {};
//(MOD,3) := (M1:897581057),(M3:985661441),(M5:935329793)
using M0 = modnum<998244353U>;///start-hash
using M1 = modnum<(unsigned int)(897581057)>;
constexpr unsigned primitive_root(unsigned M) {
	if (M == 880803841U) return 26U; // (M2)
	else if (M == 943718401U) return 7U; // (M4)
	else if (M == 918552577U) return 5U; // (M6)
	else return 3U;
}
template<unsigned MOD> struct root_of_unity<modnum<MOD>> {
	static constexpr modnum<MOD> g0 = primitive_root(MOD);
	static modnum<MOD> f(int K) {
		assert((MOD-1)%K == 0); return g0.pow((MOD-1)/K);
	}
};///end-hash 
inline int nxt_pow2(int s) { return 1 << (s > 1 ? 32 - __builtin_clz(s-1) : 0); }
template<typename T> struct FFT {
	vector<T> rt; vector<int> rev;
	FFT() : rt(2, T(1)) {}
	void init(int N) {///start-hash
		N = nxt_pow2(N);
		if (N > int(rt.size())) {
			rev.resize(N); rt.reserve(N);
			for (int a = 0; a < N; ++a)
				rev[a] = (rev[a/2] | ((a&1)*N)) >> 1;
			for (int k = int(rt.size()); k < N; k *= 2) {
				rt.resize(2*k);
				T z = root_of_unity<T>::f(2*k);
				for (int a = k/2; a < k; ++a)
					rt[2*a] = rt[a], rt[2*a+1] = rt[a] * z;
			}
		}
	}///end-hash
	void fft(vector<T>& xs, bool inverse) const {///start-hash
		int N = int(xs.size());
		int s = __builtin_ctz(int(rev.size())/N);
		if (inverse) reverse(xs.begin() + 1, xs.end());
		for (int a = 0; a < N; ++a) {
			if (a < (rev[a] >> s)) swap(xs[a], xs[rev[a] >> s]);
		}
		for (int k = 1; k < N; k *= 2) {
			for (int a = 0; a < N; a += 2*k) {
				int u = a, v = u + k;
				for (int b = 0; b < k; ++b, ++u, ++v) {
					T z = rt[b + k] * xs[v];
					xs[v] = xs[u] - z, xs[u] = xs[u] + z;
				}
			}
		}
		if (inverse)
			for (int a = 0; a < N; ++a) xs[a] = xs[a] * inv(T(N));
	}///end-hash
	vector<T> convolve(vector<T> as, vector<T> bs) {///start-hash
		int N = int(as.size()), M = int(bs.size());
		int K = N + M - 1, S = nxt_pow2(K); init(S);
		if (min(N, M) <= 64) {
			vector<T> res(K);
			for (int u = 0; u < N; ++u) for (int v = 0; v < M; ++v)
				res[u + v] = res[u + v] + as[u] * bs[v];
			return res;
		} else {
			as.resize(S), bs.resize(S);
			fft(as, false); fft(bs, false);
			for (int i = 0; i < S; ++i) as[i] = as[i] * bs[i];
			fft(as, true); as.resize(K); return as;
		}
	}///end-hash
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    FFT<M0> fft;
	FFT<M1> fft1;
    
    int n,k; cin >> n >> k;

	vector<M0> arr(1005);
	vector<M1> arr1(1005);

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		arr[x] = 1; arr1[x] = 1;
	}

	vector<M0> a(2); a[0]= 1;
	vector<M1> a1(2); a1[0]= 1;

	while(k){
		if(k&1){
			a = fft.convolve(a, arr);
			a1 = fft1.convolve(a1, arr1);
		}
		arr = fft.convolve(arr, arr);
		arr1 = fft1.convolve(arr1, arr1);

		k>>=1;
	}

	for(int i = 1; i < a.size(); i++){
		if(a[i] != 0 || a1[i] != 0) cout << i << ' ';
	}
	cout << endl;


    return 0;
}