def stoneGame(piles):
    # dp[i][j] 表示 piles[i~j]这堆石头 的结果
    m = len(piles)
    dp = [[(0, 0) for i in range(m)] for j in range(m)]

    # base case 对角线上，只有一个石头，肯定是先手赢
    for i in range(m):
        dp[i][i] = (piles[i], 0)
    
    # 状态转移
    for i in range(m-1, -1, -1):
        for j in range(i+1, m):
            # dp[i][j]时，先手可以拿左边的石头，这样剩下的[i+1,j]就是后手的值
            left = dp[i+1][j][1] + piles[i]
            # 同理，可以拿右边的
            right = dp[i][j-1][1] + piles[j]

            if left > right:
                # 当拿左边收益更大，这时候后手就等于i+1 j的先手
                dp[i][j] = (left, dp[i+1][j][0])
            if left < right:
                dp[i][j] = (right, dp[i][j-1][0])
    
    res = dp[0][m-1]
    return res[0] - res[1]