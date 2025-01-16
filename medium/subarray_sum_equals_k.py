class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # Create a hashmap where: prefixSum: count
        hashMap = {0: 1}

        # Store the prefixSum
        prefixSum = 0
        numSubArrays = 0

        for i in range(len(nums)):
            prefixSum += nums[i]

            diff = prefixSum - k
            if diff in hashMap:
                numSubArrays += hashMap[diff]
                
            if prefixSum in hashMap:
                hashMap[prefixSum] += 1
            else:
                hashMap[prefixSum] = 1
            
        return numSubArrays

