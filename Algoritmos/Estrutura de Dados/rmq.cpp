#include "bits/stdc++.h"

using namespace std;

template<typename T, typename Cmp=less<T>>
struct rmq_t : private Cmp {
	int N = 0;
	vector<vector<T>> table; 
	const T& min(const T& a, const T& b) const { return Cmp::operator()(a, b) ? a : b; }
	rmq_t() {}
	rmq_t(const vector<T>& values) : N(int(values.size())), table(__lg(N) + 1) {
		table[0] = values;
		for (int a = 1; a < int(table.size()); ++a) {
			table[a].resize(N - (1 << a) + 1);
			for (int b = 0; b + (1 << a) <= N; ++b) 
				table[a][b] = min(table[a-1][b], table[a-1][b + (1 << (a-1))]); 
		}
	}
	T query(int a, int b) const { 
		int lg = __lg(b - a);
		return min(table[lg][a], table[lg][b - (1 << lg) ]);
	}
};