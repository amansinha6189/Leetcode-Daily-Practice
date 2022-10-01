class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        for(auto it: tasks){
            mpp[it]++;
        }
        
        priority_queue<int> pq;
        for(auto it: mpp){
            pq.push(it.second);
        }
        
        queue<pair<int, int>> q; // {count, time}
        int time = 0;
        
        while(true){
            time++;
            if(!pq.empty()){
                int curr = pq.top();
                pq.pop();
                
                if(curr - 1 > 0){
                    q.push({curr - 1, time + n});
                }
            }
            
            if(!q.empty() and q.front().second <= time){
                int cnt = q.front().first;
                q.pop();
                
                pq.push(cnt);
            }
            
            if(q.empty() and pq.empty()) break;
        }
        
        return time;
    }
};