
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


void InsertSort(SqList &L) { // 从后向前

	for (int i = 2; i <= L.length; ++i) {	
		/*
		 * 0 1 2 3 4 5  6  7
		 *   8 6 9 7 12 36 24
		 */
		if (L.r[i - 1].key > L.r[i].key) { // 将r[i]插入到有序子表
			L.r[0].key = L.r[i].key; // 将待插入的记录暂存到监视哨中
			L.r[i].key = L.r[i - 1].key;
			/*
			 * 0 1 2 3 4 5  6  7
			 * 6   8 9 7 12 36 24
			 */
			int j = 0;
			for (j = i - 2; L.r[0].key < L.r[j].key; --j) {
				L.r[j + 1] = L.r[j];
			}
			L.r[j + 1] = L.r[0];
		} // if
	} // for
}

#include <iostream>

void Print(SqList L) {
	
	for (int i = 1; i <= L.length; ++i) {
		std::cout << L.r[i].key << " ";
	}
	std::cout << std::endl;
}

void test_insert() {
	SqList L;
	CreateSqList(L);
	std::cout << "create end." << std::endl;
	//Print(L);
	//InsertSort(L);
	//Print(L);
}

#include <chrono> // now()

int main(int argc, char *argv[]) {
	using namespace std::chrono;
	auto beg = system_clock::now();
	
	test_insert();

	auto end = system_clock::now();
	std::cout << "time: " << duration_cast<milliseconds> (end - beg).count()
	          << " ms."   << std::endl;

	return 0;
}
