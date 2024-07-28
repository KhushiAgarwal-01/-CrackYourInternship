 string removeDups(string str) {
        // Your code goes here
        string ans="";
        vector<int>hash(26,0);
        for(int i=0;i<str.length();i++){
            if(hash[str[i]-'a']==0){
                ans+=str[i];
                hash[str[i]-'a']=1;
            }
        }
        return ans;
    }