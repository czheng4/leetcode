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
  Problem: https://leetcode.com/problems/valid-number/
*/
class Solution {
public:
  bool isNumber(string s) {

    bool can_have_e = false;
    bool can_have_dot = true;
    int i = 0;

    if (s.size() == 0) return false;
    
    /* read sign */
    if (s[i] == '-' || s[i] == '+') i = 1;

    /* read dot */
    if (s[i] == '.') {
      i++;
      can_have_dot = false;
      if (s.size() == i) return false;
    }

    /* make sure we can have e/E */
    if (i < s.size() && s[i] >= '0' && s[i] <= '9') {
      i++;
      can_have_e = true;
    }


    for (; i < s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
      } else if ((s[i] == 'e' || s[i] == 'E') && can_have_e && i + 1 < s.size()) {
        can_have_e = false;
        can_have_dot = false;
        if (i + 1 < s.size() && (s[i+1] == '-' || s[i+1] == '+')) {
          i++;
          if (i + 1 == s.size()) return false; // make sure we have numbers followed
        }

      } else if (s[i] == '.' && can_have_dot) {
        can_have_dot = false;
      } else {
        return false;
      }
    }

    return true;
  }
};

int main(int argc, char **argv) {

  Solution solution;

  if (argc != 2) {
    printf("bin/65 s");
    return 1;
  }

  cout << solution.isNumber(argv[1]) << endl;

  return 0;


}



