#include <cstdio>
#include <cstring>

struct Student {
    int id;
    char name[15];
    Student(int _id, char _name[]) {
        id = _id;
        strcpy(name, _name);
    }
};

int main() {
    int id;
    char name[15];
    scanf("%d\n%s", &id, name);
    Student student = Student(id, name);
    printf("%d\n%s", student.id, student.name);
    return 0;
}