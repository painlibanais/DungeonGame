#include <vector>

class Item;

template<typename T>
const int find(std::vector<T *> vec, T *element) {
    for (int i = 0; i < vec.size(); i++) {
        if (*(vec[i]) == *element)
            return i;
    }
    return -1;
}

template<typename T>
int remove(std::vector<T *> *vec, int id) {
    for (int i = id; i < (vec->size()) - 1; i++) {
        vec->at(i) = vec->at(i + 1);
    }
    vec->pop_back();
    return 0;
}
