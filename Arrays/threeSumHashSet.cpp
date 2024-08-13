class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //vector<vector<int>> ans;
        set<vector<int>> st ;//this ensure no duplicate triplet
        /* to see how, comments ko uncomment karke unke neeche wali lines ko comment karde*/

        for(int i= 0; i< nums.size(); i++){
            set<int> hashSet;
            for(int j = i+1; j<nums.size(); j++){
                int target = -(nums[i]+ nums[j]);
                if(hashSet.find(target)!=hashSet.end()){
                    vector<int> temp = {nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    //ans.push_back(temp);
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }        
        }
        //sort(ans.begin(), ans.end());
        vector<vector<int>> ans(st.begin(), st.end());

            return ans;
    }
};