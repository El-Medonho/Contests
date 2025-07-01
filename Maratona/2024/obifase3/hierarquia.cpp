#include<bits/stdc++.h>

using namespace std;

void mudar_hierarquia(int v_atual,int novo_representante, vector<vector<int>> &sons, vector<int> &representante)
{
    if(representante[v_atual] != v_atual) return;
    representante[v_atual] = novo_representante;
    for(int v : sons[v_atual]) mudar_hierarquia(v,novo_representante,sons,representante);
}

int encontrar_representante(int v_atual, vector<int> &representante)
{
    if(representante[v_atual] == v_atual) return v_atual;
    return representante[v_atual] = encontrar_representante(representante[v_atual], representante);
}

int entregar_relatorio(int v_atual,int quant,vector<vector<int>> &ancestors_pow2, vector<int> &representante)
{
    if(representante[v_atual] != v_atual)
    {
        v_atual = encontrar_representante(v_atual,representante);
        quant--;
    }
    while(quant != 0)
    {
        int max_pow_2 = 0;
        for(int i=0; 1<<i <= quant;i++) max_pow_2 = i;
        v_atual = ancestors_pow2[v_atual][max_pow_2];
        quant -= 1<<max_pow_2;
    }
    return v_atual;
}

int main(void)
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    int max_pow_2 = 0;
    for(int i=0; 1<<i <= n;i++) 
    {
        max_pow_2 = i;
    }
    vector<vector<int>> ancestors_pow2(n,vector<int>(max_pow_2+1));
    vector<vector<int>> sons(n);
    vector<int> representante(n);
    vector<bool> mudanca_feita(n,false);

    ancestors_pow2[0][0] = 0;
    representante[0] = 0;
    for(int i=1; i<n; i++)
    {
        cin >> ancestors_pow2[i][0];
        ancestors_pow2[i][0]--;
        sons[ancestors_pow2[i][0]].push_back(i);
        representante[i] = i;
    }

    //binary lifting
    for(int pow=1;pow<=max_pow_2;pow++)
    {
        for(int i=0;i<n;i++)
        {
            int ancestral_intermediario = ancestors_pow2[i][pow-1];

            ancestors_pow2[i][pow] = ancestors_pow2[ancestral_intermediario][pow-1]; 
            
            /* 
            o vÃ©rtice que estÃ¡ 2^pow acima do vÃ©rtice atual 
            Ã© o vÃ©rtice que estÃ¡  2^(pow-1) acima do vÃ©rtice que estÃ¡ 2^(pow-1) acima do vÃ©rtice atual.
            Isto pois 2^x-1 + 2^x-1 = 2^x
            */
        }
    }

    int q; cin >> q;

    for(int i=0;i<q;i++)
    {
        int comando; cin >> comando;
        if(comando == 1)
        {
            int nobre,quantos_acima; cin >> nobre >> quantos_acima; nobre--;
            cout << entregar_relatorio(nobre,quantos_acima,ancestors_pow2,representante)+1 << '\n';
        }
        else
        {
            int nobre_novo_representante; cin >> nobre_novo_representante; nobre_novo_representante--;
            if(mudanca_feita[nobre_novo_representante]) continue;
            mudar_hierarquia(nobre_novo_representante,nobre_novo_representante,sons,representante);
            mudanca_feita[nobre_novo_representante] = true;
        }
    }
    //cout << representante[8] << ' ' << representante[7] << '\n';
    return 0;

}