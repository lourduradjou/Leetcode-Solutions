class RandomizedSet {
private:
    unordered_set<int> st;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        //val should not already be there in the set
        if(st.count(val) > 0)
            return false;
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        //val should be there to remove
        if(st.count(val) == 0)
            return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        auto it = st.begin();
        advance(it, rand() % st.size());
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */