// BOTTOM UP DYNAMIC PROGRAMMING METHOD

int fib_dp(int n) {
    int arr[31] = {0};
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

class Solution {
public:
    int fib(int n) {
        return fib_dp(n);
    }
};

