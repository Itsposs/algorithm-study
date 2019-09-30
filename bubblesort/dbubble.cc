#include <iostream>

#define MAXSIZE 20

// c++11
using ElemType = int;
using InfoType = int;

typedef struct LNode {
    ElemType key;
    InfoType otherinfo;
}RedType;

typedef struct {
    RedType r[MAXSIZE + 1];
    int length;
}SqList;

#include <random> // random

void CreateSqList(SqList &L) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 1; i <= MAXSIZE; ++i) {
        int key = dis(gen);
        std::cout << key << " ";
        std::cout << std::endl;
        L.r[i].key = key;
        L.length++;  // L.length error
    }
    std::cout << "length:" << L.length << std::endl;
}


void Print(const SqList &L) {
    //std::cout << "length:" << L.length << std::endl;
    for (int i = 1; i <= L.length; ++i) {
        std::cout << L.r[i].key << " ";
    }
    std::cout << std::endl;
}


void BubbleSort(SqList L) {
    bool sorted;
    int low = 0, high = L.length - 1;
    while (low < high) {
        sorted = false;
        for (int i = low; i < high; ++i) {
            if (L.r[i].key > L.r[i + 1].key) {
                sorted = true;
                std::swap(L.r[i].key, L.r[i + 1].key);
            }
        }
        if (!sorted)
            break;
        high--;
        for (int j = high; j > low; ++j) {
            if (L.r[j - 1].key > L.r[j].key) {
                std::swap(L.r[j - 1].key, L.r[j].key);
            }
        }
        low++;
    }
}

void test() {
    SqList L;
    CreateSqList(L);
    std::cout << "length:" << L.length << std::endl;
    //Print(L);
    //BubbleSort(L);
    //Print(L);
}

#include <chrono>

int main() {
    using namespace std::chrono;
    auto beg = system_clock::now();

    test();

    auto end = system_clock::now();
    std::cout << "time: " << duration_cast<milliseconds> (end - beg).count() << " ms." << std::endl;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
