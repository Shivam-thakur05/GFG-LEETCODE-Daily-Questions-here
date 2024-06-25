int rows=mat.size();
        if(rows == 0)
        return mat;
        int cols = mat[0].size();
        if(cols==0) return mat;
        
        k=k%cols;
        
        for(int i=0;i<rows;i++)
        {
            vector<int> newRow(cols);
            for(int j=0;j<cols;j++)
            {
                newRow[j]=mat[i][(j+k)%cols];
            }
            mat[i]=newRow;
        }
    return mat;
