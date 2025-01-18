class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        result = {num: -1 for num in nums1}
        
        for num in nums2:
            while stack and stack[-1] < num:
                popped = stack.pop()
                if popped in result:
                    result[popped] = num
                
            stack.append(num)
            
        return [result[n] for n in nums1]
        