#include <cstdio>
#include <cstring>

const int MAXL = 21;
char str[MAXL];

int main() {
    scanf("%s", str);
    bool result = true;
    int len = strlen(str);
    if (!((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z') || str[0] == '_')) {
        result = false;
    }
    for (int i = 1; i < len; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_')) {
            result = false;
            break;
        }
    }
    printf(result ? "YES": "NO");
    return 0;
}