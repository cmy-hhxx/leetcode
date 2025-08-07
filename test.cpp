#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> hash;
    for (auto x : nums) hash.insert(x);
    
    int res = 1;
    while (hash.count(res)) res ++;

    return res;
}

int trap(vector<int>& height) {
    stack<int> stk;

    int res = 0, n = height.size();
    for (int i = 0; i < n; i++) {
        int last = 0;
        while (!stk.empty() && height[stk.top()] < height[i]) {
            res += (height[stk.top()] - last) * (i - stk.top() - 1);
            last = height[stk.top()];
            stk.pop();
        }
        if (stk.size()) {
            res += (height[i] - last) * (i - stk.top() - 1);
        }
        stk.push(i);
    }

    return res;
}

string multiply(string num1, string num2) {
    vector<int> A;
    vector<int> B;

    int n = num1.size();
    int m = num2.size();
    for (int i = n - 1; i >= 0; i--) A.push_back(num1[i] - '0');
    for (int i = m - 1; i >= 0; i--) B.push_back(num2[i] - '0');

    vector<int> C(n + m, 0);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            C[i + j] += A[i] * B[j];

    for (int i = 0, t = 0; i < C.size(); i ++ ) {
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }

    int k = C.size() - 1;
    while (k >= 0 && C[k] == 0) k --;
    string res;
    while (k >= 0) {
        res += C[k] + '0';
        k --;
    }
    return res.empty() ? "0" : res; 
}

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    s = ' ' + s;
    p = ' ' + p;

    vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
    f[0][0] = true;

    for (int i = 0; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (p[j] == '*') {
                f[i][j] = f[i][j - 1] || i && f[i - 1][j];
            } else {
                f[i][j] = (s[i] == p[j] || p[j] == '?') && i && f[i - 1][j - 1];
            }
        }
    }
    return f[n][m];
}

int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n, 0);

    for (int i = 1, j = 0; i < n; i ++ ) {
        while (j + nums[j] < i) j ++ ;
        f[i] = f[j] + 1;
    }
    return f[n - 1];
}

int main() {
    return 0;
}