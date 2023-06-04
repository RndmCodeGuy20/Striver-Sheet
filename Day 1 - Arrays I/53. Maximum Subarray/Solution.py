class Solution:
    def maxSubArray(self, nums: [int]) -> int:
        sumN = 0
        maxS = -9999999

        for i in nums:
            sumN += i

            if (sumN > maxS):
                maxS = sumN

            if sumN < 0:
                sumN = 0

        return maxS

if __name__ == '__main__':
    s = Solution()
    print(s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
    print(s.maxSubArray([1]))
    print(s.maxSubArray([5,4,-1,7,8]))