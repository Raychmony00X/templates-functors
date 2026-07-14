#include <iostream>
#include <vector>

#include <catch2/catch_test_macros.hpp>

template <typename T>
T GetSquare(T& num) {
	return num * num;
}

template <typename T>
void SquareVector(std::vector<T>& vec) {
	for (T& num : vec) {
		num = num * num;
	}

}

int main() {
	int num = 4;
	int result = GetSquare(num);
	std::cout << result << std::endl;

	std::vector<int> nums = { -1, 4, 8 };
	SquareVector(nums);
	for (int n : nums) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

}

//Tests

//TEST_CASE ("Test GetSquare", "[test1]") {
//	float num = 2.0f;
//	float expected = 4.0f;
//	CHECK(GetSquare(num) == expected);
//}
//
//TEST_CASE("Test SquareVector", "[test2]") {
//	std::vector<float> nums = { -2.0f, 4.0f, 8.0f };
//	std::vector<float> expected = { 4.0f, 16.0f, 64.0f };
//	SquareVector(nums);
//	REQUIRE(nums == expected);
//}