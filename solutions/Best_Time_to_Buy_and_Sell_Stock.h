/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 18, 2014
 *  Problem:     	Best Time to Buy and Sell Stack
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 *  Notes:
 * 	Say you have an array for which the ith element is the price of a given
 * 	stock on day i.
 *
 * 	If you were only permitted to complete at most one transaction (ie, buy one
 * 	and sell one share of the stock), design an algorithm to find the maximum
 * 	profit.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef BUY_AND_SELL_STOCK
#define BUY_AND_SELL_STOCK

#include <vector>

using namespace std;

class Solution
{
public:
	int maxProfit(vector<int> &prices);
};

int Solution::maxProfit(vector<int> &prices)
{
	if (prices.size() == 0) return 0;

	int max_profit = 0;
	int min_prices = prices[0];

	for (size_t i = 1; i < prices.size(); i++)
	{
		min_prices = prices[i] < min_prices ? prices[i] : min_prices;

		if (prices[i] > min_prices) 
		{
			int cur_profit = prices[i] - min_prices;
			max_profit = cur_profit > max_profit ? cur_profit : max_profit;
		}
		
	}

	return max_profit;
	
}

#endif /* BUY_AND_SELL_STOCK */
