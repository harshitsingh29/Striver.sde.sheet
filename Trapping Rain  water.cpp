// link - https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int trap(vector<int>& a) {
        
        /**
        time - O(n^2)
        space - O(1)
        **/    
        
        // int n = height.size();
        // int sum = 0;
        // for(int i = 0; i < n; i++)
        // {
        //     int j, temp = 0, left_max = 0, right_max = 0;
        //     j = i;
        //     while(j>=0)
        //     {
        //         if(left_max < height[j])
        //             left_max = height[j];
        //             j--;
        //     }
        //     j = i;
        //     while(j < n)
        //     {
        //         if(right_max < height[j])
        //             right_max = height[j];
        //             j++;
        //     }
        //     cout<<left_max<<" "<<right_max<<'\n';
        //     // sum += min(left_max,right_max) - height[i];
        //     if(left_max > right_max)
        //         swap(left_max, right_max);
        //     sum += (left_max - height[i]);
        // }
        // return sum;
        
        
        
        /**
        
        time - O(2n) - O(n)
        space - O(2n)
        
        **/
        // int n = height.size();
        // int m1 = 0, m2 = 0;
        // vector<int>v_prefix,v_suffix;
        // for(int i = 0; i < n; i++)
        // {
        //     m1 = max(m1,height[i]);
        //     m2 = max(m2,height[n-i-1]);
        //     v_prefix.push_back(m1);
        //     v_suffix.push_back(m2);
        // }
        // m1 = 0;
        // for(int i = 0; i < n ; i++)
        // {
        //     m1 += min(v_prefix[i],v_suffix[n - i - 1]) - height[i];
        // }
        // return m1; 
        
        /**
        
        time - O(n)
        space - O(1)
        
        **/
        
        
        int res = 0, l = 0, r = a.size() - 1, left_max = 0, right_max = 0;
        while(l <= r)
        {
            if(a[l] <= a[r])
            {
                if(a[l] >= left_max)
                {
                    left_max = a[l++];
                }
                else
                {
                    res += left_max - a[l++];
                }
            }
            else
            {
                if(a[r] >= right_max)
                {
                    right_max = a[r--];
                }
                else
                {
                    res += right_max - a[r--];
                }
            }
        }
        return res;
    }
};
