#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    if(n == 1) {
        cout << "POSSIBLE\n";
        cout << "1 1\n";
        return 0;
    }

    if(n % 10 != 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << "POSSIBLE\n";

    int x = 0, y = -2;

    for(int i = 0; i < n; i += 10) {
        x += 1;
        y += 3;
        cout << x << ' ' << y << '\n';

        x += 1;
        y += 3;
        cout << x << ' ' << y << '\n';

        x += 3;
        y -= 1;
        cout << x << ' ' << y << '\n';

        x += 3;
        y -= 1;
        cout << x << ' ' << y << '\n';

        x += 1;
        y += 3;
        cout << x << ' ' << y << '\n';

        x -= 3;
        y += 1;
        cout << x << ' ' << y << '\n';

        x -= 3;
        y += 1;
        cout << x << ' ' << y << '\n';

        x += 1;
        y += 3;
        cout << x << ' ' << y << '\n';

        x += 3;
        y -= 1;
        cout << x << ' ' << y << '\n';

        x += 3;
        y -= 1;
        cout << x << ' ' << y << '\n';
    }
}