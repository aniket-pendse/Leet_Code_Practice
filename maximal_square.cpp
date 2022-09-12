/*
Question link: https://leetcode.com/problems/maximal-square/
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/
class Solution {
public:
  
  int maximalSquare(vector<vector<char>>& matrix) {
    size_t m = matrix.size();
    size_t n = matrix[0].size();
    int max_count = 0;
    if(0 == m || 0 == n)
    {
      return max_count;
    }
    std::vector<std::vector<int>> matrix_int(m, std::vector<int> (n, 0));

    // Initialize last column
    for(size_t i = 0; i < m; ++i)
    {
      if(matrix[i][n-1] == '0')
      {
        matrix_int[i][n-1] = 0;
      }
      if(matrix[i][n-1] == '1')
      {
        matrix_int[i][n-1] = 1;
      }

      max_count = std::max(max_count,matrix_int[i][n-1]);
    }

    // Initialize last row
    for(size_t j = 0; j< n; ++j)
    {
      if(matrix[m-1][j] == '0')
      {
        matrix_int[m-1][j] = 0;
      }
      if(matrix[m-1][j] == '1')
      {
        matrix_int[m-1][j] = 1;
      }

      max_count = std::max(max_count,matrix_int[m-1][j]);
    }
    
    // Calculate square size
    for(int i = m-2; i >= 0; --i)
    {
      for(int j = n-2; j >= 0; --j)
      {
        if(matrix[i][j] == '1')
        {
          matrix_int[i][j] = 1 + std::min(std::min(matrix_int[i][j+1], matrix_int[i+1][j]), matrix_int[i+1][j+1]);
        }
        else
        {
          matrix_int[i][j] = 0;
        }
        
        max_count = std::max(max_count, matrix_int[i][j]);
      }
    }
    
    return (max_count*max_count);
  }
};

int main()
{
  return 0;
}