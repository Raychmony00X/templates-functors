#include <iostream>

#include <catch2/catch_test_macros.hpp>

class Counter {
public:
	Counter() : m_sum(0), m_count(0) {}

	void operator()(int* arr, int size) {
		if (size <= 0) return;

		int i = 0;
		while (i < size) {
			if (arr[i] % 3 == 0) {
				m_sum += arr[i];
				m_count++;
			}

			i++;
		}

	}

	int get_sum() {
		return m_sum;
	}

	int get_count() {
		return m_count;
	}

private:
	int m_sum;
	int m_count;

};

int main() {
	int arr[] = { 4, 1, 3, 6, 25, 54 };
	int size = sizeof(arr) / sizeof(arr[0]);

	Counter counter;
	counter(arr, size);
	std::cout << counter.get_sum() << std::endl;
	std::cout << counter.get_count() << std::endl;

	return 0;
}

//Tests
//TEST_CASE("Ordinary array", "[test1]") {
//	int arr[] = { 3, 1, 66, 5, 9 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int expected_sum = 78;
//	int expected_count = 3;
//
//	Counter counter;
//	counter(arr, size);
//	CHECK(counter.get_sum() == expected_sum);
//	CHECK(counter.get_count() == expected_count);
//}
//
//TEST_CASE("All elements divine by 3", "[test2]") {
//	int arr[] = { 3, 6, 9, 12, 99 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int expected_sum = 129;
//	int expected_count = size;
//
//	Counter counter;
//	counter(arr, size);
//	CHECK(counter.get_sum() == expected_sum);
//	CHECK(counter.get_count() == expected_count);
//}
//
//TEST_CASE("All elements doesn't divine by 3", "[test3]") {
//	int arr[] = { 1, 2, 8, 4, 5 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int expected_sum = 0;
//	int expected_count = 0;
//
//	Counter counter;
//	counter(arr, size);
//	CHECK(counter.get_sum() == expected_sum);
//	CHECK(counter.get_count() == expected_count);
//}