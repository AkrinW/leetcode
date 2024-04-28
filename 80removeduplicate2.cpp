class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int count = 1;
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                ++i;
                count = 1;
                nums[i] = nums[j];
            } else if (count == 1) {
                ++i;
                ++count;
                nums[i] = nums[j];
            }
            ++j;
        }
        return i + 1;
    }        
};