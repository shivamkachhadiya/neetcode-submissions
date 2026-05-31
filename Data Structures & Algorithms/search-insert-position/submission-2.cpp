class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int start=0;
        int n=arr.size();
        int end=n-1;
        int mid=0;
        while(start<end){
             mid=(start+end)/2;
            if(arr[mid]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return mid;
    }
};