#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(500, 1e8);

void play_to_pos(ll cnt, vector<ll>& a, int pos) {
    int n = a.size();

    ll pair_pos_num = 0;
    for(int i = pos; i >= 0; i-= 2) {
        pair_pos_num <<= 1;
        pair_pos_num += a[i];
    }
    // cout << pair_pos_num << '\n';
    pair_pos_num += cnt;

    for(int i = 0, pos = 0; i < 64; i++, pos += 2) {
        a[pos] = bool(pair_pos_num&(1ll<<i));
    }

    for(int i = 0, pos = 0; i < 64; i++, pos += 2) {
        if(pos+1 > n) break;
        a[pos+1] += cnt/(1ll<<(i+1));
    }

    // ll last_cycles = 0;

    // vector<int> cycles(100);
    // ll or_cnt = cnt;

    // for(int i = 100, pot = 100/2+1; i >= 0; i-= 2, pot/=2) {

    //     a[i] = cnt/pot;last_cycles = cnt % cycle > (cycle/2) ? 1 : 0;
    // }

    // for(int i = 0; i < pos-2; i++) {
    //     if(i%2 == 0) {
    //         int pot = (1ll<<(i/2+1));
    //         a[i] = cnt/pot;last_cycles = cnt % cycle > (cycle/2) ? 1 : 0;
    //         if(cycle > cnt) break;
    //     }else {
    //         a[i] += last_cycles;
    //     }
    // }
}

void play_games(ll cnt, vector<ll>& a, int pos) {
    int n = a.size();
    ll last_cycles = 0;
    for(int i = 0; i < pos-2; i++) {
        if(i%2 == 0) {
            int cycle = (1ll<<(i/2+1));
            // cout << cycle << ' ' << cnt << endl;
            // cout << "here2" << endl;
            a[i] = last_cycles = cnt % cycle > (cycle/2) ? 1 : 0;
            if(cycle > cnt) break;
        }else {
            a[i] += last_cycles;
        }
    }

    if(pos != -1 && cnt > 0) {
        if(0 <= pos-2 && pos-2 < n) a[pos-2];
        if(0 <= pos-1 && pos-1 < n) a[pos-1]++;
        if(0 <= pos && pos < n) a[pos]++;
    }
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<ll> a(n);
    for(ll& ai : a) cin >> ai;

    ll game = 1, pos = 0;

    for(; game <= t; game *= 2, pos += 2) {
        play_to_pos(game-(game/2)-1, a, pos);

        // cout << "before game " << game << ": ";
        // for(ll& ai : a) cout << ai << ' ';
        // cout << '\n';
        
        int hand = 1;

        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                a[i]++;
                hand--;
                if(hand == 0) break;
            }else {
                a[i]++;
                hand--;
                if(hand == 0) {
                    hand = a[i];
                    a[i] = 0;
                }
            }
        }

        // cout << "after game " << game << ": ";
        // for(ll& ai : a) cout << ai << ' ';
        // cout << '\n';
    }

    // cout << "here: " << t << ' ' << game << '\n';
    play_to_pos(t-(game/2), a, 60);

    for(ll ai : a) cout << ai << ' ';
    cout << '\n';

    return 0;
}