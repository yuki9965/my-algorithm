class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        stack<int> s;
        for (int i : nums2)
        {
            while (!s.empty() and s.top() <= i)
            {
                m[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for (int j=0;j<nums1.size();j++)
        {
            if (m[nums1[j]])
                nums1[j] = m[nums1[j]];
            else
                nums1[j] = -1;
        }
        return nums1;
    }
};