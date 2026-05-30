class Solution {
public:
    bool solve(vector<int>&nums,int k,int target,int i,int sum){
        if(i==nums.size()){
            if(sum==target){
                return true;
            }
            return false;
        }
        if(sum==target){
            return true;
        }
        if(sum>target){
            return false;
        }

        //pick
        bool pick=solve(nums,k,target,i+1,sum+nums[i]);
        //non pick
        bool nonPick=solve(nums,k,target,i+1,sum);

        return pick||nonPick;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(auto &i:nums){
            sum+=i;
        }

        if(sum%k==0){
            int target=sum/k;
            return solve(nums,k,sum,0,0);
        }else{
            return false;
        }
    }
};