#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(false) , cin.tie(nullptr)

int main(){
    fastio;
    int n,c;
    cin >> n >> c;

    vector<string> words;
    vector<int> change;
    words.resize(n);
    change.resize(n);

    int record = 0;
    string word;

    for (int i = 0; i < n; i++){
        cin >> words[i];
        change[i] = words[i].find('*');
    }

    for (int i = 0; i < 26; i++){
        char currchar = char(i - 'a');
        unordered_map<string, int> freq;
        freq.reserve(10000);

        for(int j = 0; j < n; j++){
            string newword = words[j];
            newword.replace(change[j], 1, to_string(currchar));
            freq[newword] += 1;
            if (freq[newword] > record){
                record = freq[newword];
                word = newword;
            }
            else if (freq[newword] == record){
                for (char l : newword){
                    for (char m : word){
                        if (l < m) word = newword;
                    }
                }
            }
        }
    }

    cout << record << " " << word << "\n";
    return 0;
}