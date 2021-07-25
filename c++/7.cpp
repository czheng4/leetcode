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
  Problem: https://leetcode.com/problems/reverse-integer/
*/
class Solution {
public:
  int reverse(int x) {
    int last_digit;
    int tmp_x;
    long long int rv;

    tmp_x = x; 
    rv = 0;
    while (tmp_x != 0) {
      last_digit = tmp_x % 10;
      rv = rv * 10 + last_digit;
      tmp_x /= 10;
    }

    if (rv < -pow(2,31) || rv > pow(2,31) -1) return 0;

    return rv;
  }
};

int main(int argc, char **argv) {

  int x;
  Solution solution;

  if (argc != 2) {
    printf("bin/7 x");
    return 1;
  }

  x = atoi(argv[1]);
  
  cout << solution.reverse(x) << endl;

  return 0;


}



