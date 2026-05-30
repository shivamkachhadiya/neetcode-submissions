class Solution {
   public:
    vector<vector<int>> solve(vector<int>& nums, vector<int>& chhota_vector,
                              vector<vector<int>>& bada_ans_vector, int i) {
                                
                                //base cond
                                if(i==nums.size()){
                                    bada_ans_vector.push_back(chhota_vector);
                                    return bada_ans_vector;
                                }

                                chhota_vector.push_back(nums[i]);
                                solve(nums,chhota_vector,bada_ans_vector,i+1);
                                chhota_vector.pop_back();
                                solve(nums,chhota_vector,bada_ans_vector,i+1);
                                return bada_ans_vector;
                              }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> chhota_vector;
        vector<vector<int>> bada_ans_vector;

        return solve(nums, chhota_vector, bada_ans_vector, 0);
    }
};
