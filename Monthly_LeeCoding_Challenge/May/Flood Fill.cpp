class Solution {
public:
    int n;
    int m;
    //visited helps in decreasing no of iterations
    int visited[50][50];
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // ***** length is in range [1,50]
        n = image.size()-1;
        m  = image[0].size()-1;
        memset(visited, 0, sizeof(visited));
        int is_color = image[sr][sc];
        fill(image, sr, sc, newColor, is_color);
        
        return image;
    }
    
    void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int is_color){
        //isValid
        if(sr<0 or sr>n or sc<0 or sc>m or image[sr][sc]!=is_color or visited[sr][sc]==1)
            return;
        //marking it visited
        visited[sr][sc] =1;
        
        image[sr][sc] = newColor;
        //iterating childs
        fill(image, sr-1, sc, newColor, is_color);
        fill(image, sr, sc-1, newColor, is_color);
        fill(image, sr+1, sc, newColor, is_color);
        fill(image, sr, sc+1, newColor, is_color);
        return;
    }
};