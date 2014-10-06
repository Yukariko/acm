int main(){
    // A : O(V^2 + VE + V^3 + Q)
    // B : O(V^2E + QV^2E )
    // if V<E : O(A) < O(B)
    int i, j, V=10, E=6;
    printf("%d\n", V);
    for(i=0; i < V; ++i){
        printf("%d ", E);
        for(j=0; j < E; ++j) printf("%d %d ",i==0?V-1:j,V*100-i*100-j*10);
        puts("");
    }
    int Q = 10;
    printf("%d\n", Q);
    while(Q--){
        printf("%d %d\n", 0, V-1);
    }
}
