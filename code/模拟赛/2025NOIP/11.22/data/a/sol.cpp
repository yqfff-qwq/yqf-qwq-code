#include <bits/stdc++.h>
using namespace std;
const string path = "data";
int main() {
    for (int i = 1; i <= 10; i ++) {
		string name = path + to_string(i);
        string qwq = string("std.exe <") + (name + ".in") + " > " + (name + ".out");
        system(qwq.c_str());
    }
    return 0;
}
