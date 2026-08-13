class Solution {
public:
    int r;
    int c;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;

        r=image.size();
        c=image[0].size();

        dfs(image, sr, sc, image[sr][sc], color);

        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int newcolor){

        if(image[sr][sc]!=color){
            return;
        }

        image[sr][sc]=newcolor;

        
        if(sr>0 && image[sr-1][sc]==color ){
            dfs(image, sr-1, sc, color,newcolor);
        }

        if(sr<r-1 && image[sr+1][sc]==color ){
            dfs(image, sr+1, sc, color,newcolor);
        }

        if(sc>0 && image[sr][sc-1]==color ){
            dfs(image, sr, sc-1, color,newcolor);
        }

        if(sc<c-1 && image[sr][sc+1]==color ){
            dfs(image, sr, sc+1, color,newcolor);
        }
        
    }
};