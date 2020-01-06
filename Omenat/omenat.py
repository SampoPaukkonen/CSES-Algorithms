def main():
    n = int(input())
    nums = [int(x) for x in input().split()]
    total_sum = sum(nums)

    def exhaust(i, sum_so_far):
        if (i == 0):
            return abs((total_sum - sum_so_far) - sum_so_far)
        return min(exhaust(i-1, sum_so_far+nums[i-1]), exhaust(i-1, sum_so_far))
    print(exhaust(n, 0))


main()
