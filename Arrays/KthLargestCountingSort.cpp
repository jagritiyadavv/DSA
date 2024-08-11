class Solution {
    int countSort(vector<int>& nums, int min, int max, int k){
        int range = max-min+1;
        vector<int> count(range, 0);

        int ans=0;

        for (auto i :  nums)
            count[i-min]++;

        for (int i = range-1; i>=0; i--){
            k-=count[i];
            if(k<=0) {
                ans = i+ min; 
                break;
                }
        }
        return ans ;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // to find the range for count sort

        int min, max;

        //range is [first, last) so we do begin and end
        min = *min_element(nums.begin(), nums.end());
        max = *max_element(nums.begin(), nums.end());

        return countSort(nums, min, max, k);
     
    }
};