

// 限制:
// 1.必须为整数
// 2.浪费空间

#include <list>   // list
#include <vector>    // vector
#include <chrono>    // now()
#include <algorithm> // max_element


// v1
void bucket(std::vector<int> &vec) {
	// 元素最大值,eg：{1, 3, 5, 100}
	// vector<int> ret(101, 0);
	auto size = std::max_element(vec.begin(), vec.end());
	std::vector<int> ret(*size + 1, 0);
	typedef std::vector<int>::size_type size_type;
	
	for(size_type i = 0; i < vec.size(); ++i) { // 尽量i++
		ret[vec[i]]++;
	}
	
	int k = 0;
	for (size_type i = 0; i < ret.size(); ++i) {
		for (size_type j = 1; j != (unsigned)ret[i]; ++j) {
			//std::cout << j << " ";
			vec[k++] = i;
		}
	}
	//std::cout << std::endl;
}


// v2

typedef struct KNode {
	int key;
	struct KNode *next;
} KNode;

void bucket(int keys[], int n) {
	constexpr int size = 10;
	// size number of bucket
	//KNode **table = (KNode **)malloc(size * sizeof(KNode *));

	// replace
	KNode **table = new KNode *[size];
	// initialization
	for (int i = 0; i < size; ++i) { // head node
		table[i] = new KNode;
		table[i] -> key = 0;
		table[i] -> next = nullptr;
	}
	
	for (int j = 0; j < size; j++) {
		KNode *q = new KNode;
		q -> key = keys[j];
		q -> next = nullptr;

		int index = keys[j] / size;
		KNode *p = table[index];
		if (p -> key == 0) {
			p -> next = q;
			p -> key++;   // number of node
		} else {
			while (p -> next && p -> next -> key <= q -> key)  // insert sort
				p = p -> next;
			q -> next = p -> next;
			p -> next = q;
			table[index] -> key++;
		}
	}
	int j = 0;
	KNode *r = nullptr;
	for (int i = 0; i < size; i++) {
		r = table[i] -> next;
		while (r != nullptr) {
			keys[j++] = r -> key;
			//std::cout << r -> key << " ";
			r = r -> next;
		}
	}
	//std::cout << std::endl;
}


// v3

void bucket(std::vector<int> &vec, int bucket) {
	std::vector<std::list<int>> ret;
	ret.resize(bucket);
	
	constexpr int size = 10;
	typedef std::vector<int>::size_type size_type;

	for (size_type i = 0; i < vec.size(); ++i) {
		int index = vec[i] / size; // function
		if (ret[index].empty()) {
			ret[index].push_back(vec[i]);
		} else {
			(ret[index]).push_back(vec[i]);
			ret[index].sort();
		}
	}
	int i = 0;	
	for (size_type j = 0; j < vec.size(); ++j) {
		if(!ret[j].empty()) {
			typedef std::list<int>::const_iterator iter;
			for (iter b = ret[j].begin(); b != ret[j].end(); ++b) {
				vec[i++] = *b;
			}
		}
	}
}

// test
#include <iterator>
#include <iostream>

void test_bucket() {
	std::cout <<  " test v1 " << std::endl;
	std::vector<int> vec1{1, 3, 5, 2, 9, 6, 4};
	bucket(vec1);

	for(const auto v : vec1)
		std::cout << v << " ";
	std::cout << std::endl;
	
	std::cout << " test v2 " << std::endl;
	int array[] = {6, 3, 1, 8, 9, 2, 5};
	bucket(array, 7);

	for (auto beg = std::begin(array); beg != std::end(array); ++beg) {
		std::cout << *beg << " ";
	}
	std::cout << std::endl;

	std::cout << " test v3 " << std::endl;
	std::vector<int> vec2{3, 1, 5, 12, 9, 4};
	bucket(vec2, 10);

	for(const auto v : vec2) {
		std::cout << v << " ";
	}
	std::cout << std::endl;

}

int main(int argc, char *argv[])
{
	using namespace std::chrono;
	auto beg = system_clock::now();
	
	test_bucket();

	auto end = system_clock::now();
	std::cout << "time: " << duration_cast<milliseconds> (end - beg).count()
	          << " ms."   << std::endl;
	
	return 0;
}
