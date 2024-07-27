class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

    int m = board.size();
        int n = board[0].size();
        vector<vector<int>> temp = board;
        int x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int one = 0;
                for (int k = 0; k < 8; k++) {
                    int u = i + x[k];
                    int v = j + y[k];
                    if (u >= 0 && u < m && v >= 0 && v < n) {
                        one += temp[u][v];
                    }
                }

                if (temp[i][j] == 1 && (one < 2 || one > 3)) {
                    board[i][j] = 0;
                } else if (temp[i][j] == 0 && one == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }

};