#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int list[10];

    char str[40];

    vector<int> v;

    int n; cin >> n;

    for(int i = 0; i<n; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }

    cout << v.size() << '\n';

    v.pop_back();

    string s;

    cin >> s;
    s[1] = 'a';
    v[9] = 10;

    string v2;

    s = v2 + s;

    int quatro = '4'-'0';

    set<int> st;

    for(int i = 0; i < v.size(); i++){
        st.insert(v[i]);
    }

    st.erase(10);
    st.size();

    st.lower_bound(5);

    lower_bound();
    upper_bound();
    binary_search();

    map<string, char> m;

    pair<int, int> p;

    pair<vector<set<int>>>, string>

    p = make_pair(18, 84);

    p = {18, 84};


    m.insert({"fred", 'y'})
    m["alexandre"] = 'k';

    cout << m["fred"] << '\n';



    sort(list, list+10);

    sort(v.begin(), v.end());

    binary_search(list, list+10, 4);

    lower_bound(v.begin(), v.end(), 10);

    int *aux;

    cout << *aux;

    cout << lower_bound(v.begin(), v.end(), 10) - v.begin() << '\n';

    cout << *lower_bound(v.begin(), v.end(), 10) << '\n'

    

    return 0;
}