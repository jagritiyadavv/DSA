class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        //logic will fail without sorting

        /*triplets have to be unique not their elements if there is multiple count 
        of the same element so we are not deleting duplicates entry rather
        skipping over those for the same entry*/

        for (int firstElement=0; firstElement<n-2; firstElement++){
            if(firstElement>0 && nums[firstElement]==nums[firstElement-1]) continue;

            /*skip duplicate triplets
            only 1st element doesnt have a previous element and for all other entries 
            we do not want same 1st element because that will lead to same triplet
            example [-2,-2,-2,0,0,0,1,1,2,2] */

            int a = nums[firstElement];
            int target = 0 - a;
            int secondEle = firstElement + 1;
            int thirdEle = n-1;

            while(secondEle< thirdEle){
                //haven't crossed

                int sum = nums[secondEle] + nums[thirdEle];
                if(sum==target){
                    //a triplet found, push it
                    answer.push_back({a, nums[secondEle], nums[thirdEle]});

                    //move pointers
                    secondEle++;
                    thirdEle--;

                    //-2,[-2],-2,-1,0,1,2,(2) 
                    //moves to idx 2 then checks it is the same as prev so have to move again
                    //moves to idx n-2 then same so another step

                    //move the pointer to a non same number to find another unique triplet
                    while(secondEle < thirdEle && nums[secondEle]==nums[secondEle - 1])
                    secondEle++;

                    while(thirdEle> secondEle && nums[thirdEle]== nums[thirdEle+1])
                    thirdEle--;
                }

                else if( sum < target){
                    //add +ve value, move secondEle to positive side on number line
                    secondEle++;
                }
                else {
                    thirdEle--;
                }
            }

        }

       return answer;
    }
};