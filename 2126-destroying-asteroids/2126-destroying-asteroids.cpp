class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        
        long temp = mass;
        for(auto it: asteroids){
            if(it <= temp){
                temp += it;
            }else{
                return false;
            }
        }
        return true;
    }
};