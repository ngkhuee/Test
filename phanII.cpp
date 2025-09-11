#include <iostream>
#include <cmath>
using namespace std;

// Bai a
int f1a(int x) {
    if (x > 10)
        return 2 * x;
    else
        return -x;
}

// Bai b
int f1b(int x) {
    if (x > 10)
        return 2 * x;
    else if (x > 0)
        return -x;
    else
        return 2 * x;
}

// Bai c
int f2(int x) {
    if (x < 10)
        return 2 * x;
    else if (x < 2)
        return -x;
    else
        return 2 * x;
}

// Bai d
int f3(int x) {
    if (log(x * x * cos(x)) < 3 * x)
        return 2 * x;
    else
        return 2 * x;
}

// Bai e
int findMax(int num1, int num2, int num3) {
    int max = 0;
    if ((num1 > num2) && (num1 > num3))
        max = num1;

    if ((num2 > num1) && (num2 > num3))
        max = num2;

    if ((num3 > num1) && (num3 > num2))
        max = num3;
    
    return max;
}

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    cout << f1a(x) << endl;
    cout << f1b(x) << endl;
    cout << f2(x) << endl;
    cout << f3(x) << endl;
    cout << findMax(a, b, c) << endl;
    return 0;
}