
// III. PRATICE

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) {
        return -1;
    }

    if (a == 0 && b == 0) {
        return 0;
    }

    if (a == 0) {
        double y = -c / b;
        if (y < 0)
            return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }

    double delta = b * b - 4 * a * c;
    if (delta < 0)
        return 0;

    double y1 = (-b + sqrt(delta)) / (2 * a);
    double y2 = (-b - sqrt(delta)) / (2 * a);

    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && y2 != y1) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }

    return count;
}

// Hàm kiểm tra Test Case tự động
struct TestCase {
    double a, b, c;
    int expectedCount;  // Số nghiệm expec: 0,2,4 và -1 nếu vô nghiệm
    double expected[4]; // Tối đa 4 nghiệm
};

// Hàm so sánh nghiệm thực tế và mong đợi (x, n: nghiệm và số nghiệm thực tế)
    // 1. Kiểm tra số nghiệm
    // 2. Sắp xếp thứ tự thực tế và mong đợi giống nhau
    // 3. So sánh số thực với ngưỡng sai số cho phép (0.000001 = 1e-6)
bool checkSolutions(double x[], int n, double expected[], int m) {  
    if (n != m) return false;
    sort(x, x+n);
    sort(expected, expected+m);
    for (int i = 0; i < n; i++) {
        if (fabs(x[i] - expected[i]) > 1e-6) return false;
    }
    return true;
}

// Hàm chạy test
void checks() {
    TestCase tests[] = {
        {0,0,0, -1, {}},            // Infinite solutions
        {0,0,5, 0, {}},             // No solution
        {0,2,-8, 2, {2,-2}},        // 2 solutions
        {0,2,8, 0, {}},             // No solution
        {1,2,5, 0, {}},             // No solution
        {1,2,1, 0, {}},             // No solution
        {1,-5,4, 4, {2,-2,1,-1}},   // 4 solutions
        {1,-2,1, 2, {1,-1}}         // 2 solutions
    };
    int total = sizeof(tests)/sizeof(TestCase); // Lấy số lượng test case trong mảng

    for (int i = 0; i < total; i++) {
        double x[4];
        int n = solveQuartic(tests[i].a, tests[i].b, tests[i].c, x);    // Lấy nghiệm thực

        bool ktra;
        if (tests[i].expectedCount == -1) {     // TH vô số nghiệm
            ktra = (n == -1);
        } else {                                // Các TH còn lại ktra bằng hàm ss trên
            ktra = (n == tests[i].expectedCount) &&
                 checkSolutions(x, n, tests[i].expected, tests[i].expectedCount);
        }

        cout << "Test " << i+1 << ": " << (ktra ? "PASSED" : "FAILED") << endl;
    }
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    
    double x[4];
    int n = solveQuartic(a, b, c, x);

    if (n == -1) {
        cout << " Infinite solutions." << endl;
    } else if (n == 0) {
        cout << "No solution." << endl;
    } else {
        cout << " The equation has " << n << " real solution(s): ";
        for (int i = 0; i < n; i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
    }

    // Kiểm TestCase
    checks();
    return 0;
}