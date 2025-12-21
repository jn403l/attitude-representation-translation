#ifndef AML_MATRIX33_H
#define AML_MATRIX33_H

#include <iostream>

namespace AML
{
  // Forward declaration of Vector3 class
  class Vector3;
  // ============================================================
  // Matrix33
  //
  // Represents a 3x3 double-precision matrix.
  //
  // Intended use:
  // - Attitude / orientation mathematics
  // - Rotation matrices
  // - Linear algebra operations in 3D
  // ============================================================
  class Matrix33
  {
  public:
    
    // ------------------------------------------------------------
    // Storage
    //
    // A union allows the same memory to be accessed as:
    //
    // 1) data[row][col] for algorithmic access
    // 2) named elements m11 ... m33 for readability
    // ------------------------------------------------------------
    union
    {
      double data[3][3];
      struct { double m11, m12, m13, m21, m22, m23, m31, m32, m33; };
    };

    // ------------------------------------------------------------
    // Constructors
    // ------------------------------------------------------------

    // Default constructor
    // Intended to initialize all elements to zero.
    Matrix33();

    // Scalar constructor
    // Initializes all elements to the same scalar value.
    // Useful for quick testing or uniform matrices.
    explicit Matrix33(double val);

    // Flat array constructor
    // Interprets data as 9 elements in row-major order
    explicit Matrix33(const double data[9]);

    // 2D array constructor
    // Copies from a 3x3 row-major array.
    explicit Matrix33(const double data[3][3]);

    // Vector-based constructor
    // Builds a matrix using three vectors.
    // - v1, v2, v3 represent columns
    // Common in attitude math to treat vectors as columns.
    explicit Matrix33(const Vector3& v1, const Vector3& v2, const Vector3& v3);

    // ------------------------------------------------------------
    // Compound assignment operators
    //
    // These modify "this" and return "this".
    // ------------------------------------------------------------
    Matrix33& operator+=(const Matrix33& rhs);
    Matrix33& operator-=(const Matrix33& rhs);
    Matrix33& operator*=(const Matrix33& rhs);
    Matrix33& operator/=(const Matrix33& rhs);

    // ------------------------------------------------------------
    // Compound assignment operators
    // Applies the scalar to every element
    // ------------------------------------------------------------
    Matrix33& operator+=(double rhs);
    Matrix33& operator-=(double rhs);
    Matrix33& operator*=(double rhs);
    Matrix33& operator/=(double rhs);    


    // ------------------------------------------------------------
    // Identity matrix
    //
    // Returns:
    //   [ 1 0 0 ]
    //   [ 0 1 0 ]
    //   [ 0 0 1 ]
    //
    // Static because identity does not depend on any instance.
    // ------------------------------------------------------------
    static const Matrix33 identity();
    
  }; // class Matrix33

  // ============================================================
  // Unary operators
  // ============================================================

  // Unary minus
  // Negates all elements of the matrix.
  Matrix33 operator-(const Matrix33& rhs);

  // ============================================================
  // Binary matrix-matrix operators
  //
  // These return new matrices and do not modify inputs.
  // ============================================================
  Matrix33 operator+(const Matrix33& lhs, const Matrix33& rhs);
  Matrix33 operator-(const Matrix33& lhs, const Matrix33& rhs);
  
  // Matrix multiplication
  Matrix33 operator*(const Matrix33& lhs, const Matrix33& rhs);

  // Matrix division
  Matrix33 operator/(const Matrix33& lhs, const Matrix33& rhs);

  // ============================================================
  // Matrix-vector multiplication
  //
  // Applies the linear transformation represented by the matrix
  // to a Vector3.
  // ============================================================
  Matrix33 operator*(const Matrix33& lhs, const Vector3& rhs);

  // ============================================================
  // Matrix-scalar operators
  //
  // Scalar is applied element-wise.
  // ============================================================
  Matrix33 operator+(const Matrix33& lhs, double s);
  Matrix33 operator-(const Matrix33& lhs, double s);
  Matrix33 operator*(const Matrix33& lhs, double s);
  Matrix33 operator/(const Matrix33& lhs, double s);

  // Scalar-matrix versions for symmetry
  Matrix33 operator+(double s, const Matrix33& lhs);
  Matrix33 operator-(double s, const Matrix33& lhs);
  Matrix33 operator*(double s, const Matrix33& lhs);
  Matrix33 operator/(double s, const Matrix33& lhs);

  // ============================================================
  // Matrix utility functions
  // ============================================================

  // Extracts the diagonal elements as a Vector3
  Vector3 diag(const Matrix33& rhs);
  
  // Creates a diagonal matrix from a Vector3
  Matrix33 diag(const Vector3& rhs);

  // Returns the transpose of the matrix
  Matrix33 transpose(const Matrix33& rhs);

  // Computes the determinant of the matrix.
  // Used for checking invertibility and orientation.
  double determinant(const Matrix33& rhs);
  

  // Computes the inverse of the matrix.
  // Caller is responsible for ensuring determinant != 0.
  Matrix33 inverse(const Matrix33& rhs);

  // Stream output
  std::ostream& operator<<(const std::ostream& os, const Matrix33& obj);
}; // namespace AML

#endif // AML_MATRIX33_H
