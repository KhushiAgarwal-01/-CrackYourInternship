class RandomizedCollection {
public:

    vector<int>arr;
    unordered_map<int,unordered_set<int>>mp;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans=true;
        if(mp.find(val)!=mp.end()){
            ans=false;
        }
            arr.push_back(val);
            mp[val].insert(arr.size()-1);
        
        return ans;
    }
    
    bool remove(int val) {
        bool ans=false;
        if(mp.find(val)==mp.end()){
            return false;
        }
        else{
            int i=*mp[val].begin();
            mp[val].erase(i);
            if(mp[val].empty()) mp.erase(val);

            if(i!=arr.size()-1){
                int last=arr[arr.size()-1];
                mp[last].erase(arr.size()-1);
                mp[last].insert(i);

                arr[i]=last;
            }
            arr.pop_back();

         
        }
        return true;
    }
    
    int getRandom() {
        if(arr.size()!=0)
     return arr[rand()%arr.size()];
     else 
     return -1;
    }

};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */