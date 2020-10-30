#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>



class Matrix // always a square matrix
{
public:
    Matrix(std::istream& inp, int m); // Create storage for n x n matrix and read its n*n values from "inp"   
    Matrix(const Matrix& M, int r, int c); // Create Sr,c(M); if M is nxn, the new matrix will be (n-1)x(n-1)
    double det() const; //determinatant 
    ~Matrix();


  private:
    double** grid;
    int n;
    
};
#endif
