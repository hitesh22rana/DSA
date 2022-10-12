class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0;
        
        for(vector<int>& i : points) {
            for(vector<int>& j : points) {
                for(vector<int>& k : points) {
                    double newArea = 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]);
                    if(newArea > area) area = newArea;
                }
            }
        }
        
        return area;
    }
};