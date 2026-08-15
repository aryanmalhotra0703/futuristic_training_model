class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int check=0;
        bool non_zero=false;
        for(int x:nums){
            check=check^x;
            if(check!=0){
                non_zero=true;
            }
        }
        if(check!=0){
            return nums.size();
        }
        if(!non_zero){
            return 0;
        }
        return nums.size()-1;
    }
};