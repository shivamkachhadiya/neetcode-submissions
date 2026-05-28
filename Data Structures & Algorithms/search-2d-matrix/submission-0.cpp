class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();//3 row
        int m=matrix[0].size();// 4 coloumn size
        for(int i=0; i<n;i++){  //row loop  3 tak chalega
            for (int j=0; j<m; j++){ // column loop  // every row ke element pe chalgega
                    if(matrix[i][j]==target){
                        return true;
                    }
            }
        }
        return false;
    }
};
