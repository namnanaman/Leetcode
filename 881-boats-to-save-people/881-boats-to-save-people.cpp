class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count = 0;
        int i = 0, j = people.size()-1;
        
        while(i <= j){
            if(i == j){
                count++;
                i++;
                j--;
                break;
            }
            int x = people[i] + people[j];
            
            if(x <= limit){
                count++;
                i++;j--;
            }
            if(x > limit){
                count++;
                j--;
            }
        }
        return count;
    }
};