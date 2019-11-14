
// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> ans;
        if (N == 0)
            return ans;
        ans.push_back(1);
        int k = 2;
        while (ans.size() != N) {
            int l = 0, r = ans.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (compare(ans[mid], k))
                    l = mid + 1;
                else
                    r = mid;
            }
            ans.insert(ans.begin() + l, k++);
        }
        return ans;
    }
};
