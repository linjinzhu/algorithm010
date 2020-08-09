#include <iostream>
using namespace std;

/**
 * 求阶乘
 */
double jiecheng(int64_t n) {
    double ans = 1;
    for (int64_t i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

// 求幂
float pow(float x, int64_t y) {
    // 非法底数
    if (x == 0) {
        return 0;
    }
    
    // 指数为0
    if (y == 0) {
        return 1;
    }


    // 计算每一项值
    float item = x;
    int size = y;
    if (y < 0) {
        item = 1.0 / x;
        size = -1 * y;
    }
    
    // 求指数
    float ans = item;
    for (size_t i = 2; i <= size; i++) {
        ans *= item;
    }
    
    return ans;
}

/**
 * 求f
*/
double f(int64_t n, int64_t k, float p) {
    // C(n, k)组合数 = n!/(k!(n-k)!)
    // f (n, k, p) = C(n, k)p^k(1-p)^(n-k)
    double c = jiecheng(n) / (jiecheng(k) * jiecheng(n - k));
    std::cout << "c:" << c << std::endl;
    // p的k次方
    double a = pow(p, k);
    // (1-p)的(n-k)次方
    double b = pow((1-p), (n-k));
    return c*a*b;
}

void test_pow() {
    float ans1 = pow(0.1, 0);
    std::cout << "pow(0.1, 0):" << ans1 << std::endl;
    float ans2 = pow(0.1, -2);
    std::cout << "pow(0.1, -2):" << ans2 << std::endl;
    float ans3 = pow(0.1, 2);
    std::cout << "pow(0.1, 2):" << ans3 << std::endl;
    std::cout << "pow(1, 10):" << pow(1, 10) << std::endl;
    std::cout << "pow(0, 10):" << pow(0, 10) << std::endl;
}

void test_jiecheng() {
    int ans1 = jiecheng(10);
    int ans2 = jiecheng(0);
    std::cout << "jiecheng(0):" << ans2 << std::endl;
    std::cout << "jiecheng(1):" << jiecheng(1) << std::endl;
    std::cout << "jiecheng(2):" << jiecheng(2) << std::endl;
    // 5! = 5 * 4 * 3 * 2 * 1
    std::cout << "jiecheng(5):" << jiecheng(5) << std::endl;
    std::cout << "jiecheng(10):" << ans1 << std::endl;
    std::cout << "jiecheng(100000):" << jiecheng(1000000) << std::endl;
}

void test_f() {
    int64_t n = 10;
    int64_t k = 0;
    float p = 0.500;
    float ans = f(n, k, p);
    std::cout << "p=0.5:" << ans << std::endl;

    p = 0;
    ans = f(n, k, p);
    std::cout << "p=0:" << ans << std::endl;

    p = 1;
    ans = f(n, k, p);
    std::cout << "p=1:" << ans << std::endl;

    k = 10;
    p = 0.6;
    ans = f(n, k, p);
    std::cout << "p=0.6,k=10:" << ans << std::endl;
    
    n = 1;
    k = 10;
    p = 0.6;
    ans = f(n, k, p);
    std::cout << "n=1,p=0.6,k=1:" << ans << std::endl;

}

int main () {
    test_jiecheng();
    // test_pow();
    // test_f();

    // 输入n,k,p
    int64_t n = 10;
    int64_t k = 0;
    float p = 0.500;

    std::cin >> n >> k >> p;
    float ans = f(n, k, p);
    std::cout << ans << std::endl;

    return 0;
}