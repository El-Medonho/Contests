#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t,n;
    cin >> t;
    vector<long long> vec;
    vector<long long> answer;
    long long int num;

    for(int init = 0; init < t; init ++){

        cin >>n;
        answer.clear();
        vec.clear();
        for(int i=0; i<n-1; i++){
            cin >> num;
            vec.push_back(num);
        }

        bool first = true;
        for(int i = 0; i < n-2; i ++){

            if(vec[i] < vec[i+1] && i == 0){
                answer.push_back(vec[i]);
                answer.push_back(0);
                first = false;
            }

            else if(vec[i] < vec[i+1] && first && i != 0){
                answer.push_back(0);
                answer.push_back(vec[i]);
                first = false;
            }

            else if(vec[i] < vec[i+1] && !first){
                answer.push_back(vec[i]);
            }

            else if(vec[i] == vec[i+1]){
                answer.push_back(vec[i]);
            }

            else if(vec[i] > vec[i+1]){
                answer.push_back(vec[i+1]);
            }
            
        }
        answer.push_back(vec[vec.size() - 1]);
        for(int i = 0; i < n - answer.size(); i ++){
            answer.push_back(0);
        }
        for(int i=0;i<n-1;i++){
            cout << answer[i] << ' ';
        }
        cout << answer[n-1] << '\n';
        
    }
}