int main(){
    // A : O(V^2 + VE + V^3 + Q)
    // B : O(V^2E + QV^2E )
    // if V<E : O(A) < O(B)
    int i, j, V=99, E=11;
    printf("%d\n", V);
    for(i=0; i < V; ++i){
        printf("%d ", E-(i%2==0));
        for(j=0; j < E-(i%2==0); ++j) printf("%d %d ",i==0?V-1:i-1,1);
        puts("");
    }
    int Q = 10;
    printf("%d\n", Q);
    while(Q--){
        printf("%d %d\n", 0, V-1);
    }
}
