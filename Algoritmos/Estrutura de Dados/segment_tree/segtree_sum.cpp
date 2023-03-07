vll tree(0); vll arr(0);
int sti = 0;

void build(int node, int l, int r){
    if(l == r){
        tree[node] = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node] = tree[2*node] + tree[2*node+1];     //change op
}

void initialize(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    sti = iterador;
    iterador*=2;
    tree.resize(iterador, 0);     //value of every node should be neutral value of op when itilializing
    build(1, 0, arr.size() - 1);
}

void upd(int node, int l, int r, int id, int val){
    if(l == r){
        tree[node] = val;
        arr[l] = val;
        return;
    }
    int mid = (l+r)>>1;
    if(l <= id && id <= mid){
        upd(2*node, l, mid, id, val);
    } else{
        upd(2*node+1, mid+1, r, id, val);
    }
    tree[node] = tree[2*node] + tree[2*node+1]; //change op
}

ll query(int node, int l, int r, int a, int b){     //call it like query(1, 0, sti-1, a, b)
    if(b < l || a > r) return 0;        //return neutral value of op
    if(l >= a && r <= b) return tree[node];
    int mid = (l+r)>>1;
    return query(2*node, l , mid, a, b) + query(2*node+1, mid+1, r, a, b);  //change op
}