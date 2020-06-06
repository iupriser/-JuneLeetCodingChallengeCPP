class Solution {
public:
    vector<int>w_sum;
    Solution(vector<int>& w) {
        w_sum.push_back(w[0]);
        //prefixSum
        for(int i=1; i<w.size(); ++i){
            w_sum.push_back(w_sum[i-1]+w[i]);
        }
    }
    
    int pickIndex() {
        int target = rand()%w_sum[w_sum.size() -1];
        auto it = upper_bound(w_sum.begin(),w_sum.end(),target);
        return it-w_sum.begin();
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

