#include<iostream>
#include<vector>
#include<list>
#include<array>


using namespace std;

template <typename printType>
void printValue(printType& type) {
    for (auto& x : type)
        cout << x << ' ';
    cout << endl;
}

template <typename myType>
void increaseValue(myType& type, int num) {
    for (auto& x : type)
        x += num;
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2) {
    while (f1 != e1) {
        *f2++ = *f1++;
    }
    return f2;
}

int main() {

    array<int,10> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> lst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    array<int,10> copyarr = arr;
    vector<int> copyvec = vec;
    list<int> copylst = lst;

    increaseValue(copyarr, 2);
    increaseValue(copyvec, 3);
    increaseValue(copylst, 5);

    cout << "copy containers after increase: \n";
    cout << "array: ";
    printValue(copyarr);
    cout << "vector: ";
    printValue(copyvec);
    cout << "list: ";
    printValue(copylst);
    cout << endl;

    my_copy(copyarr.begin(), copyarr.end(), copyvec.begin());
    my_copy(copylst.begin(), copylst.end(), copyarr.begin());

    cout << "copy containers after copy function: \n";
    cout << "array: ";
    printValue(copyarr);
    cout << "vector: ";
    printValue(copyvec);
    cout << "list: ";
    printValue(copylst);
    cout << endl;

    cout << "search 3 in copy vector\n";
    auto findresult = find(copyvec.begin(), copyvec.end(), 3);
    if (findresult != copyvec.end())
        cout << "found 3 at " << distance(copyvec.begin(), findresult) << endl;
    else
        cout << "not found\n";

    cout << "search 27 in copy list\n";
    auto findresult2 = find(copylst.begin(), copylst.end(), 27);
    if (findresult2 != copylst.end())
        cout << "found 27 at " << distance(copylst.begin(), findresult2) << endl;
    else
        cout << "not found\n";


    return 0;
}
