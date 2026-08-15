class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j]!='.'){
                    if(check(i,j,board)==false){
                        return false;
                    }
                }
            }     
        }

        return true;
    }

    bool check(int i, int j, vector<vector<char>>& board){
        char ch=board[i][j];

        for(int k=0; k<9; k++){
            if(board[k][j]==ch && k!=i) return false;
            if(board[i][k]==ch && k!=j) return false;

            int b1=(i/3)*3+(k/3);
            int b2=(j/3)*3+(k%3);

            if(board[b1][b2]==ch && (b1!=i || b2!=j)) return false;
        }

        return true;
    }
};