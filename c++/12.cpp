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
  Problem: https://leetcode.com/problems/integer-to-roman/
*/
class Solution {
public:
  string intToRoman(int num) {
    string rv;
    int key;
    map <int, string> m;
    map <int, string>::reverse_iterator it;
    
    m[1] = "I";
    m[5] = "V";
    m[10] = "X";
    m[50] = "L";
    m[100] = "C";
    m[500] = "D";
    m[1000] = "M";
    m[4] = "IV";
    m[9] = "IX";
    m[40] = "XL";
    m[90] = "XC";
    m[400] = "CD";
    m[900] = "CM";

    rv = "";
    for (it = m.rbegin(); it != m.rend() && num != 0; ++it) {
      while (num - it->first >= 0) {
        rv += it->second;
        num -= it->first;
      }
    }

    return rv;

  }
};




int main(int argc, char **argv) {

  string s, p;
  Solution solution;
  char c;
  if (argc <= 1 ) {
    printf("bin/12 num");
    return 1;
  }

  
  cout << solution.intToRoman(atoi(argv[1])) << endl;

  return 0;


}



