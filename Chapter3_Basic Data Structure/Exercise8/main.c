#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StudentNode
{
    char *studentName;
    struct StudentNode *next;
} STUDENT;

typedef struct ClassNode
{
    char *className;
    struct ClassNode *next;
    STUDENT *students;
} CLASS;

STUDENT *insertStudent(STUDENT *monitor, char *studentName)
{
    STUDENT *newNode = (STUDENT *)malloc(sizeof(STUDENT));
    newNode->studentName = studentName;
    if (monitor == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = monitor;
    }
    monitor = newNode;
    return monitor;
}

CLASS *insertClass(CLASS *mainClass, STUDENT *monitor, char *className)
{
    CLASS *newNode = (CLASS *)malloc(sizeof(CLASS));
    newNode->className = className;
    newNode->students = monitor;
    if (mainClass == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = mainClass;
    }
    mainClass = newNode;
    return mainClass;
}

void printStudents(STUDENT *monitor)
{
    if (monitor != NULL)
    {
        STUDENT *currentStudent = monitor;
        while (currentStudent != NULL)
        {
            printf("%s\t", currentStudent->studentName);
            currentStudent = currentStudent->next;
        }
        printf("\n");
    }
    else
    {
        printf("No Student!\n");
    }
}

void printClasses(CLASS *class)
{
    if (class != NULL)
    {
        CLASS *currentClass = class;
        while (currentClass != NULL)
        {
            printf("%s\t", currentClass->className);
            currentClass = currentClass->next;
        }
        printf("\n");
    }
    else
    {
        printf("No Class!\n");
    }
}

void printDetail(CLASS *mainClass)
{
    if (mainClass == NULL)
    {
        printf("None of Class!\n");
    }
    else
    {
        CLASS *currentClass = mainClass;
        while (currentClass != NULL)
        {
            STUDENT *monitor = currentClass->students;
            printf("\nClass %s: ", currentClass->className);
            while (monitor != NULL)
            {
                printf("%s, ", monitor->studentName);
                monitor = monitor->next;
            }
            currentClass = currentClass->next;
        }
        printf("\n");
    }
}

void main()
{
    STUDENT *monitorSTARLAB = NULL;
    STUDENT *monitorAvenger = NULL;
    STUDENT *monitorKripton = NULL;
    STUDENT *monitorFlash = NULL;

    monitorSTARLAB = insertStudent(monitorSTARLAB, "Barry Allen");
    monitorSTARLAB = insertStudent(monitorSTARLAB, "Caitlyn Snow");
    monitorSTARLAB = insertStudent(monitorSTARLAB, "Cisco Ramon");
    monitorSTARLAB = insertStudent(monitorSTARLAB, "Harrison Wells");
    // printStudents(monitorSTARLAB);

    monitorAvenger = insertStudent(monitorAvenger, "Iron Man");
    monitorAvenger = insertStudent(monitorAvenger, "Captain American");
    monitorAvenger = insertStudent(monitorAvenger, "Spider Man");
    monitorAvenger = insertStudent(monitorAvenger, "Black Widow");
    monitorAvenger = insertStudent(monitorAvenger, "Vision");
    monitorAvenger = insertStudent(monitorAvenger, "Haw Eyes");
    monitorAvenger = insertStudent(monitorAvenger, "Ant Man");
    monitorAvenger = insertStudent(monitorAvenger, "Scalet Witch");
    // printStudents(monitorAvenger);

    monitorKripton = insertStudent(monitorKripton, "Kal-el");
    monitorKripton = insertStudent(monitorKripton, "Mon-el");
    monitorKripton = insertStudent(monitorKripton, "Jor-el");
    monitorKripton = insertStudent(monitorKripton, "Zod");
    // printStudents(monitorKripton);

    monitorFlash = insertStudent(monitorFlash, "The Flash");
    monitorFlash = insertStudent(monitorFlash, "Kid Flash");
    monitorFlash = insertStudent(monitorFlash, "Jesse Quick");
    monitorFlash = insertStudent(monitorFlash, "Zoom");
    monitorFlash = insertStudent(monitorFlash, "Reverse Flash");
    monitorFlash = insertStudent(monitorFlash, "The Rival");
    monitorFlash = insertStudent(monitorFlash, "Black Flash");
    monitorFlash = insertStudent(monitorFlash, "Savitar");
    // printStudents(monitorFlash);

    CLASS *class = NULL;

    class = insertClass(class, monitorAvenger, "Avenger");
    class = insertClass(class, monitorKripton, "Kripton");
    class = insertClass(class, monitorFlash, "Flash");
    class = insertClass(class, monitorSTARLAB, "STARLAB");
    // printClasses(class);

    printDetail(class);
}