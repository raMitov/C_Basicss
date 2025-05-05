#include <stdio.h>

union Pers{
    int age;
    float height;
};
struct Person{
    int age;
    float height;
};

void persInit(union Pers *pers, int data, float data2){
    pers->age = data;
    pers->height = data2;
}
void PersonInit(struct Person *pers, int data, float data2){
    pers->age = data;
    pers->height = data2;
}
void printPer(union Pers *pers){
    printf("%d, %f -> %zu\n", pers->age, pers->height, sizeof(*pers));
}

void printPerson(struct Person *pers){
    printf("%d, %f -> %zu\n", pers->age, pers->height, sizeof(*pers));
}

int main(){
    union Pers pers;
    struct Person bigPers;
    persInit(&pers, 12, 1.80);
    PersonInit(&bigPers, 13, 1.90);
    printPer(&pers);
    printPerson(&bigPers);

}