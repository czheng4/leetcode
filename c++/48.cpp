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
  Problem: https://leetcode.com/problems/rotate-image
*/
class Solution {
public:
  void rotate(vector < vector<int> >& matrix) {
    int i, j, k, m, n;
    int tmp, tmp1, tmp2, tmp3, tmp4;

    n = matrix.size();

    for (i = 0; i < n / 2; i++) {
      for (j = i; j < n - 1 - i; j++) {

        // tmp1 = matrix[i][j];
        // tmp2 = matrix[j][n - i - 1];
        // tmp3 = matrix[n - i - 1][n - j - 1];
        // tmp4 = matrix[n - j - 1][i];


        // matrix[i][j] = tmp4;
        // matrix[j][n - i - 1] = tmp1;
        // matrix[n - i - 1][n - j - 1] = tmp2;
        // matrix[n - j - 1][i] = tmp3;


        // matrix[i][j] = matrix[n - j - 1][i];
        
        tmp = matrix[n - j - 1][i];
        
        matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1] = matrix[i][j];
        matrix[i][j] = tmp;
       
        // cout << tmp1 << " " << tmp2 << " " << tmp3 << " " << tmp4 << endl;

      }
    }

  }
};

int main(int argc, char **argv) {

  int i, j;
  int num_rows;
  Solution solution;
  vector < vector<int> > matrix;

  if (argc <= 1 || (int) sqrt(argc - 1) != (double) sqrt(argc - 1)) {
    printf("bin/48 num1 num2 num3 ...");
    return 1;
  }

  num_rows = sqrt(argc - 1);

  matrix.resize(num_rows);
  for (i = 0; i < num_rows; i++) {
    for (j = 0; j < num_rows; j++) {
      matrix[i].push_back(atoi(argv[1 + i * num_rows + j]));
    }
  } 

  

  solution.rotate(matrix);

  for (i = 0; i < num_rows; i++) {
    for (j = 0; j < num_rows; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;


}



