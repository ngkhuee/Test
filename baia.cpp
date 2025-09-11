#include <iostream>
#include <cmath>
using namespace std;

// Bai a
int f1(int x) {
    if (x > 10)
        return 2 * x;
    else
        return -x;
}

int main()
{
    int x;
    cin >> x;
    cout << f1(x) << endl;
    return 0;
}