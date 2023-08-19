class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>row(m);
        vector<int>col(n);
        int count;
        //traversing row to count 1's
        for(int i=0;i<m;i++){
            count=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
            }
            row[i]=count;
        }
        //traversing col to count 1's
        for(int j=0;j<n;j++){
             count=0;
            for(int i=0;i<m;i++){
                if(grid[i][j]==1) count++;
            }
            col[j]=count;
        }
        vector<vector<int>>mt;
        vector<int>temp;
        int x;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                x=row[i]+col[j]-((m-row[i])+(n-col[j]));
                temp.push_back(x);
            }
            mt.push_back(temp);
            temp.clear();
            x=0;
        }
        return mt;
    }
};
