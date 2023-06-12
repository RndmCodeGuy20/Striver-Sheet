class Solution:
    def SortColors(self, nums: [int]):
        rez = {0: 0, 1: 0, 2: 0}

        for i in nums:
            rez[i] += 1

        k = 0
        for i in range(len(nums)):
            if rez[k] != 0:
                nums[i] = k
                rez[k] -= 1
            else:
                k += 1
                nums[i] = k
                rez[k] -= 1

        print(nums)


if __name__ == '__main__':
    solution = Solution()

    solution.SortColors([0, 2])
