import numpy as np

def read_file(filename):

    nums = []
    with open(filename, 'r') as f:
        #num = f.readlines()
        for line in f:
            nums.append(int(line))
        #    container = []
        #    line_parse = line.split()
            # [source target1,weight1 target2,weight2 target3,weight3 ... ]
        #    source = line_parse[0]
        #    for i, val in enumerate(line_parse[1:len(line_parse)]):
        #        target, data = val.split(',')
        #        edge = [source] + [target] + [data]
        #        edgeList.append(edge)

    return nums

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lookup = {}
        for i, num in enumerate(nums):
            if target - num in lookup:
                return [lookup[target - num], i]
            lookup[num] = i
        return []

    def twoSum2(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        k = 0
        for i in nums:
            j = target - i
            k += 1
            tmp_nums = nums[k:]
            if j in tmp_nums:
                return [k - 1, tmp_nums.index(j) + k]


if __name__ == '__main__':
    
    nums = read_file("../../data/2sum.txt")
    target_list = list(range(-10000, 10000));
    count = 0
    for t in target_list:
        print(str(t))
        result = Solution().twoSum(nums, t)
        if result:
            count = count + 1
            print("No. "+ str(count)+ " "+ str(result) + " "+ str(t))
    print(count)   