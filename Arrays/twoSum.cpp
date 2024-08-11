class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pairIndex; 

        for(int i=0; i<nums.size(); i++){
            int num= nums[i];
            if(pairIndex.find(target-num)!= pairIndex.end()){
                return{i, pairIndex[target-num]};
            }
            pairIndex[num]=i;
        }

        return {};
    }
};