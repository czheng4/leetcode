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
  Problem: https://leetcode.com/problems/jump-game/
*/
class Solution {
public:

  vector <int> cache;
  bool canJump(vector<int>& nums) {
    cache.resize(nums.size(), -1);
    return recursion(nums, 0);  
  }
  bool recursion(vector<int>& nums, int index) {
    int i;
    bool rv = false;

    if (index == nums.size() - 1) return true;
    if (cache[index] != -1) return cache[index];
   
    for (i = 1; i <= nums[index] && index + i < nums.size() && rv == false; i++) {
      rv = recursion(nums, index + i);
    }
    cache[index] = rv;
    return rv;
  }

};

int main(int argc, char **argv) {

  int i;
  Solution solution;
  vector <int> nums;

  if (argc <= 1) {
    printf("bin/55 num1 num2 ...");
    return 1;
  }

  for (i = 1; i < argc; i++) {
    nums.push_back(atoi(argv[i]));
  }
  
  cout << solution.canJump(nums) << endl;

  return 0;


}



