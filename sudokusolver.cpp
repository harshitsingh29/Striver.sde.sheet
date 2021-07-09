// link - https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++){
                        if(issafe(board, c, i, j)){
                            board[i][j] = c;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool issafe(vector<vector<char>>& board, char c, int i, int j)
    {
        for(int val = 0; val < 9; val++){
            if(board[val][j] == c)
                return false;
            
            if(board[i][val] == c)
                return false;
            
            if(board[3 * (i / 3) + val / 3][3 * (j / 3) + val % 3] == c)
                return false;
        }
        return true;
    }
};
