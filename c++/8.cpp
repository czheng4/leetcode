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
  Problem: https://leetcode.com/problems/string-to-integer-atoi/
*/
class Solution {
public:
  int myAtoi(string s) {
    int sign = 1;
    bool ignore_lw = true;
    int i;
    long long int rv;

    const int lower_bound = -pow(2,31);
    const int upper_bound = pow(2,31) - 1;

    i = 0;
    while(s[i] == ' ') i++;
    if (i < s.size() && s[i] == '-') { sign = 0; i++; }
    else if (i < s.size() && s[i] == '+') { sign = 1; i++; }

    rv = 0;
    for (; i < s.size(); i++) {
  
      if (s[i] >= '0' && s[i] <= '9') {
        if (sign == 0) rv = rv * 10 - (s[i] - '0');
        else rv = rv * 10 + s[i] - '0';
        if (rv < lower_bound) rv = lower_bound;
        if (rv > upper_bound) rv = upper_bound;
      } else {
        break;
      }

    }

    return rv;

  }
};
int main(int argc, char **argv) {

  Solution solution;

  if (argc != 2) {
    printf("bin/8 s");
    return 1;
  }

  cout << solution.myAtoi(argv[1]) << endl;

  return 0;


}



