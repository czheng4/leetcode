#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*
  Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/



struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int i;
    int size;
    ListNode *node, *tmp;


    for (size = 0, node = head; node != nullptr; node = node->next, size++);

    n = size - n + 1;
    if (n == 1) {
      node = head->next;
      delete head;
      return node;
    }


    node = head;
    for (i = 0; i < n - 2 && node != nullptr; i++, node = node->next);
    if (node == nullptr || node->next == nullptr) return head;
    tmp = node->next;
    node->next = tmp->next;
    delete tmp;

    return head;


    
  }
};

int main(int argc, char **argv) {

  size_t i;
  Solution solution;
  ListNode *head, *n, *prev_n;

  if (argc <= 1) {
    printf("bin/19 val1 val2 ... rm_nth");
    return 1;
  }

  head = nullptr;
  prev_n = nullptr;
  for (i = 1; i < argc - 1; i++) {
    n = new ListNode(atoi(argv[i]));
    if (i == 1) head = n;
    if (prev_n != nullptr) prev_n->next = n;
    prev_n = n;
  }

  head = solution.removeNthFromEnd(head, atoi(argv[argc - 1]));
  n = head;
  for (; n != nullptr; n = n->next) {
    printf("%d ", n->val);
  }
  printf("\n");

  return 0;


}



