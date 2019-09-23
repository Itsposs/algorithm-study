
#include <vector>   // vector
#include <chrono>   // now()


void insert(std::vector<int> &vec) {
	typedef std::vector<int>::size_type size_type;

	for (size_type i = 0; i < vec.size(); ++i) {
		for (int j = i; j > 0; j--) {
			if (vec[j] < vec[j - 1]) {
				std::swap(vec[j], vec[j - 1]);
			}
		}
	}
}

// test
#include <iostream>

void test_insert() {
	
	std::vector<int> vec1{6, 3, 1, 5, 12, 7, 4};
	insert(vec1);
	for(const auto val : vec1)
		std::cout << val << " ";
	std::cout << std::endl;
}


typedef struct Node {

	int val;
	struct Node *next;
}LNode;

#include <cassert>

void insert(LNode *head) {
	
	assert(head -> next);

	
}


int main(int argc, char *argv[]) {

	using namespace std::chrono;
	auto beg = system_clock::now();
	
	test_insert();
	
	auto end = system_clock::now();
	std::cout << "time: " << duration_cast<milliseconds> (end - beg).count()
			  << " ms."   << std::endl;
	return 0;
}
