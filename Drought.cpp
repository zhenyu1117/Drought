#include <cstdio>
#include <cstring>

int N;
int H[1010], f[110][1010], sum[1010];
int MOD = 1000000007;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", H+i);
    }

    if (N%2 == 0) {
        memset(f, 0, sizeof(f));
        for (int j = 0; j <= H[0]; j++) {
            f[0][j] = 1;
        }

        for (int i = 1; i < N; i++) {
            sum[0] = f[i-1][0];
            for (int j = 1; j <= H[i]; j++) {
                sum[j] = (sum[j-1] + f[i-1][j]) % MOD;
            }
            for (int j = 0; j <= H[i]; j++) {
                f[i][j] = sum[H[i]-j];
            }
        }

        printf("%d\n", f[N-1][0]);
    } else {
        int ans = 0;
        while (true) {
            memset(f, 0, sizeof(f));
            for (int j = 0; j <= H[0]; j++) {
                f[0][j] = 1;
            }

            for (int i = 1; i < N; i++) {
                sum[0] = f[i-1][0];
                for (int j = 1; j <= H[i]; j++) {
                    sum[j] = (sum[j-1] + f[i-1][j]) % MOD;
                }
                for (int j = 0; j <= H[i]; j++) {
                    f[i][j] = sum[H[i]-j];
                }
            }

            ans = (ans + f[N-1][0]) % MOD;

            for (int i = 0; i < N; i++) {
                H[i]--;
                if (H[i] < 0) {
                    printf("%d\n", ans);
                    return 0;
                }
            }
        }
    }

    return 0;
}
