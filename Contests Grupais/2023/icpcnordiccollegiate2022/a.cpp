#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
    fastio;
    
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        int pos=0;
        for(int j=0; j<a.size(); j++){
            if(a[j]=='-'){
                pos=j;
                break;
            }
        }
        int x=stoi(a.substr(0, pos));
        int y=stoi(a.substr(pos+1, a.size()-(pos+1)+1));

        arr[i] = {x,y};
    }

    int last = 0; int end = -1;
    int a = 0; int b = 0;
    for(int i = 0; i < n; i++){
        int sum = arr[i].first + arr[i].second;
        if(end != -1 && sum > end){
            cout << "error " << i+1 << '\n';
            return 0;
        }
        if(sum == last && arr[i].first == a && arr[i].second == b) continue;
        if(sum < last){
            cout << "error " << i+1 << '\n';
            return 0;
        }
        else{
            if( ((sum+1)/2)%2 != ((last+1)/2)%2) swap(a,b);
            if(arr[i].first == 11 && arr[i].second == 11) {
                cout << "error " << i+1 << '\n';
                return 0;                
            }
            if(arr[i].first == 11 || arr[i].second == 11) end = sum;
            if( arr[i].first >= a && arr[i].second >= b) {
                a = arr[i].first; b = arr[i].second;
                last = sum;
                continue;
            }
            else{
                cout << "error " << i+1 << '\n';
                return 0;
            }
        }
    }

    cout << "ok\n";

    return 0;
}