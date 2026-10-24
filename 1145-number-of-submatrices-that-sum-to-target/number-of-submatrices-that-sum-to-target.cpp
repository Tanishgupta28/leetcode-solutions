class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        for (int top = 0; top < n; top++) {

            vector<int> colSum(m, 0);

            for (int bottom = top; bottom < n; bottom++) {

                // Compress rows into a 1D array
                for (int j = 0; j < m; j++) {
                    colSum[j] += matrix[bottom][j];
                }

                // LeetCode 560 logic
                unordered_map<int, int> mp;
                mp[0] = 1;

                int sum = 0;

                for (int j = 0; j < m; j++) {
                    sum += colSum[j];

                    if (mp.count(sum - target)) {
                        ans += mp[sum - target];
                    }

                    mp[sum]++;
                }
            }
        }

        return ans;
    }
};



// more optimal solution in which instead of using 2d matrix helper we use 1 d array 