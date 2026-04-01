#include <stdio.h>

#define MAXN 100005

int arr[MAXN];
int prefix0[MAXN], prefix1[MAXN];

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        for(int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }

        // prefix counts
        prefix0[0] = prefix1[0] = 0;

        for(int i = 1; i <= n; i++) {
            prefix0[i] = prefix0[i-1] + (arr[i] == 0);
            prefix1[i] = prefix1[i-1] + (arr[i] == 1);
        }

        int q;
        scanf("%d", &q);

        while(q--) {
            int L, R;
            scanf("%d %d", &L, &R);

            int len = R - L + 1;

            long long total = (long long)len * (len - 1) / 2;

            int count0 = prefix0[R] - prefix0[L-1];
            int count1 = prefix1[R] - prefix1[L-1];

            long long invalid = 0;

            // (0,0)
            invalid += (long long)count0 * (count0 - 1) / 2;

            // (0,1)
            invalid += (long long)count0 * count1;

            printf("%lld\n", total - invalid);
        }
    }

    return 0;
}