#include<iostream>
#include<list>
#include<vector>

using namespace std;

class HashTable {
    public:
        HashTable(int size) : table(size){}

        void insert(int key){
            int index = hash(key);
            table[index].push_front(key);
        }

        string search(int key){
            int index = hash(key);
            int listIndex = 0;

            for(const auto& k : table[index]){
                if (k == key){
                    return to_string(key) + ":FOUND_AT" + to_string(index) + "," + to_string(listIndex) + ";";
                }
                listIndex++;
            }
            return to_string(key) + ":NOT_FOUND;";
        }

        string remove(int key){
            int index = hash(key);
            int listIndex = 0;

            for(auto it = table[index].begin(); it != table[index].end(); it++){
                if (*it == key){
                    table[index].erase(it);
                    return to_string(key) + ":DELETED;";
                }
                listIndex++;
            }
            return to_string(key) + ":DELETE_FAILED;";
        }

        void printTable(){
            for (int i = 0; i < table.size(); i++){
                cout << i << ":";
                for (const auto& key : table[i]){
                    cout << key << "->";
                }
                cout << ";" << endl;
            }
        }

    private:
    vector<list<int>> table;

    int hash(int key){
        return key % table.size();
    }
};

int main(){
    int m;
    cin >> m;
    HashTable hashTable(m);

    while (true) {
        char op;
        cin >> op;

        if (op == 'i'){
            int key;
            cin >> key;
            hashTable.insert(key);
        } else if (op == 's'){
            int key;
            cin >> key;
            cout << hashTable.search(key) << endl;
        } else if (op == 'd'){
            int key;
            cin >> key;
            cout << hashTable.remove(key) << endl;
        } else if (op == 'o'){
            hashTable.printTable();
        } else if (op == 'e'){
            break;
        }
    }
    return 0;
}
