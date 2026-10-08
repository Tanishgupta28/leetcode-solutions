class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value, 0);
        for (int num : nums) {
            int rem = ((num % value) + value) % value;
            freq[rem]++;
        }
        int mex = 0;
        while (freq[mex % value] > 0) {
            freq[mex % value]--;
            mex++;
        }
        return mex;
    }
};