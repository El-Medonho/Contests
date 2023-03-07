vll tree(0); vll arr(0);
int sti = 0;

void initialize(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    sti = iterador;
    iterador*=2;
    tree.resize(iterador, -INFL);     //value of every node should be neutral value of op when itilializing

    for(int i = sti; i < sti*2; i++){
        int l = (i-sti);
        if(l < arr.size()) tree[i] = arr[l];
    }
 
    for(int i = sti/2; i > 0; i/=2){
        for(int j = i; j < i*2; j++){
            tree[j] = max(tree[2*j], tree[2*j+1]);      //op
        }
    }
}

void upd(int id, ll val){
    id += sti;
    tree[id] = val;
    for(int i = id/2; i > 0; i/=2) tree[i] = max(tree[2*i], tree[2*i+1]);       //op
}

ll query(int lo, int hi) {
	ll ra = -INFL, rb = -INFL;      //value
	for (lo += sti, hi += sti + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = max(ra, tree[lo++]);       //op
		if (hi & 1) rb = max(rb, tree[--hi]);       //op
	}
	return max(ra, rb);     //op
}