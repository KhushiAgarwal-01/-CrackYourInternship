class Solution {

    bool solve(int i, int j, vector<vector<char>>& board, int k, string w) {
        if (k == w.length()) {
            return true;
        }
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0 || board[i][j]!=w[k]){
            return false;
        }
        
           
            char temp=board[i][j];
           board[i][j] = '\0';

            bool up= solve(i-1,j,board,k+1,w);
            bool left=solve(i,j-1,board,k+1,w);
            bool down=solve(i+1,j,board,k+1,w);
            bool right=solve(i,j+1,board,k+1,w);
    
            if(up || left || down || right){
                return true;
            }
            board[i][j]=temp;
            return false;
        
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(solve(i,j,board,0,word))
            return true;
        }
       }
       return false;
    }
};