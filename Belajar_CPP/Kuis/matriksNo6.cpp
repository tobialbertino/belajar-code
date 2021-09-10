#include <iostream>

using namespace std;

int main(){
    int matriks1[10][10], matriks2[10][10], hasil[10][10];
    int i, j, k, m, n, p, q, jumlah = 0;
    cin >> m;
    cin >> n;
    cin >> p;
    cin >> q;

    if(n != p) {
        cout << "something.\n" ;
    } 
    else {
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                cin >> matriks1[i][j];
            }
        }
        for (i = 0; i < p; i++) {
            for (j = 0; j < q; j++) {
                cin >> matriks2[i][j];
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < p; j++) {
                for (k = 0; k < q; k++){
                    jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
                }
                hasil[i][j] = jumlah;
                jumlah = 0;
            }
        }
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                cout << hasil[i][j] << "\t";
            }
            cout << endl;
        }
    }
    return 0;
}