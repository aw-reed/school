#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(){
    int x;

    vector<int> mylist;
    cin >> x;
    for (int i = 0; i < x; i++){
        int y;
        cin >> y;
        mylist.push_back(y);
    }

    int minimum = numeric_limits<int>::max();
    int maximum = numeric_limits<int>::min();

    for (int y : mylist){
        if (y < minimum){
            minimum = y;
        }
        if (y > maximum){
            maximum = y;
        }
    }

    cout << maximum << ";" << minimum << endl;

    return 0;
}
