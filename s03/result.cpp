void sort2d(int (&array)[N][M]){
    int line[N*M] = {0};
    for (int i = 0; i<N; ++i){
        for (int j = 0; j<M; ++j){
            line[i*M+j] = array[i][j];
        }
    }
    int n = N*M;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (line[j] > line[j+1]) {
                int temp = line[j];
                line[j] = line[j+1];
                line[j+1] = temp;
            }
        }
    }
    for (int i = 0; i<n; ++i){
        int k = i%M;
        int l = i/M;
        array[l][k] = line[i];
    }
}