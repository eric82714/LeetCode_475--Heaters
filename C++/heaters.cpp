class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        if(heaters.size() == 1)
            return std::max(heaters[0]-houses[0], houses[houses.size()-1]-heaters[0]);
        else {
            int radius = 0;
            int pos = 0;
            int n = heaters.size();
           
            for(int i = 0; i < houses.size(); i++) {
                int cur = houses[i];
                
                while(pos < n - 1 && abs(heaters[pos + 1] - cur) <= abs(heaters[pos] - cur))                     
                    pos ++;
                
                radius = std::max(radius, abs(heaters[pos] - cur));
            }
              
            return radius;
        }
    }
};
