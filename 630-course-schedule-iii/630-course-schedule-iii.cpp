class Solution {
private:
    static bool compare(vector<int>& course1 , vector<int>& course2) {
        return course1[1] < course2[1];
    }

public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end() , compare);
        
        priority_queue<int> pq;
        int time = 0;
        
        for(vector<int> course : courses) {
            int totalTime = course[0];
            int finishDate = course[1];
            
            if(totalTime <= finishDate) {
                if(totalTime + time <= finishDate) {
                    pq.push(totalTime);
                    time += totalTime;
                } else {
                    if(pq.top() > totalTime) {
                        time -= pq.top();
                        pq.pop();
                        pq.push(totalTime);
                        time += totalTime;
                    }
                }
            }
            
        }        
        
        return pq.size();
    }
};