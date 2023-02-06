

int exp(int b, int e){
int res=1;
while(e){
if(e&1) res*=b;
b*=b;
e>>=1;
}
return res;
}