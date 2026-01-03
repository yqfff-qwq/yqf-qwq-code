#include <bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100
using namespace std;
int n, a[N + 5];
char s[N + 5];
I void dfs(CI x, CI v) { //x记录当前位置，v记录左括号个数减右括号个数
    if (x > n)
        return (void)(!v &&
                      (puts(s + 1), exit(0), 0)); //如果x大于n且v恰好为0，则输出答案，退出程序

    if (s[x]) { //如果已经确定
        if (s[x]^')')
            return dfs(x + 1, v + 1); //如果是左括号，搜索下一位

        if (v)
            return dfs(x + 1, v - 1);

        return;//如果是右括号且v大于0，搜索下一位
    }

    if (a[x] > x || s[a[x]]^'(')
        s[x] = '(', s[a[x]] = ')', dfs(x + 1, v + 1), s[x] = s[a[x]] = '\0'; //选左括号

    if (v)
        s[x] = ')', dfs(x + 1, v - 1), s[x] = '\0'; //选右括号
}
int main() {
    RI i;

    for (scanf("%d", &n), i = 1; i <= n; ++i)
        scanf("%d", a + i); //读入

    return dfs(1, 0), 0;
}