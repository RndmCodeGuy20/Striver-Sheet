class Solution:
    def SortColors(self, nums: [int]):
        rez = {0: 0, 1: 0, 2: 0}

        for i in nums:
            rez[i] += 1

        print(rez)
        # for i in rez.keys():
        #     if rez[i] != 0:
        #         k = i
        #         break
        # print(k)
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

    # solution.SortColors([0, 1, 2, 1, 2, 0, 0, 1])
    solution.SortColors([0, 2])
    # solution.SortColors([2])
