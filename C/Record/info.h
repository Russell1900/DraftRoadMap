#ifndef INFO_H
#define INFO_H

#define DB_FILE "record.db"
#define ITEM_SIZE sizeof(Person)

typedef enum gender{
    male, female
}Gender;

typedef struct person{
    int id;
    char name[10];
    char tel[11];
    int age;
    Gender ged;
    int salary;
    char addr[50];
    struct person *Next;
}Person;

Person* header;
Person* tailer;
int total_num;

void load_items(void);
void append(Person* per);
#endif