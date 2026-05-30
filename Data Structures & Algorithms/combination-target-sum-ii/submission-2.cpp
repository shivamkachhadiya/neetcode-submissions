class Solution {
public:
    // Same solve function as Combination Sum 1, but with duplicate-skipping in skip branch
    void solve(vector<int>& arr, int target, int n, vector<vector<int>>& ans, vector<int>& part,
               int sum, int i) {
        if (i >= n) {
            if (sum == target) {
                ans.push_back(part);
            }
            return;
        }

        if (sum > target) {
            return;
        }

        if (sum == target) {
            ans.push_back(part);
            return;
        }

        // Pick current element
        part.push_back(arr[i]);
        solve(arr, target, n, ans, part, sum + arr[i], i + 1);  // each element used once
        part.pop_back();

        // Skip current element AND all its duplicates
        int j = i + 1;
        while (j < n && arr[j] == arr[i]) {
            j++;
        }
        solve(arr, target, n, ans, part, sum, j);  // skip duplicates
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // sort to group duplicates
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> part;

        solve(candidates, target, n, ans, part, 0, 0);

        return ans;
    }
};