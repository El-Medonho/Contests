#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int n,k; cin >> n >> k;


    vector<int> pos_amigo_cima; //posiÃ§ao do amigo no lado de cima da mesa
    //lado de cima da mesa
    for(int i=0;i<n;i++)
    {
        int pessoa; cin >> pessoa;
        if(pessoa == 1) pos_amigo_cima.push_back(i);
    }

    vector<int> pos_amigo_baixo; //posiÃ§ao do amigo no lado de baixo da mesa
    //lado de baixo
    for(int i=0;i<n;i++)
    {
        int pessoa; cin >> pessoa;
        if(pessoa == 1) pos_amigo_baixo.push_back(i);
    }

    long long int resp =0;

    for(int i=0;i<k;i++)
    {
        resp += abs(pos_amigo_baixo[i] - pos_amigo_cima[i]);
    }
    cout << resp << '\n';
}