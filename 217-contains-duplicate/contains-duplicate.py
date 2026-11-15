class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        helper = set()
        n = len(nums)
        for i in range(n):
            if(nums[i] in helper):
                return True
            helper.add(nums[i])
        return False
