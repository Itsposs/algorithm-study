
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

using ElemType = int;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

#include <random>  // random


void create(LinkList &L, int count) {
	
	L = new LNode;  // init
	L -> next = nullptr;

	LinkList r = L;   // pointer of tail 
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);

	for (int i = 0; i < count; ++i) {
		int key = dis(gen);
		//std::cout << key << " ";
		LinkList p = new LNode;
		p -> data = key;
		p -> next = nullptr;
		r -> next = p;
		r = p;
	}
	//return head;
}

#include <iostream>

void print(LinkList &L) {

	if (!L)
		return;
	LinkList p = L -> next;
	while (p) {
		std::cout << p -> data << " ";
		p = p -> next;
	}
	std::cout << std::endl;
}


void destroy(LinkList &L) {
	if(!L)
		return;
	LinkList r;
	LinkList p = L;
	while (p) {
		r = p -> next;
		free(p);
		p = r;
	}
}

void insert(LinkList &L) {
	if (!L)
		return nullptr;
	LinkList p = head -> next, q;
	LinkList r = p -> next;
	p -> next = nullptr;
	p = r;
	/*         x   p  
	 * head	   p   r
	 * [ ] -> [ ] [ ]->[ ]->[ ]->[ ]
	 *
	 */
	while (p) {
		/*  q           p      r
		 * [ ] -> [ ]  [ ] -> [ ]
		 *
		 */
		r = p -> next;
		q = L;
		while (q -> next != nullptr && q -> next -> data < p -> data)
			q = q -> next;
		p -> next = q -> next;
		q -> next = p;
		p = r;
	}
	//return head;
}

void test_list() {
	LinkList p;
	create(p, 10);
	print(p);
	std::cout << "create end." << std::endl;
	insert(p); // error
	std::cout << "insert end." << std::endl;
	print(p);
	destroy(p);
}

int main(int argc, char *argv[]) {
	using namespace std::chrono;
	auto beg = system_clock::now();
	
	test_list();
	
	auto end = system_clock::now();
	std::cout << "time: " << duration_cast<milliseconds> (end - beg).count()
			  << " ms."   << std::endl;
	return 0;
}
