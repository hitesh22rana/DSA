class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        
        int direction = 1;
        
        // North = 1;
        // east = 2;
        // south = 3;
        // west = 4;
        
        for(char& c : instructions) {
            if(c == 'G') {
                if(direction == 1) {
                    x++;
                }
                
                else if(direction == 2) {
                    y++;
                }
                
                else if(direction == 3) {
                    x--;
                }
                
                else {
                    y--;
                }
            }
            
            else if(c == 'L') {
                direction--;
                if(direction == 0) direction = 4;
            }
            
            else if(c == 'R') {
                direction++;
                if(direction == 5) direction = 1;
            }
        }
        
        return (x == 0 && y == 0) || direction != 1;
    }
};