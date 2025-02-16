class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    const std::size_t N = cost.size();

        /*
            dp[k] = the minimum cost to reach the top from k-th step
                  = the cost to leave k-th step + min(
                        the minimum cost to reach the top from 1 step above,
                        the minimum cost to reach the top from 2 step above
                    )
                  = cost[k] + min(dp[k+1], dp[k+2])
        */
        std::vector<int> dp(N+2); {
            dp[N] = 0;    // the cost to reach the top = 0
            dp[N+1] = 0;  // the cost to reach the step beyond the top = 0
        }
        
        for (std::size_t ri = 0; ri != N; ++ri) {
            std::size_t i = (N - 1) - ri;  // i = N-1 ~ 0
            dp[i] = cost[i] + std::min(dp[i+1], dp[i+2]);
        }

        // you can either start from index 0 or 1, pick one with a lower cost
        return std::min(dp[0], dp[1]);    
    }
};