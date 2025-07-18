#pragma once

// 常用头文件
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cmath>
#include <cassert>

// 常用命名空间
using namespace std;

// 常用类型定义
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;

// 常用宏定义
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// LeetCode 常用数据结构定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 实用工具函数
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void print2DVector(const vector<vector<int>>& vec) {
    cout << "[" << endl;
    for (const auto& row : vec) {
        cout << "  ";
        printVector(row);
    }
    cout << "]" << endl;
}

ListNode* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}
