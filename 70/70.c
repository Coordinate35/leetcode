int climbStairs(int n) {
    int last_two, last_one, current;
    int i;
    last_two = 1;
    last_one = 2;
    if (0 == n) {
        return 0;
    }
    if (1 == n) {
        return 1;
    }    
    if (2 == n) {
        return 2;
    }
    for (i = 3; i <= n; i++) {
        current = last_one + last_two;
        last_two = last_one;
        last_one = current;
    } 
    return current;
}