// link - https://leetcode.com/problems/set-matrix-zeroes/

void setZeroes(vector<vector<int>>& matrix) {
        
        // bruteforce code
        
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int>row(r,1),col(c,1);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(row[i]==0 || col[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        row.clear();
        col.clear();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
        //optimal code
        
        int col = matrix[0].size();
        int row = matrix.size();
        int flag = 1;
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==0) flag = 0;
            for(int j=1;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=1;j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
                
            }
            if(flag==0)
            {
                matrix[i][0]=0;
            }
        }
        
    }
