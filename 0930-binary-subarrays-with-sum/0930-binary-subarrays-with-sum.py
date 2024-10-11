class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        one_idxs = [-1]
        for [i, num] in enumerate(nums):
            if num == 1:
                one_idxs.append(i)
        one_idxs.append(len(nums))

        result = 0
        for i in range(1, len(one_idxs) - goal):
            if goal == 0:
                num_of_zero = (one_idxs[i] - one_idxs[i - 1]) - 1
                result += int((num_of_zero * (num_of_zero + 1)) / 2)
            else:
                num_of_start_zero = (one_idxs[i] - one_idxs[i - 1]) - 1
                num_of_end_zero = (one_idxs[i + goal] - one_idxs[i - 1 + goal]) - 1
                result += (num_of_start_zero + 1) * (num_of_end_zero + 1)

        return result