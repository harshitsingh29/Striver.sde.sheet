// link - https://leetcode.com/problems/n-queens/

// BRUTE FORCE

class Solution {
public:
    
    bool issafe(int row, int col, vector<string> &board, int n)
    {
        int drow = row;
        int dcol = col;
        while(row >=0 and col >=0)
        {
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        
        row = drow;
        col = dcol;
        while(row <= n - 1 and col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        
        col = dcol;
        row = drow;
        while(col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        return true;
    }
    
    void solve(int col, int n, vector<vector<string>> &res, vector<string> &board)
    {
        if(col == n)
        {
            res.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++)
        {
            if(issafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, n, res, board);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>board(n);
        string s(n,'.');
        for(int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(0,n,res,board);
        return res;
    }
};


// EFFICIENT

class Solution {
public:
    
    void solve(int col, int n, vector<vector<string>> &res, vector<string> &board, vector<int> &lowerdia, vector<int> &upperdia, vector<int> &leftrow)
    {
        if(col == n)
        {
            res.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++)
            if(leftrow[row] == 0 and lowerdia[row + col] == 0 and upperdia[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerdia[row + col] = 1;
                upperdia[n - 1 + col - row] = 1;
                solve(col + 1, n, res, board, lowerdia, upperdia, leftrow);
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerdia[row + col] = 0;
                upperdia[n - 1 + col - row] = 0;
            }    
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>board(n);
        string s(n,'.');
        for(int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int>lowerdia(2 * n - 1, 0), upperdia(2 * n - 1, 0), leftrow(n ,0);
        solve(0,n,res,board,lowerdia,upperdia,leftrow);
        return res;
    }
};
