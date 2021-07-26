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
  Problem: https://leetcode.com/problems/longest-common-prefix/
*/
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string rv;
    int i, j;

    if (strs.size() == 0) return "";
    rv = strs[0];
    for (i = 1; i < strs.size(); i++) {
      for (j = 0; j < rv.size() && j < strs[i].size(); j++) {
        if (rv[j] != strs[i][j]) break;
      }
      if (j == 0) return "";
      else rv = rv.substr(0, j);
    }

    return rv;
  }
};

int main(int argc, char **argv) {

  int i;
  Solution solution;
  vector <string> strs;

  if (argc <= 1) {
    printf("bin/14 str1 str2 str3 ...");
    return 1;
  }

  for (i = 1; i < argc; i++) strs.push_back(argv[i]);
  

  cout << solution.longestCommonPrefix(strs) << endl;

  return 0;


}



