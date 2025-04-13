class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # By using a hashmap (dictionary in case of python)
        hash_map = {}

        for index1, value in enumerate(nums):
            req_value = target - value

            if req_value in hash_map:
                index2 = hash_map[req_value]
                return [index1, index2]
            
            hash_map[value] = index1