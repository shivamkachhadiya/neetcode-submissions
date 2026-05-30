// class Solution {
// public:
//     // 1,1,2,5,6,7,10  after sort
//     void solve(vector<int>& arr, int target, vector<int>& part,
//                vector<vector<int>>& ans, int i, int sum) {
//         if (i == arr.size()) {
//             if (target == sum) {
//                 ans.push_back(part);
//             }
//             return;
//         }
//         if (sum == target) {
//             ans.push_back(part);
//             return;
//         }
//         if (sum > target)
//             return;
//         part.push_back(arr[i]);
//         solve(arr, target, part, ans, i + 1, sum + arr[i]);
//         part.pop_back();

//         // Skip duplicates when not including
//         int j = i + 1;
//         while (j < arr.size() && arr[j] == arr[i]) {
//             j++;
//         }
//         solve(arr, target, part, ans, j, sum);
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
//         // 10,1,2,7,6,1,5  without sort
//         // 1,1,2,5,6,7,10  after sort
//         vector<int> part;
//         vector<vector<int>> ans;
//         solve(candidates, target, part, ans, 0, 0);
//         return ans;
//     }
// };


class Solution {
public:
    // EXACT SAME solve function as Combination Sum 1
    void solve(vector<int>& nums, int target, int n, vector<vector<int>>& ans, vector<int>& part,
               int sum, int i) {
        if (i >= n) {
            if (sum == target) {
                ans.push_back(part);
            }
            return;
        }

        if (sum == target) {
            ans.push_back(part);
            return;
        }

        if (sum > target) {
            return;
        }

        part.push_back(nums[i]);
        // pick recursion include (use same index once, then move)
        // For Combination Sum II: each element used at most once, so we use i+1 here as well
        solve(nums, target, n, ans, part, sum + nums[i], i + 1);  // FIX: i+1 instead of i
        // back track
        part.pop_back();
        // non recursion exclude
        solve(nums, target, n, ans, part, sum, i + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // sort to group duplicates
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> part;

        // generate all combinations (may include duplicates)
        solve(candidates, target, n, ans, part, 0, 0);

        // remove duplicate combinations
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};