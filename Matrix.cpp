#include "Matrix.h"
#include <math.h>
#include <iostream>


Matrix::Matrix(std::istream& inp, int m)
{
  double holder = 0.0;
  grid = nullptr;
  grid = new double*[m];

  for (int x = 0; x < m ; x++)
  {
    grid[x] = new double[m];
  }

  for (int i = 0 ; i < m;i++)
  {
    for (int j =0 ; j< m; j++)
    {
      inp >> holder;
      grid[i][j] = holder;
    }
  }
  n = m;
}// Create storage for n x n matrix and read its n*n values from "inp"
Matrix::Matrix(const Matrix& M, int r, int c)
{
  n= M.n-1;
  grid = new double *[M.n-1];
  for (int x = 0; x < M.n-1;x++)
  {
    grid[x] = new double [M.n-1];
  }
  for (int i = 0; i < M.n;i++)
  {
    for (int j = 0; j < M.n;j++)
    {
      if (i!=r && j!=c)
      {
        if (i < r && j < c)
        {
          grid[i][j] = M.grid[i][j];

        }
        if(i > r && j < c)
        {
          grid[i-1][j] = M.grid[i][j];
        }
        if (i > r && j > c)
        {
          grid[i-1][j-1]= M.grid[i][j];
        }
        if (i < r && j > c)
        {
          grid[i][j-1]= M.grid[i][j];
        }
      }
    }
  }

} // Create Sr,c(M); if M is nxn, the new matrix will be (n-1)x(n-1)
double Matrix::det() const
{
  if (n == 1)
  {
    return grid[0][0];
  }
  else if (n == 2)
  {
    return (grid[0][0]*grid[1][1] - grid[1][0]*grid[0][1]);
  }
  else
  {
  double answer = 0.0;
  for (int x = 0; x< n ; x++)
  {
    Matrix T(*this,0,x);
    answer = answer + (pow(-1,x)*(grid[0][x]*T.det()));
  }
  return answer;
  }

} 
Matrix::~Matrix()
{
  for (int x = 0; x < n ; x++)
  {
    delete[] grid[x];
  }
  delete [] grid;
}
