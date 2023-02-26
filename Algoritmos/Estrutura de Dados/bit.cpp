//fenwick tree
// bit[x] tem que ser indexada no 1, inclusive o ind

void upd(int ind, int val, vector<int> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}
int sum(int ind, vector<int> &bit){         //O(logn)
    int ans=0;
    while(ind){
        ans+=bit[ind];    
        ind-=ind&-ind;    
    }
    return ans;
}

// 2d fenwick tree
// bit[x][y] tem que ser indexada no 1, inclusive o ind

void upd(int x, int y, int val, vector<vector<int>> &bit){   //O(log²n)
    int ogy = y;
    while(x<=bit.size()-1){
        y = ogy;
        while(y<=bit[0].size()-1){
            bit[x][y]+=val;
            y+=y&-y;
        }
        x+=x&-x;
    }
}

int sum(int x, int y, vector<vector<int>> &bit){         //O(log²n)
    int ans=0;
    int ogy = y;
    while(x){
        y = ogy;
        while(y){
            ans+=bit[x][y];    
            y-=y&-y;
        }
        x-=x&-x;    
    }
    return ans;
}

// podemos criar uma bit de quantas dimensões quisermos utilizando a aplicação acima recursivamente