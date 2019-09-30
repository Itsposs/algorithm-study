#include <random>
#include <chrono>
#include <iostream>

using ElemType = int;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

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

}
void SelectSort(LinkList &L) {
    if (！（L && L -> next）)
        return;
    LinkList p, q;
    for (p = L -> next; p; p = p -> next) {
        int min = p -> data;
        LinkList s = p;
        for (q = p -> next; q; q = q -> next) {
            if (min > q -> data) {
                min = q -> data;
                s = q;
            }
        }
        if (s != p) {
            std::swap(s -> data, p -> data);
        }
    }
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

void test() {
    LinkList p;
    create(p, 10);
    print(p);
    std::cout << "create end." << std::endl;
    SelectSort(p); // error
    std::cout << "sort end." << std::endl;
    print(p);
    destroy(p);
}

int main() {
    using namespace std::chrono;
    auto beg = system_clock::now();

    test();

    auto end = system_clock::now();
    std::cout << "time: " << duration_cast<milliseconds> (end - beg).count() << "ms." << std::endl;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
