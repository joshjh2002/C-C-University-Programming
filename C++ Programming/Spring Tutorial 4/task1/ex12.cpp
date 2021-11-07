#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Test
{
public:
    static int count;
    static vector<T> vals;

    Test()
    {
        vals.push_back(count);
        count++;
    }
};

// need to initialize these variables, try to remove it to see the error!
template <class T>
vector<T> Test<T>::vals = {37, 20};

template <class T>
int Test<T>::count = 0;

int main()
{
    Test<int> a;
    Test<int> b;
    Test<double> c;
    cout << Test<int>::count << endl;
    cout << Test<double>::count << endl;

    cout << "Let's iterate through our values of Test<int>::vals using the new for each" << endl;
    for (auto &x : Test<int>::vals)
    {
        cout << x << endl;
    }

    cout << "using iterators and a reference" << endl;
    vector<int> &vec = Test<int>::vals;
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}