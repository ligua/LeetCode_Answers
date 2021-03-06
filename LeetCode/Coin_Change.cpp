//You are given coins of different denominations and a total amount of money amount.Write a function to compute the fewest number of coins that you need to make up that amount.If that amount of money cannot be made up by any combination of the coins, return -1.
//
//Example 1:
//coins = [1, 2, 5], amount = 11
//return 3 (11 = 5 + 5 + 1)
//
//Example 2 :
//coins = [2], amount = 3
//return -1.
//
//Note :
//	 You may assume that you have an infinite number of each kind of coin.

#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
	int sz = coins.size();
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < sz; ++i)
	{
		for (int j = coins[i]; j <= amount; ++j)
		{
			if (dp[j - coins[i]] != INT_MAX)
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}
	return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

void testCoinChange()
{
	vector<int> coins = { 186, 419, 83, 408 };
	int amount = 6249;
	int rt = coinChange(coins, amount);
}