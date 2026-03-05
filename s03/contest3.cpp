# include <iostream>

using namespace std;

#define N 4
#define M 3
void readArray(int (&arr)[N]){
    for (int i=0; i<N; ++i){
        int a;
        cin>>a;
        arr[i]=a;
    }
}

void printArray(int (&arr)[N]){
    if (N==1){
        std::cout<<arr[0]<<std::endl;
        return;
    }
    for (int i=0; i<N-1; ++i){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<arr[N-1];
}

void reverseArray(int (&arr)[N]){
    for (int i = 0; i<(N/2); ++i){
        std::swap(arr[i], arr[N-1-i]);
    }
}
void shiftArrayRight(int (&arr)[N]){
    for (int i = 0; i<N-1; ++i){
        std::swap(arr[i], arr[i+1]);
    }
}

// void moveNegativeToEnd(int (&array)[N]){
//     for (int i = 0; i<N; ++i){
//         if ((arr[i]>=0) and (arr[i+1]<0)){
//             std::swap(arr[i, arr[i+1]]);
//         }
//     }
// }

// int main(){
//     int arr[N] = {0, };
//     readArray(arr);
//     shiftArrayRight(arr);
//     printArray(arr);
//     return 0;
// }

// void printTransposed(int (&array)[N][M]){
//     int trans[M][N];
//     for (int i = 0; i<M; ++i){
//         for (int j = 0; j<N; ++j){
//             trans[i][j] = array[j][i];
//         }
//     }
//     for (int i = 0; i<M; ++i){
//         for (int j = 0; j<N; ++j){
//             std::cout<<trans[i][j]<<' ';
//         }
//         std::cout<<std::endl;
//     }
// }

int findLastZero(int (&array)[N]){
    int low = 0;
    int high = N-1;
    int mid = 0;
    int res = -1;
    while (high >= low){
        mid = low + (high-low)/2;
        if (array[mid]==0){
            res = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return res;
}

void moveNegativeToEnd(int (&array)[N]){
    for (int i = 0; i<N; ++i){
        for (int j = 0; j<N-1; ++j){
            if ((array[j]<0) and (array[j+1]>=0)){
                std::swap(array[j], array[j+1]);
            }
        }
    }
}

int find_unique(int (&a)[N]){
    int res = 0;
    for (int i = 0; i<N; ++i){
        res ^= a[i];
    }
    return res;
}

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
int main(){
    int arr[N][M] = {{6, 5, 4}, {9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    sort2d(arr);
    for (int i = 0; i<N; ++i){
        for (int j = 0; j<M; ++j){
            cout<<arr[i][j]<<' ';
        }
    }
    return 0;
}