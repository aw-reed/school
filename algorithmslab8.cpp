#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<vector<int>>&s, int i, int j){
    if (i == j){
        cout << "A" << i - 1;
    } else {
        cout << "(";
        print(s, i, s[i][j]);
        print(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int matrixChain(vector<int>& dimensions){
    int n = dimensions.size() - 1;
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    for (int l = 2; l <= n; l++){
        for (int i = 1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++){
                int q = m[i][k] + m[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n] << endl;
    print(s, 1, n);
    cout << endl;
    return m[1][n];
}

int main(){
    int matrices;
    cin >> matrices;
    vector<int> dimensions(matrices + 1);
    for (int i = 0; i <= matrices; i++){
        cin >> dimensions[i];
    }
    matrixChain(dimensions);
    return 0;
}
