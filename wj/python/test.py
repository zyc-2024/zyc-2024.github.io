N, M, k, t = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

dp = [[0 for _ in range(M)] for _ in range(N)]
dp[0][0] = min(t, A[0][0]) * (k + 1)

for i in range(N):
    for j in range(M):
        if i == 0 and j == 0:
            continue
        if t >= A[i][j]:
            dp[i][j] = A[i][j] * (k + 1)
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) - 1

print(dp[N-1][M-1])
