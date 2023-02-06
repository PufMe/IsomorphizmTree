#include <bits/stdc++.h>
#include <chrono>
using namespace std;


struct node{
    int id;
    node* parent;
    vector<node> children;
};

void findTreeCenter(vector<int>& tree) {
    int nodes_count = tree.size();
    vector<int> degree(nodes_count, 0);
    vector<int> leaves;


    while (leaves.size() < nodes_count){
        for(int i = 0; i < nodes_count; ++i) {
            for (int j = 0; j < nodes_count; ++j) {
                if (degree[i] == -2 || degree[j] == -2) {
                    continue;
                }
                if (i == tree[j]) {
                    degree[i] += 1;
                }
            }
            if( i != 0 && (degree[i] != -2) && (degree[tree[i]] != -2)){
                degree[i] += 1;
            }
            if(degree[i] == 1 || degree[i] == 0){
                leaves.push_back(i);
            }
        }
        //удаление
        for(int i = 0; i < nodes_count; ++i){
            if(degree[i] == -2){
                continue;
            }else if(degree[i] == 1){
                degree[i] = -2;
            }else{
                degree[i] = 0;
            }
        }
    }

}


int main(){
    auto start = chrono::steady_clock::now();
    std::vector<int> tree1 = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    findTreeCenter(tree1);
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;


}