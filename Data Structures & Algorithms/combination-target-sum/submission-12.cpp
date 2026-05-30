class Solution {
public:
    void solve(vector<int>&nums,int target,int n,
                        vector<vector<int>>&ans,vector<int>&part,int sum,
                        int i){

                            if(i>=n){
                                if(sum==target){
                                    ans.push_back(part);
                                    return;
                                }
                                return;
                            }

                            if(sum==target){
                                ans.push_back(part);
                                return;
                            }

                            if(sum>target){
                                return;
                            }
                            part.push_back(nums[i]);
                            //pick recursion include
                            solve(nums,target,n,ans,part,sum+nums[i],i);
                            //back track
                            part.pop_back();
                            //non recursion exclude
                            solve(nums,target,n,ans,part,sum,i+1);


                        }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>part;
         solve(nums,target,n,ans,part,0,0);
         return ans;
    }
};
