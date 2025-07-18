#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> res;
string strs[] = {
    "", "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
};

void dfs(string& digits, int index, string path) {
    if (index == (int)digits.size()) res.push_back(path);
    else {
        int digit = digits[index] - '0';
        for (char c : strs[digit]) 
            dfs(digits, index + 1, path + c);
    }
}

int main() {
    string digits;
    cin >> digits;

    if (digits.empty()) cout << "[]" << endl;
    else {
        dfs(digits, 0, "");
        cout << "[";
        for (size_t i = 0; i < res.size(); ++i) {
            cout << "\"" << res[i] << "\"";
            if (i < res.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}