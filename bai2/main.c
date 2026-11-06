#include <iostream>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    float **matrix = new float *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new float[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> *(*(matrix + i) + j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(*(matrix + i) + j)<<" ";
        }
        cout << endl;
    }
}
