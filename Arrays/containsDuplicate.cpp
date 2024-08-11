class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for (auto i: nums) hashMap[i]++;

        for (auto i: hashMap){
            if(i.second>=2)
            return true; 
        }

        return false; 
    }
};