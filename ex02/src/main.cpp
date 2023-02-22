#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./include/A.hpp"
#include "./include/B.hpp"
#include "./include/C.hpp"
#include "./include/Base.hpp"

Base* generate() {
    srand(time(0));
    int r = rand() % 3;
    if (r == 0) {
        return new A();
    } else if (r == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != nullptr) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != nullptr) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        if (dynamic_cast<A*>(&p) != nullptr) {
            std::cout << "A" << std::endl;
        } else if (dynamic_cast<B*>(&p) != nullptr) {
            std::cout << "B" << std::endl;
        } else if (dynamic_cast<C*>(&p) != nullptr) {
            std::cout << "C" << std::endl;
        }
    } catch (std::bad_cast& ex) {
        std::cerr << "dynamic_cast failed: " << ex.what() << std::endl;
    }
}


int main() {
    Base* obj = generate();
    identify(obj);
    identify(*obj);
    delete obj;
    return 0;
}