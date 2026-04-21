#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    auto clamp01 = [](int x){
        if (x < 0) return 0;
        if (x > 100) return 100;
        return x;
    };

    for (int i = 0; i < m; ++i) {
        for (int sr = 0; sr < 3; ++sr) {
            for (int j = 0; j < n; ++j) {
                for (int sc = 0; sc < 3; ++sc) {
                    int val = 0;
                    if (sr == 1 && sc == 1) {
                        val = a[i][j];
                    } else if ((sr == 1 && sc != 1) || (sc == 1 && sr != 1)) {
                        int A = a[i][j];
                        bool hasB = false;
                        int B = 0;
                        if (sr == 1 && sc == 0) { // left
                            if (j - 1 >= 0) { hasB = true; B = a[i][j-1]; }
                        } else if (sr == 1 && sc == 2) { // right
                            if (j + 1 < n) { hasB = true; B = a[i][j+1]; }
                        } else if (sc == 1 && sr == 0) { // up
                            if (i - 1 >= 0) { hasB = true; B = a[i-1][j]; }
                        } else if (sc == 1 && sr == 2) { // down
                            if (i + 1 < m) { hasB = true; B = a[i+1][j]; }
                        }
                        if (hasB) {
                            val = (4*A + B) / 5; // floor(0.8*A + 0.2*B)
                        } else {
                            val = A; // only A exists
                        }
                    } else {
                        // Corner: no A; B is only own center (distance 2)
                        val = a[i][j];
                    }
                    val = clamp01(val);
                    cout << val << ' ';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
