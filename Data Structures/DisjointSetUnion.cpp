#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union
class disjointSet {
    public:
    vector<int> parent, rank;
    
    disjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    } 
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void union_sets(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent) return;
        
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};

int main() {
    int n = 10;
    disjointSet dsu(n);
    
    cout << dsu.find(1) << endl;
    cout << dsu.find(3) << endl;
    
    dsu.union_sets(1, 3);
    
    cout << dsu.find(1) << endl;
    cout << dsu.find(3) << endl;
    
    return 0;
}