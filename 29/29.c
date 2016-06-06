// int divide(int dividend, int divisor) {
//     long long result, abs_dividend, abs_divisor, test_bit, power;
//     int flag, dividend_flag, divisor_flag, bit;
//     if (0 == divisor) {
//         return 2147483647;
//     }
//     result = 0;
//     dividend_flag = dividend > 0 ? 1 : -1;
//     divisor_flag = divisor > 0 ? 1 : -1;
//     flag = dividend_flag * divisor_flag;
//     abs_dividend = abs(dividend);
//     abs_divisor = abs(divisor);
//     test_bit = abs_divisor;
//     while (abs_divisor <= abs_dividend) {
//         power = 1;
//         test_bit = abs_divisor;
//         while (test_bit << 1 < abs_dividend) {
//             test_bit <<= 1;
//             power <<= 1;
//         }
//         result += power;
//         abs_dividend -= test_bit; 
//     }
//     if (((-1 == flag) && (result > 2147483648)) || ((1 == flag) && (result > 2147483647))) {
//         return 2147483647;
//     } else {
//         return flag * result;
//     }
// }

int divide(int dividend, int divisor) {
    long long a = dividend >= 0 ? dividend : -(long long)dividend;
    long long b = divisor >= 0 ? divisor : -(long long)divisor;
    if ((-2147483648 == dividend) && (-1 == divisor)) {
        return 2147483647;
    }
    if ((-2147483648 == divisor) && (-2147483648 != dividend)) {
        return 0;
    }
    
    long long result = 0;
    while (a >= b) {
        long long c = b;
        for (int i = 0; a >= c; ++i, c <<= 1) {
            a -= c;
            result += 1 << i;
        }
    }
    return ((dividend ^ divisor) >> 31) ? (-result) : (result);
}

