//Pollard-rho randomized factorization algorithm. Returns
//prime factors of a number, in arbitrary order (e.g. 2299 -> {11, 19, 11}).
//O(n^(1/4))

ull pollard(ull n) {
auto f = [n](ull x, ull k) { return modmul(x, x, n) + k; };
ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
while (t++ % 40 || gcd(prd, n) == 1) {
if (x == y) x = ++i, y = f(x, i);
if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
x = f(x, i), y = f(f(y, i), i);
}
return gcd(prd, n);
}
vector<ull> factor(ull n) {
if (n == 1) return {};
if (isPrime(n)) return {n};
ull x = pollard(n);
auto l = factor(x), r = factor(n / x);
l.insert(l.end(), r.begin(), r.end());
return l;
}