class Solution {
public:
    vector<vector<int>> solve(vector<int>&nums,int target,int n,
                        vector<vector<int>>&ans,vector<int>&part,int sum,
                        int i){

                            if(i>=n){
                                if(sum==target){
                                    ans.push_back(part);
                                    return ans;
                                }
                                return ans;
                            }

                            if(sum==target){
                                ans.push_back(part);
                                return ans;
                            }

                            if(sum>target){
                                return part;
                            }
                            part.push_back(nums[i]);
                            //pick recursion include
                            solve(nums,target,n,ans,part,sum+nums[i],i);
                            //back track
                            part.pop_back();
                            //non recursion exclude
                            solve(nums,target,n,ans,part,sum,i+1);

                            return ans;

                        }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>part;
        return solve(nums,target,n,ans,part,0,0);
    }
};
