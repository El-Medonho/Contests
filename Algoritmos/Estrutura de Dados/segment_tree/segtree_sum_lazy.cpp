vll tree(0); vll arr(0); vll lazy(0);

void unlazy(int node, int l, int r){
    if(lazy[node]){
        tree[node]=(r-l+1)*lazy[node];   //change op
        if(l!=r){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
}

void build(int node, int l, int r){
    if(l==r){
        tree[node]=arr[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node]=tree[2*node]+tree[2*node+1];     //change op
}

void initialize(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    iterador*=2;
    tree.resize(iterador, 0);     //value of every node should be neutral value of op when itilializing
    lazy.resize(iterador, 0);
    build(1, 0, arr.size() - 1);
}

void upd(int node, int l, int r, int a, int b, int val){
    unlazy(node, l, r);
    if(a>r || b<l) return;
    if(l>=a && r<=b){
        lazy[node]=val;
        unlazy(node, l, r);
        return;
    }
    int mid=(l+r)>>1;
    upd(2*node, l, mid, a, b, val);
    upd(2*node+1, mid+1, r, a, b, val);
    tree[node]=tree[2*node]+tree[2*node+1];   //change op
}

int query(int node, int l, int r, int a, int b){
    unlazy(node, l, r);
    if(a>r || b<l) return 0;    //change value
    if(a<=l && b>=r){
        return tree[node];
    }
    int mid=(l+r)>>1;
    return query(2*node, l, mid, a, b) + query(2*node+1, mid+1, r, a, b);   // change op
}

int consult(int node, int l, int r, int id){
    unlazy(node,l,r);
    if(l == r){
        return tree[node];
    }
    int mid=(l+r)>>1;
    if(l<=id && mid>=id){
        return consult(2*node,l,mid,id);
    }else{
        return consult(2*node+1, mid+1, r, id);
    }
}