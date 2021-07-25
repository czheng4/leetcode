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
  Problem: https://leetcode.com/problems/regular-expression-matching/
*/
class Solution {
public:

  vector < vector<int> > cache;
  bool isMatch(string s, string p) {
    int i;
    cache.resize(s.size() + 1);
    for (i = 0; i < cache.size(); i++) cache[i].resize(p.size() + 1, -1);
    return recursion(s, p, 0, 0);
  }

  bool recursion(string &s, string &p, int sindex, int pindex) {

    int i,j;
    bool rv, is_matched;

    if (cache[sindex][pindex] != -1) return cache[sindex][pindex] == 1;
    if (pindex == p.size()) return sindex == s.size();

    is_matched = (sindex < s.size() && (s[sindex] == p[pindex] || p[pindex] == '.'));
    
    /*
      case1 - we ignore start and the char before start.
      case2 - we match it and move the string index to the next one.
      case3 - we don't have start, we simply move both string and patten pointer to next one.
    */
    if (pindex + 2 <= p.size() && p[pindex + 1] == '*') {
      rv = recursion(s, p, sindex, pindex + 2) || (is_matched && recursion(s, p, sindex + 1, pindex));
    } else {
      rv = is_matched && recursion(s, p, sindex + 1, pindex + 1);
    }

    cache[sindex][pindex] = rv == true;
    return rv;
    
    
  }
};

int main(int argc, char **argv) {

  string s, p;
  Solution solution;
  char c;
  if (argc <= 1 || argc > 3) {
    printf("bin/10 example_num or bin/10 s p");
    return 1;
  }

  if (argc == 3) {
    s = argv[1];
    p = argv[2];
  } else {

    c = argv[1][0];
    if (c == '1') {
      s = "aa";
      p = "a";
    } else if (c == '2') {
      s = "aa";
      p = "a*";
    } else if (c == '3') {
      s = "ab";
      p = ".*";
    } else if (c == '4') {
      s = "aab";
      p = "c*a*b";
    } else if (c == '5') {
      s = "mississippi"; 
      p = "mis*is*p*.";
    } else {
      printf("bin/10 example_num");
      return 1;
    }
  }

  cout << solution.isMatch(s, p) << endl;

  return 0;


}



