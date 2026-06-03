class Solution {
   public:
    void revese_fn(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
         k %= n; 
       // Right rotate: Pehle full array reverse, phir parts reverse
        revese_fn(nums, 0, n - 1);      // ✅ Full array reverse
        revese_fn(nums, 0, k - 1);      // ✅ First k reverse
        revese_fn(nums, k, n - 1);      // ✅ Remaining reverse
    }
};
