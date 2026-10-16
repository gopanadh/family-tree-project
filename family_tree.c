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


void read_person_info(const char *role, char *name_out, int *age_out) {
    printf("Enter %s's name: ", role);
    fgets(name_out, 50, stdin);

    for (int i = 0; name_out[i] != '\0'; i++) {
      if (name_out[i] == '\n') {
            name_out[i] = '\0';
            break;
        }
    }

    printf("Enter %s's age: ", role);
    scanf("%d", age_out);
    getchar();
}

void link_parents(Person *child, Person *father,Person *mother){
    child -> father = father;
    child -> mother = mother;
}


void print_family_relationships(const Person *me) {
    printf("\n=== FAMILY TREE RELATIONSHIPS ===\n");

    printf("\n1. YOURSELF:\n");
    printf("   - Name: %s | Age: %d\n", me->name, me->age);

    printf("\n2. PARENTS:\n");
    printf("   - Father: %s | Age: %d\n",
           me->father->name, me->father->age);
    printf("   - Mother: %s | Age: %d\n",
           me->mother->name, me->mother->age);

    printf("\n3. PATERNAL GRANDPARENTS (via Father's Pointers):\n");
    printf("   - Grandfather: %s | Age: %d\n",
           me->father->father->name, me->father->father->age);
    printf("   - Grandmother: %s | Age: %d\n",
           me->father->mother->name, me->father->mother->age);

    printf("\n4. MATERNAL GRANDPARENTS (via Mother's Pointers):\n");
    printf("   - Grandfather: %s | Age: %d\n",
           me->mother->father->name, me->mother->father->age);
    printf("   - Grandmother: %s | Age: %d\n",
           me->mother->mother->name, me->mother->mother->age);
}


int main(void){
    char name[7][50];
    int age[7];
    Person *people[7];

    read_person_info("Paternal Grandfather", name[0], &age[0]);
    read_person_info("Paternal Grandmother", name[1], &age[1]);
    read_person_info("Maternal Grandfather", name[2], &age[2]);
    read_person_info("Maternal Grandmother", name[3], &age[3]);
    read_person_info("Father", name[4], &age[4]);
    read_person_info("Mother", name[5], &age[5]);
    read_person_info("Yourself", name[6], &age[6]);

    people[0] = create_person(name[0], age[0]);
    people[1] = create_person(name[1], age[1]);
    people[2] = create_person(name[2], age[2]);
    people[3] = create_person(name[3], age[3]);
    people[4] = create_person(name[4], age[4]);
    people[5] = create_person(name[5], age[5]);
    people[6] = create_person(name[6], age[6]);

    link_parents(people[4], people[0], people[1]);
    link_parents(people[5], people[2], people[3]);
    link_parents(people[6], people[4], people[5]);

    print_family_relationships(people[6]);

    return 0;
}
