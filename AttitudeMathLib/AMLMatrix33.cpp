#include "AMLVector3.h"
#include "AMLMatrix33.h"

#include <iostream>

namespace AML
{

  // Default constructor
  Matrix33::Matrix33() :
    m11(0.0), m12(0.0), m13(0.0),
    m21(0.0), m22(0.0), m23(0.0),
    m31(0.0), m32(0.0), m33(0.0)
  {}

  // Scalar constructor
  Matrix33::Matrix33(double val) :
    m11(val), m12(val), m13(val),
    m21(val), m22(val), m23(val),
    m31(val), m32(val), m33(val)
  {}

  // Flat array constructor
  Matrix33::Matrix33(const double data_[9]) :
    m11(data_[0]), m12(data_[1]), m13(data_[2]),
    m21(data_[3]), m22(data_[4]), m23(data_[5]),
    m31(data_[6]), m32(data_[7]), m33(data_[8])
  {}

  // 2D array constructor
  Matrix33::Matrix33(const double data_[3][3]) :
    m11(data[0][0]), m12(data[0][1]), m13(data[0][2]),
    m21(data[1][0]), m22(data[1][0]), m23(data[1][0]),
    m31(data[2][0]), m32(data[2][0]), m33(data[2][0])  
  {}

  // Vector-based constructor
  Matrix33::Matrix33(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3) :
    m11(v1.x), m12(v2.x), m13(v3.x),
    m21(v1.y), m22(v2.y), m23(v3.y),
    m31(v1.z), m32(v2.z), m33(v3.z)
  {}

  // Compound assignment operators
  Matrix33& Matrix33::operator+=(const Matrix33 &rhs)
  {
    m11 += m11;
    m12 += m12;
    m13 += m13;
    m21 += m21;
    m22 += m22;
    m23 += m23;
    m31 += m31;
    m32 += m32;
    m33 += m33;
    return *this;
  }
  Matrix33& Matrix33::operator-=(const Matrix33 &rhs)
  {
    m11 -= m11;
    m12 -= m12;
    m13 -= m13;
    m21 -= m21;
    m22 -= m22;
    m23 -= m23;
    m31 -= m31;
    m32 -= m32;
    m33 -= m33;
    return *this;    
  }
  Matrix33& Matrix33::operator*=(const Matrix33 &rhs){}
  Matrix33& Matrix33::operator/=(const Matrix33 &rhs){}

  // Compound assignment operators
  Matrix33& Matrix33::operator+=(double rhs) {}
  Matrix33& Matrix33::operator-=(double rhs) {}
  Matrix33& Matrix33::operator*=(double rhs) {}
  Matrix33& Matrix33::operator/=(double rhs) {}

  // Identity matrix
  const Matrix33 Matrix33::identity() {}

  // Unary minus
  Matrix33 operator-(const Matrix33 &rhs) {}

  // Binary matrix-matrix operators
  Matrix33 operator+(const Matrix33 &lhs, const Matrix33 &rhs) {}
  Matrix33 operator-(const Matrix33 &lhs, const Matrix33 &rhs) {}

  // Matrix multiplication
  Matrix33 operator*(const Matrix33 &lhs, const Matrix33 &rhs) {}

  // Matrix division
  Matrix33 operator/(const Matrix33 &lhs, const Matrix33 &rhs) {}

  // Matrix-vector multiplication
  Matrix33 operator*(const Matrix33 &lhs, const Vector3 &rhs) {}

  // Matrix-scalar operators
  Matrix33 operator+(const Matrix33 &lhs, double s);
  Matrix33 operator-(const Matrix33 &lhs, double s);
  Matrix33 operator*(const Matrix33 &lhs, double s);
  Matrix33 operator/(const Matrix33 &lhs, double s);

  // Scalar-matrix versions for symmetry
  Matrix33 operator+(double s, const Matrix33 &lhs);
  Matrix33 operator-(double s, const Matrix33 &lhs);
  Matrix33 operator*(double s, const Matrix33 &lhs);
  Matrix33 operator/(double s, const Matrix33 &lhs);


  Vector3 diag(const Matrix33 &rhs);

  // Creates a diagonal matrix from a Vector3
  Matrix33 diag(const Vector3 &rhs);

  // Returns the transpose of the matrix
  Matrix33 transpose(const Matrix33 &rhs);

  // Computes the determinant of the matrix.
  // Used for checking invertibility and orientation.
  double determinant(const Matrix33 &rhs);

  // Computes the inverse of the matrix.
  // Caller is responsible for ensuring determinant != 0.
  Matrix33 inverse(const Matrix33 &rhs);

  // Stream output
  std::ostream &operator<<(const std::ostream &os, const Matrix33 &obj);
}; // namespace AML

