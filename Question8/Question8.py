def solution(n, m, costs):
    cost=[]
    for i in range(n+1):
            cost.append([0]*(m+1))
    for i in range(1, n + 1):
        prevCost= float('-inf')
        for j in range(1, m):
            prevCost = max(prevCost,cost[i - 1][j - 1]-costs[j - 1])
            cost[i][j] = max(cost[i][j - 1],costs[j] + prevCost)
    sumOfCost=cost[n][m-1]
    return sumOfCost
    
def main():
    n, m=map(int,input().split())
    costs = list(map(int, input().split()))
    print(solution(n, m, costs))


if __name__ == "__main__":
    main()
