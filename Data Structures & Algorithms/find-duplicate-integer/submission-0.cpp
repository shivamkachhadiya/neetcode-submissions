class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==1)return -1;
        sort(nums.begin(),nums.end());
        //1 2 2 2 3
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
        return -1;
    }
};
