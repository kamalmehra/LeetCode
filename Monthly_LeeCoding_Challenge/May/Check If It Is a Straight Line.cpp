	class Solution {
public:
    
    //another better approach will be to subtract x2-y1 and y2-x1 and there diff sum will always be equal
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n<=2) return true;
        
        int x1, x2, y1, y2;
        x1 = coordinates[0][0];
        x2 = coordinates[1][0];
        y1 = coordinates[0][1];
        y2 = coordinates[1][1];

        int dX = x1 - x2;
        int dY = y1 - y2;
        for(int i=2; i<n;i++){
            int x3 = coordinates[i][0];
            int y3 = coordinates[i][1];
            if(dX*(y3-y1)!=dY*(x3-x1)) 
                return false;
        
        }
        
        return true;
    }
};