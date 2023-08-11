#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int day;
    int month;
};

int compareBirthdays(const void *a, const void *b) {
    const struct Person *personA = (const struct Person *)a;
    const struct Person *personB = (const struct Person *)b;

    if (personA->month != personB->month) {
        return personA->month - personB->month;
    } else {
        return personA->day - personB->day;
    }
}

int main() {
    int numPeople;

    printf("Enter the number of people: ");
    if (scanf("%d", &numPeople) != 1 || numPeople <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    struct Person people[numPeople];

    for (int i = 0; i < numPeople; i++) {
        printf("Enter the name of person %d: ", i + 1);
        scanf("%s", people[i].name);

        printf("Enter the birth month of %s (1-12): ", people[i].name);
        scanf("%d", &people[i].month);

        if (people[i].month < 1 || people[i].month > 12) {
            printf("Invalid month.\n");
            return 1;
        }

        printf("Enter the birth day of %s: ", people[i].name);
        scanf("
        if (people[i].day < 1 || people[i].day > 31) {
            pri%d", &people[i].day);
ntf("Invalid day.\n");
            return 1;
        }
    }

    qsort(people, numPeople, sizeof(struct Person), compareBirthdays);

    printf("\nSorted Birthday List:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("%s: %d/%d\n", people[i].name, people[i].month, people[i].day);
    }

    int searchMonth;
    printf("\nEnter a month to search for birthdays: ");
    scanf("%d", &searchMonth);

    printf("\nBirthdays in month %d:\n", searchMonth);
    for (int i = 0; i < numPeople; i++) {
        if (people[i].month == searchMonth) {
            printf("%s: %d/%d\n", people[i].name, people[i].month, people[i].day);
        }
    }

    return 0;
}

