class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        //Using XOR + AND combination
        int ones = 0;
        int twos = 0;
        for(auto ele: nums)
        {
            ones = (ones^ele) & (~twos);
            twos = (twos^ele) & (~ones);
        }
        return ones;
        /*
        //Counting SET-BIT
        int n=nums.size();
        unsigned int ans=0,shift=1;
        for(int i=0;i<32;++i)
        {
            int count=0;
            for(auto ele: nums)
            {
                if(ele & shift)
                    count+=1;
            }
            if(count%3 != 0)
                ans += shift;
            shift*=2;
            
        }
        return ans;
        */
        /*
        //SORTING
        int n=nums.size();
        if(n<3)
            return nums[0];
        
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1])
            return nums[0];
        int i=1;
        while(i<n)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
            i+=3;
        }
        return nums[n-1];
        */
    }
};
