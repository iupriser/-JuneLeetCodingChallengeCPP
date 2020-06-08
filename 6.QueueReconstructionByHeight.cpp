class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(),people.end(),[](const vector<int>&a, const vector<int>&b) {
            return (a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]));
        });
        
        for (auto& p : people) 
            result.insert(result.begin() + p[1], p);
    
        return result;       
    }
};