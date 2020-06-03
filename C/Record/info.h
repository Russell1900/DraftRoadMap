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
    struct person *Prev;
}Person;

Person* header;
Person* tailer;
int total_num;

Person *parr[20];
int p_len;

void load_items(void);
void clearall();
void insert_item(Person* per);
void search_item_id(int id);
void search_item_name(char* name);
void save_items();
void add_item(void);
void delete_item(Person *p);

#endif