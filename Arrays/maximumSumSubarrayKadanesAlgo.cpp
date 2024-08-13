class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum= nums[0];

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            maxSum= max(maxSum, sum);
            //order matters, neeche karne pe sum already zero ho jara tha
            
            if(sum<0){
                sum=0;
                //start afresh, we do not need negative sum component
                //this is not equivalent to saying we do not need -ve elements
            }
            
           // maxSum= max(maxSum, sum);
        }
        return maxSum;
    }
};