
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

void BInsertSort(SqList &L) {

	for (int i = 2; i <= L.length; ++i) {
		
		L.r[0] = L.r[i];
		int low = 1, high = i -1;
		while (low <= high) {
			int m = (low + high) / 2;
			if (L.r[0].key < L.r[m].key)
				high = m -1;
			else
				low = m + 1;
		}
		for (int j = i -1; j >= high + 1; --j) 
			L.r[j + 1] = L.r[j];
		L.r[high + 1] = L.r[0];
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
	BInsertSort(L);
	Print(L);
}

int main(int argc, char *argv[]) {

	test();

	return 0;
}
