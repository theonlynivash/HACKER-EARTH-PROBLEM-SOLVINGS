#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char string[100005];
        scanf("%s", string);

        int freq[26] = {0};

        // Count frequencies
        for (int i = 0; i < n; i++) {
            freq[string[i] - 'a']++;
        }

        int c = -1;

        // Count odd frequencies
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                c++;
            }
        }

        if (c < 0) {
            c = 0;
        }

        printf("%d\n", c);
    }

    return 0;
}