#ifndef AML_VECTOR3_H
#define AML_VECTOR3_H

#include <iostream>

namespace AML {
  
  // ============================================================
  // Vector3
  //
  // Represents a 3D vector with double-precision components.
  //
  // Design goals:
  // - Lightweight (no dynamic allocation)
  // - Plain old data (POD)-like memory layout
  // - Usable in math-heavy code (attitude / orientation / physics)
  // - Convenient access via both array indexing and named components
  // ============================================================
  class Vector3
  {
  public:

    // ------------------------------------------------------------
    // Storage
    //
    // A union is used so the same memory can be accessed as:
    //   - data[0], data[1], data[2]
    //   - x, y, z
    // ------------------------------------------------------------
    union
    {
      double data[3];
      struct{ double x, y, z; };
    };

    // ------------------------------------------------------------
    // Constructors
    // ------------------------------------------------------------

    // Default constructor
    // Intended to initialize to (0, 0, 0)
    Vector3();
    
    // Scalar constructor
    // Sets all components to the same value:
    // (val, val, val)
    Vector3(double val);
    
    // Component-wise constructor
    // Directly initializes (x, y, z)
    Vector3(double x, double y, double z);
    
    // Array constructor
    // Copies values from a raw double[3]
    // Assumes input array has at least 3 elements
    Vector3(const double data[3]);

    // ------------------------------------------------------------
    // Compound assignment operators
    //
    // These modify "this" in place and return "this"
    // to allow chaining.
    // These are component-wise operations
    // ------------------------------------------------------------
    Vector3& operator+=(const Vector3& rhs);
    Vector3& operator-=(const Vector3& rhs);
    Vector3& operator*=(const Vector3& rhs);
    Vector3& operator/=(const Vector3& rhs);

    // ------------------------------------------------------------
    // Compound assignment operators
    //
    // Applies the scalar to each component
    // ------------------------------------------------------------
    Vector3& operator+=(double s);
    Vector3& operator-=(double s);
    Vector3& operator*=(double s);
    Vector3& operator/=(double s);

    // ------------------------------------------------------------
    // Axis helper functions
    //
    // Return unit vectors aligned with coordinate axes.
    // Static because they do not depend on any instance.
    // ------------------------------------------------------------
    static const Vector3 xAxis();
    static const Vector3 yAxis();
    static const Vector3 zAxis();

  }; // Vector3

  // ============================================================
  // Unary operators
  // ============================================================

  // Unary minus
  // Returns a new vector with all components negated.
  Vector3 operator-(const Vector3& rhs);

  // ============================================================
  // Binary vector-vector operators
  //
  // These return new vectors (do not modify inputs).
  // Operations are component-wise.
  // ============================================================
  Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
  Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
  Vector3 operator*(const Vector3& lhs, const Vector3& rhs);
  Vector3 operator/(const Vector3& lhs, const Vector3& rhs);

  // ============================================================
  // Vector-scalar operators (vector on the left)
  //
  // Applies the scalar to each component.
  // ============================================================
  Vector3 operator+(const Vector3& lhs, double s);
  Vector3 operator-(const Vector3& lhs, double s);
  Vector3 operator*(const Vector3& lhs, double s);
  Vector3 operator/(const Vector3& lhs, double s);

  // ============================================================
  // Vector-scalar operators (scalar on the left)
  //
  // These exist for symmetry
  // ============================================================
  Vector3 operator+(double s, Vector3& rhs);
  Vector3 operator-(double s, Vector3& rhs);
  Vector3 operator*(double s, Vector3& rhs);
  Vector3 operator/(double s, Vector3& rhs);


  // ============================================================
  // Vector math utilities
  // ============================================================

  // Euclidean length (magnitude) of the vector
  double norm(const Vector3& rhs);

  // Normalizes the vector in place
  void normalize(Vector3& rhs);

  // Returns a normalized copy of the input vector
  // Does not modify the original.
  Vector3 unit(const Vector3& rhs);

  // Cross product
  Vector3 cross(const Vector3& lhs, const Vector3& rhs);

  // Dot product
  double dot(const Vector3& lhs, const Vector3& rhs);

  // ============================================================
  // Stream output
  // Allows:
  // std::cout << v;
  // ============================================================
  std::ostream& operator<<(std::ostream& os, const Vector3& obj);

} // AML

#endif // AML_VECTRO3_H
