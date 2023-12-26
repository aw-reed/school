#include<iostream>
#include<vector>
#include<climits>

using namespace std;

pair<int, vector<int>> rodCutting(int n, const vector<int>& prices){
    vector<int> maxRev(n+1, 0);
    vector<int> cutLen(n+1, 0);

    for (int i = 1; i <= n; i++){
        int maxVal = INT_MIN;
        for (int j = 1; j <= i; j++){
            if (prices[j - 1] + maxRev[i - j] > maxVal){
                maxVal = prices[j - 1] + maxRev[i - j];
                cutLen[i] = j;
            }
        }
        maxRev[i] = maxVal;
    }

    vector<int> optimalCut;
    int remainingLength = n;
    while (remainingLength > 0){
        optimalCut.push_back(cutLen[remainingLength]);
        remainingLength -= cutLen[remainingLength];
    }

    return make_pair(maxRev[n], optimalCut);
}

int main(){
    int n;
    cin >> n;
    vector<int> p(n);

    for (int i = 0; i < n; i++){
        cin >> p[i];
    }

    pair<int, vector<int>> result = rodCutting(n, p);

    cout << result.first << endl;

    for (int i = 0; i < result.second.size(); i++){
        cout << result.second[i] << " ";
    }

    cout << "-1" << endl;

    return 0;
}
