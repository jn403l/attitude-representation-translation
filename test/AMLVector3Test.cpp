#include <catch2/catch_test_macros.hpp>
#include "AttitudeMathLib.h"

// 29:45

using namespace AML;

TEST_CASE("Vector3 Constructors", "[Vector3]")
{
	// Case 1
	Vector3 v;
	CHECK(v.x == 0.0);
	CHECK(v.y == 0.0);
	CHECK(v.z == 0.0);
	// Case 2
	v = Vector3(5.0);
	CHECK(v.x == 5.0);
	CHECK(v.y == 5.0);
	CHECK(v.z == 5.0);
	// Case 3
	v = Vector3(1.0, 2.0, 3.0);
	CHECK(v.x == 1.0);
	CHECK(v.y == 2.0);
	CHECK(v.z == 3.0);
	// Case 4
	double data[3] = {3.0, 2.0, 1.0};
	v = Vector3(data);
	CHECK(v.x == 3.0);
	CHECK(v.y == 2.0);
	CHECK(v.z == 1.0);	
}
