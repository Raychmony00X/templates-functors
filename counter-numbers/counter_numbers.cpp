#include <iostream>
#include <vector>
#include <algorithm>

#include <catch2/catch_test_macros.hpp>

class Counter {
public:
	Counter() : m_sum(0), m_count(0) {}

	void operator()(int num) {
		if (num % 3 == 0) {
			m_sum += num;
			m_count++;
		} else {
			return;
		}

	}

	int get_sum() const {
		return m_sum;
	}

	int get_count() const {
		return m_count;
	}

private:
	int m_sum;
	int m_count;

};

int main() {
	std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
	Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());
	std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

	return 0;
}

//Tests
//TEST_CASE("Ordinary array", "[test1]") {
//	std::vector<int> numbers = { 3, 1, 66, 5, 9 };
//	int expected_sum = 78;
//	int expected_count = 3;
//
//	Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());
//	CHECK(counter.get_sum() == expected_sum);
//	CHECK(counter.get_count() == expected_count);
//}
//
//TEST_CASE("All elements divine by 3", "[test2]") {
//	std::vector<int> numbers = { 3, 6, 9, 12, 99 };
//	int expected_sum = 129;
//	int expected_count = 5;
//
//	Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());
//	CHECK(counter.get_sum() == expected_sum);
//	CHECK(counter.get_count() == expected_count);
//}
//
//TEST_CASE("All elements doesn't divine by 3", "[test3]") {
//	std::vector<int> numbers = { 1, 2, 8, 4, 5 };
//	int expected_sum = 0;
//	int expected_count = 0;
//
//	Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());
//	CHECK(counter.get_sum() == expected_sum);
//	CHECK(counter.get_count() == expected_count);
//}