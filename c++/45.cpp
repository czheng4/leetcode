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
  Problem: https://leetcode.com/problems/jump-game-ii/
*/
class Solution {
public:

  vector <int> cache;
  int jump(vector<int>& nums) {
    cache.resize(nums.size(), -1);
    return recursion(nums, 0);
  }
  int recursion(vector<int>& nums, int index) {
    int rv, i;

    if (index == nums.size() - 1) return 0;
    if (cache[index] != -1) return cache[index];
    rv = 10000000;
    for (i = 1; i <= nums[index] && index + i < nums.size(); i++) {
      rv = std::min(1 + recursion(nums, index + i), rv);
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
    printf("bin/45 num1 num2 ...");
    return 1;
  }

  for (i = 1; i < argc; i++) {
    nums.push_back(atoi(argv[i]));
  }
  
  cout << solution.jump(nums) << endl;

  return 0;


}



