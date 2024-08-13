class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        //we want to sort intervals so that merging is easy,comparision based
        int n = intervals.size();

        vector<vector<int>> ans;

        for(int i =0; i<n; i++){
            //if it is the first entry in ans or non overlapping entry then add as it is
            if(ans.empty() || intervals[i][0]> ans.back()[1]){
                /*intervals[i] gives ith interval
                intervals[i][0] gives starting of that interval
                ans.back gives last entry interval and its [1] give end of that interval*/
                ans.push_back(intervals[i]);
                //push the ith interval
            }
            else{
                /*overlapping interval, change the end of the previous interval
                current interval could end before, with or after the prev interval so max*/

                ans.back()[1]=max(intervals[i][1], ans.back()[1]);
            }
        }
        return ans;

    }
};