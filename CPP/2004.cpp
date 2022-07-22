#include <iostream>
#include <cmath>
using namespace std;

int get_2(int n) {
    // n!에 2가 몇 개 존재하는지를 return
    // 2의 배수, 4의 배수, 16의 배수, ..., 2^k의 배수의 수를 모두 더하면
    // 된다. 단, k는 2^k <= n을 만족시키는 최대의 정수이다.
    int count = 0;
    int k = 1;
    int power;

    while (pow(2, k) <= n) {
        power = pow(2, k);
        count += n / power;
        k++;
    }

    return count;
}

int get_5(int n) {
    // n!에 5가 몇 개 존재하는지를 return
    // 5의 배수, 25의 배수, 125의 배수, ..., 5^k의 배수의 수를 모두 더하면
    // 된다. 단, k는 5^k <= n을 만족시키는 최대의 정수이다.
    int count = 0;
    int k = 1;
    int power;

    while (pow(5, k) <= n) {
        power = pow(5, k);
        count += n / power;
        k++;
    }

    return count;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num1, num2;
    cin >> num1 >> num2;

    // 분자, 분모가 각각 2, 5를 몇 개 포함하는지가 중요하다.
    int numerator_2 = 0;
    int numerator_5 = 0;
    int denominator_2 = 0;
    int denominator_5 = 0;
    int total_2 = 0;
    int total_5 = 0;

    // 분자는 n!, 분모는 (n-r)!r!이다.
    numerator_2 = get_2(num1);
    numerator_5 = get_5(num1);
    denominator_2 = get_2(num1 - num2) + get_2(num2);
    denominator_5 = get_5(num1 - num2) + get_5(num2);


    // 총 2와 5의 수를 구해서 둘 중 작은 수로 맞춰주면 된다.
    // 2^5 * 5^8이면 10이 8개가 아닌 5개 있기 때문이다.
    total_2 = numerator_2 - denominator_2;
    total_5 = numerator_5 - denominator_5;

    cout << (total_2 < total_5 ? total_2 : total_5) << "\n";

    return 0;
}