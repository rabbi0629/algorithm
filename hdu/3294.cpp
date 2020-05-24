#include<bits/stdc++.h>

const int maxn = 200200;
char str[maxn*2];
int mp[2*maxn];
char s1[10],s2[maxn];
char real_string[maxn];

int main()
{
    while(~scanf("%s%s", s1,s2)) {
        int delta = s1[0] - 'a';

        int strLength = strlen(s2);
        for(int i = 0; i < strLength; i++) {
                real_string[i] = s2[i]-'a'>=delta?s2[i]-delta:s2[i]+26-delta;
        }

        int len = 0;
        str[len++] = '$';
        str[len++] ='#';
        for(int i = 0; i < strLength; i++) {
            str[len++] = real_string[i];
            str[len++] = '#';
        }

        mp[len] = '\0';
        int mx = 0, id = 0, maxLen = 1;
        int L = 0, R = 0;
        for(int i = 0; i < len; i++) {
            mp[i] = mx > i ? std::min(mp[2*id-i], mx-i):1;
            while(str[i-mp[i]] == str[i+mp[i]]){
                mp[i]++;
            }

            if(mp[i] > mx) {
                mx = i+mp[i];
                id = i;
            }

            if(maxLen < mp[i]-1) {
                maxLen = mp[i]-1;
                L = (i-mp[i])>>1;
                R = (i+mp[i]-4)>>1;
            }
        }

        if(maxLen < 2) {
            std::cout << "No solution!" << std::endl;
            continue;
        }

        std::cout << L << " " << R << std::endl;
        std::string ans = "";
        for(int i = L; i <= R; i++) {
            ans += real_string[i];
        }
        std::cout << ans << std::endl;
        std::cout << str << std::endl;
        
    }
    return 0;
}
