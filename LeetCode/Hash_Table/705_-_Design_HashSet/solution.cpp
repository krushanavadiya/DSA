class MyHashSet {
public:
    vector<int> mp;
    MyHashSet() {
        mp=vector<int> (1000001, 0);
    }
    
    void add(int key) {
        mp[key]=1;
    }
    
    void remove(int key) {
        mp[key]=0;
    }
    
    bool contains(int key) {
        if(mp[key]==1) return true;
        else return false;
    }
};