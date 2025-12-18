#include "AMLVector3.h"
#include <cmath>

namespace AML {

  // Default Constructor
  Vector3::Vector3()
  : x(0.0), y(0.0), z(0.0) {}

  // Scalar constructor
  Vector3::Vector3(double val)
  : x(val), y(val), z(val) {}

  // Component-wise constructor
  Vector3::Vector3(double x_, double y_, double z_)
  : x(x_), y(y_), z(z_) {}

  // Array constructor
  Vector3::Vector3(const double data_[3])
  : x(data_[0]), y(data_[1]), z(data_[2]) {}

  // Compound assignment operators
  Vector3& Vector3::operator+=(const Vector3 &rhs)
  {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }
  Vector3& Vector3::operator-=(const Vector3 &rhs)
  {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }
  Vector3& Vector3::operator*=(const Vector3 &rhs){
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
  }
  Vector3& Vector3::operator/=(const Vector3 &rhs){
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
  }

  // Compound assignment operators
  Vector3& Vector3::operator+=(double s)
  {
    x += s;
    y += s;
    z += s;
    return *this;
  }
  Vector3& Vector3::operator-=(double s)
  {
    x -= s;
    y -= s;
    z -= s;
    return *this;
  }
  Vector3& Vector3::operator*=(double s)
  {
    x *= s;
    y *= s;
    z *= s;
    return *this;    
  }
  Vector3& Vector3::operator/=(double s)
  {
    x /= s;
    y /= s;
    z /= s;
    return *this;
  }

  // Axis helper functions
  const Vector3 Vector3::xAxis()
  {
    return Vector3(1.0, 0.0, 0.0);
  }
  const Vector3 Vector3::yAxis()
  {
    return Vector3(0.0, 1.0, 0.0);    
  }
  const Vector3 Vector3::zAxis()
  {
    return Vector3(0.0, 0.0, 1.0);    
  }

  // ============================================================
  // Unary operators
  // ============================================================

  // Unary minus
  Vector3 operator-(const Vector3& rhs)
  {
    return Vector3(-rhs.x, -rhs.y, -rhs.z);
  }

  // ============================================================
  // Binary vector-vector operators
  // ============================================================
  Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
  {
    return (Vector3(lhs) += rhs);
  }
  Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
  {
    return (Vector3(lhs) -= rhs);
  }
  Vector3 operator*(const Vector3& lhs, const Vector3& rhs)
  {
    return (Vector3(lhs) *= rhs);
  }
  Vector3 operator/(const Vector3& lhs, const Vector3& rhs)
  {
    return (Vector3(lhs) /= rhs);
  }

  // ============================================================
  // Vector-scalar operators (vector on the left)
  //
  // Applies the scalar to each component.
  // ============================================================
  Vector3 operator+(const Vector3& lhs, double s)
	{
		return (Vector3(lhs) += s);
	}
  Vector3 operator-(const Vector3& lhs, double s)
	{
		return (Vector3(lhs) -= s);
	}
  Vector3 operator*(const Vector3& lhs, double s)
	{
		return (Vector3(lhs) *= s);
	}
  Vector3 operator/(const Vector3& lhs, double s)
	{
		return (Vector3(lhs) /= s);
	}

  // ============================================================
  // Vector-scalar operators (scalar on the left)
  //
  // These exist for symmetry
  // ============================================================
  Vector3 operator+(double s, Vector3& rhs)
	{
		return (Vector3(s) += rhs);
	}
  Vector3 operator-(double s, Vector3& rhs)
	{
		return (Vector3(s) -= rhs);
	}
  Vector3 operator*(double s, Vector3& rhs)
	{
		return (Vector3(s) *= rhs);
	}
  Vector3 operator/(double s, Vector3& rhs)
	{
		return (Vector3(s) /= rhs);
	}


  // ============================================================
  // Vector math utilities
  // ============================================================

  // Euclidean length (magnitude) of the vector
  double norm(const Vector3& rhs)
	{
		return sqrt(rhs.x*rhs.x + rhs.y*rhs.y + rhs.z*rhs.z);
	}

  // Normalizes the vector in place
  void normalize(Vector3& rhs)
	{
		double mag = norm(rhs);
		if (mag > 0.0)
		{
			rhs /= mag;
		}
	}

  // Returns a normalized copy of the input vector
  // Does not modify the original.
  Vector3 unit(const Vector3& rhs)
	{
		double mag = norm(rhs);
		if (mag > 0.0)
		{
			return (Vector3(rhs) /= mag);
		}
		return rhs;
	}

  // Cross product
  Vector3 cross(const Vector3& lhs, const Vector3& rhs)
	{
		// lhs x y z
		// rhs x y z
		double x = (lhs.y * rhs.z) - (lhs.z * rhs.y);
		double y = (lhs.x * rhs.z) - (lhs.z * rhs.x);
		double z = (lhs.x * rhs.y) - (lhs.y * rhs.x);
		return Vector3(x, y, z);
	}

  // Dot product
  double dot(const Vector3& lhs, const Vector3& rhs)
	{
		return (rhs.x * lhs.x + rhs.y * lhs.y + rhs.z * lhs.z);
	}

  // ============================================================
  // Stream output
  // Allows:
  // std::cout << v;
  // ============================================================
  std::ostream& operator<<(std::ostream& os, const Vector3& obj)
	{
		os << "[" << obj.x << ", " << obj.y << ", " << obj.z << "]";
		return os;
	}

} // AML
