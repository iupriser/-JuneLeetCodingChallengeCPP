/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();++i)
        {
            if(nums[abs(nums[i])-1]>=0)
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            else
                return abs(nums[i]); 
        }
        return 0;
    }
};
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while (slow != fast);
        
        fast = nums[0];
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};
