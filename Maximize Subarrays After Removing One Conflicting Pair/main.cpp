class Solution 
{
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) 
    {
        // Step 1: Prepare the conflict list
        vector<vector<int>> conflicts(n + 2);
        for (const auto& pair : conflictingPairs) 
        {
            int a = pair[0];
            int b = pair[1];
        
            // Store the smaller in the larger's conflict list
            if (a < b) 
            {
                conflicts[b].push_back(a);
            } 
            else 
            {
                conflicts[a].push_back(b);
            }
        }

        // Step 2: Initialize tracking variables
        int maxLeft = 0;
        int secondMaxLeft = 0;
        vector<long long> gains(n + 2, 0);
        long long validSubarrays = 0;

        // Step 3: Loop through numbers from 1 to n (as subarray end points)
        for (int right = 1; right <= n; ++right) 
        {
            for (int left : conflicts[right]) 
            {
                if (left > maxLeft) 
                {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                } 
                else if (left > secondMaxLeft) 
                {
                    secondMaxLeft = left;
                }
            }

            // Count valid subarrays ending at 'right'
            validSubarrays += right - maxLeft;
            // Track recoverable subarrays
            gains[maxLeft] += maxLeft - secondMaxLeft;
        }

        // Step 4: Return total valid subarrays + best recoverable gain
        long long maxGain = *max_element(gains.begin(), gains.end());
        return validSubarrays + maxGain;
    }
};