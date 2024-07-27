class Solution {
    
    void solve(int k,vector<int>& arr,set<vector<int>>&st){
        
        if(k==arr.size()){
            st.insert(arr);
            return ;
        }
        for(int i=k;i<arr.size();i++)
        {
            swap(arr[i],arr[k]);
            solve(k+1,arr,st);
            swap(arr[i],arr[k]);
        }
        
        
    }
    
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>>st;
        solve(0,arr,st);
        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
        
    }
};