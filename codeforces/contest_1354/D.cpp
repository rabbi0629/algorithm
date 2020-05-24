#include<bits/stdc++.h>

int sum[1001000], n;

int ask(int x) {
    int ans = 0;
    for(int i = x; i > 0; i -= i&(-i)) {
        ans += sum[i];
    }
    return ans;
}

void add(int x, int d) {
    for(int i = x; i <= n; i+= i&(-i)) {
        sum[i] += d;
    }
}

int main()
{
    int q;
    std::cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        add(x, 1);
    }

    while(q--) {
        int x;
        scanf("%d", &x);
        if(x > 0) {
            add(x, 1);
        } else {
            int L = 0, R = n;
            while(L < R) {
                int mid = (L+R)/2;
                if(ask(mid) < -x) L=mid+1;
                else R=mid;
            }

            add(L, -1);
        }

    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(ask(i) > 0) {
            ans = i;
            break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
