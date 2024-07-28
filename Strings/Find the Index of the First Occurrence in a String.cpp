class Solution {
public:
    int strStr(string h, string s) {
        int n=s.length();
        int x=h.length();  
      for(int i=0;i<=x-n;i++){
        string c=h.substr(i,n);
        if(c==s){
            return i;
        }
      }
      return -1;

    }
};