def main():
    tmp = [int(x) for x in input().split()]
    k = tmp[1]
    numbers = [int(x) for x in input().split()]
    low = 1
    high = sum(numbers)

    def is_possible(target):
        partition_sum = 0
        count = 1
        for i in numbers:
            if i > target:
                return False
            partition_sum += i
            if (partition_sum > target):
                count += 1
                partition_sum = i
        return count <= k
    ans = 0
    while(low <= high):
        m = (low + high)//2
        if (is_possible(m)):
            ans = m
            high = m - 1
        else:
            low = m + 1
    print(ans)


main()
