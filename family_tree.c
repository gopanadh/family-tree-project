#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person {
char name[50];
int age;
struct Person *father;
struct Person *mother;
} Person;

Person* create_person(const char *name, int age){
    Person *p = malloc(sizeof(Person));
    if (p == NULL) {
        return NULL;
    }

    strcpy(p->name, name);
    p->age = age;
    p->father = NULL;
    p->mother = NULL;

    return p;
}


