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
  Problem: https://leetcode.com/problems/unique-paths/
*/
class Solution {
public:
  int row, col;
  vector < vector <int> > cache;
  int uniquePaths(int m, int n) {
    size_t i;


    row = n;
    col = m;
    cache.resize(row + 1);
    for (i = 0; i < cache.size(); i++) cache[i].resize(col + 1, -1);
    return DFS(1, 1);
  }

  int DFS(int x, int y) {
    
    int total_path = 0;

    if (x > row || y > col) return 0;
    if (cache[x][y] != -1) return cache[x][y];
    if (x == row && y == col) { 
      return 1;
    }

    total_path += DFS(x + 1, y);
    total_path += DFS(x, y + 1);
    cache[x][y] = total_path;
    return total_path;
  }
};



int main(int argc, char **argv) {

 
  Solution solution;

  if (argc != 3) {
    printf("bin/62 m n");
    return 1;
  }

  cout << solution.uniquePaths(atoi(argv[1]), atoi(argv[2])) << endl;

  return 0;


}



