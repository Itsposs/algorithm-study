
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

typedef struct LNode {
	int val;
	struct LNode *next;
} LNode;

#include <random>  // random


LNode * create(LNode *head, int count) {
	
	head = new LNode;  // init
	head -> next = nullptr;

	LNode *r = head;   // pointer of tail 
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);

	for (int i = 0; i < count; ++i) {
		int key = dis(gen);
		//std::cout << key << " ";
		LNode *p = new LNode;
		p -> val = key;
		p -> next = nullptr;
		r -> next = p;
		r = p;
	}
	return head;
}

#include <iostream>

void print(LNode *head) {

	if (!head)
		return;
	LNode *p = head -> next;
	while (p) {
		std::cout << p -> val << " ";
		p = p -> next;
	}
	std::cout << std::endl;
}


void destroy(LNode *head) {
	if(!head)
		return;
	LNode *r;
	LNode *p = head;
	while (p) {
		r = p -> next;
		free(p);
		p = r;
	}
}

LNode *insert(LNode *head) {
	if (!head)
		return nullptr;
	LNode *p = head -> next, *q;
	LNode *r = p -> next;
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
		q = head;
		while (q -> next != nullptr && q -> next -> val < p -> val)
			q = q -> next;
		p -> next = q -> next;
		q -> next = p;
		p = r;
	}
	return head;
}

void test_list() {
	LNode *p;
	LNode *r = create(p, 10);
	print(r);
	std::cout << "create end." << std::endl;
	LNode *q = insert(r); // error
	std::cout << "insert end." << std::endl;
	print(q);
	destroy(r);
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
