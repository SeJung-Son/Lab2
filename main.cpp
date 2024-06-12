#include<iostream>
#include <vector>

using namespace std;

void print_subset(vector<int> original_vec, vector<int> copied, int how_many) {
    if (how_many == 0) {
        for (auto elem : copied) {
            cout << elem << " ";
        }
        cout << endl;
        return;
    }

    auto begin = original_vec.begin();

    for (int i = 0; i <= original_vec.size() - how_many; i++) {
        int mem = original_vec[i];
        vector<int> new_vec2 = copied;
        new_vec2.push_back(mem);
        vector<int> new_vec(begin + i + 1, original_vec.end());
        print_subset(new_vec, new_vec2, how_many - 1);
    }
}
 
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> initial, original; 
    for (int i = 0; i < N; i++) {original.push_back(i+1);}
    print_subset(original, initial, M);
    return 0;
}

