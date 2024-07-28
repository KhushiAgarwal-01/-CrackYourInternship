class Solution {

    void findpse(vector<int>& heights,vector<int>& pse,int n){
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) pse[i]=0;
            else pse[i]=st.top()+1;
            st.push(i);
        }
    }

     void findnse(vector<int>& heights,vector<int>& nse,int n){
        
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) nse[i]=n-1;
           else  nse[i]=st.top()-1;

           st.push(i);
        }
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n,-1);
        vector<int>nse(n,n);
        findpse(heights,pse,n);
        findnse(heights,nse,n);
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]+1));
        }
        return maxi;

    }
};