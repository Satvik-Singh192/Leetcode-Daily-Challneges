/*
 * 1290. Convert Binary Number in a Linked List to Integer
 * Date: 14-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head != nullptr) {
            result = result * 2 + head->val;
            head = head->next;
        }
        return result;
    }
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
