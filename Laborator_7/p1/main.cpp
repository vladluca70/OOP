#include "Vector.h"

int main() {
    Vector<int> v;

    // index, element
    v.insert(0, 10);
    v.insert(1, 5);
    v.insert(2, 20);

    Vector<int> w = v;

    // index
    v.remove(0);
    v.sort(compare_ints);
    printf("%d\n", w[0]);

    v.print();
}
