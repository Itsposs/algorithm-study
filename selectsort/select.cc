
// c++11
// const int MAXSIZE = 20;
// constexpr int MAXSIZE = 20;
#define MAXSIZE 20

// using KeyType = int;
typedef int KeyType;
typedef int InfoType;

typedef struct {
	KeyType key;
	InfoType otherinfo;
} RedType;

typedef struct {
	RedType r[MAXSIZE + 1];
	int length;
} SqList;

#include <random> // random
// debug
//#include <iostream>
void CreateSqList(SqList &L) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);

	for (int i = 1; i <= MAXSIZE; ++i) {
		int key = dis(gen);
		//std::cout << key << " ";
		L.r[i].key = key;
		L.length++;
	}
	//std::cout << std::endl;
}

# include <algorithm>  // swap()

void Select(SqList &L) {
	
	for (int i = 1; i <= L.length; ++i) {

		int k = i;
		for (int j = i + 1; j <= L.length; ++j) {
			if (L.r[j].key < L.r[k].key)
				k = j;
		}
		if (k != i) {
			std::swap(L.r[i], L.r[k]);
		}
	}
}

#include <iostream>

void Print(SqList L) {
	
	for (int i = 1; i <= L.length; ++i) {
		std::cout << L.r[i].key << " ";
	}
	std::cout << std::endl;
}

void test() {
	SqList L;
	CreateSqList(L);
	Print(L);
	Select(L);
	Print(L);
}

int main(int argc, char *argv[]) {
	
	test();

	return 0;
}
