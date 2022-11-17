class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int as1 = abs(ax2 - ax1); 
        int as2 = abs(ay2 - ay1);
        
        int bs1 = abs(bx2 - bx1); 
        int bs2 = abs(by2 - by1);
        
        int cx1 = max(ax1, bx1);
        int cy1 = max(ay1, by1);
        
        int cx2 = min(ax2, bx2);
        int cy2 = min(ay2, by2);
        
        int carea = 0;
        
        if((cx2 - cx1) > 0 && (cy2 - cy1) > 0) {
            carea = (cx2 - cx1) * (cy2 - cy1);
        }
        
        return as1 * as2 + bs1 * bs2 - carea;
    }
};