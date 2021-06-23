// link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size(), profit = 0, mini = v[0];
        for(int i=1;i<n;i++)
        {
            if(mini>v[i])
            {
                mini = v[i];
            }
            else
            {
                if(profit<(v[i]-mini))
                {
                    profit = v[i] - mini;
                }
            }
        }
        return profit;
    }
};
