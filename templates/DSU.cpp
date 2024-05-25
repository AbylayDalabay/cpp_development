class UnionFind{
private:
    vector<int> p, rank;
public:
    UnionFind(int n){
        rank.assign(n, 0); p.assign(n, 0); 
        for(int i = 0;i < n;i++) 
            p[i] = i;
    }
    int FindSet(int i){
        return (i != p[i] ? p[i] = FindSet(p[i]) : i);
    }
    bool isSameSet(int i, int j){
        return FindSet(i) == FindSet(j);
    }
    void UnionSet(int i, int j){
        i = FindSet(i); j = FindSet(j);
        if(i == j) return;
        if(rank[i] == rank[j]) rank[i]++;
        if(rank[i] < rank[j]) swap(i, j);
        p[j] = i;
    }
};