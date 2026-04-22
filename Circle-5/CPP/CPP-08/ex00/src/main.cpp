#include "../inc/easyfind.hpp"
#include <vector>
#include <list>
#include <cstdlib>

int main() {
    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
        lst.push_back(i);
    }

    try {
        std::cout << "Vector: ";
        print(vec);
        std::vector<int>::iterator itVec = easyfind(vec, 5);
        std::cout << "Found in vector: " << *itVec << std::endl;

        std::cout << "List: ";
        print(lst);
        std::list<int>::iterator itList = easyfind(lst, 5);
        std::cout << "Found in list: " << *itList << std::endl;

        // Esto provocará una excepción
        itVec = easyfind(vec, 20);
    }
    catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
