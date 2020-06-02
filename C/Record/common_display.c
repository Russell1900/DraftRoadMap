#include <stdio.h>
#include "info.h"

void show_header(char* name){
    printf("------ %s ------\n", name);
}

void print_item(Person *item){
    show_header("ITEM");

    printf("ID: %s\n", item->id);
    printf("NAME: %s\n", item->name);
    printf("GENDER: %s\n", item->ged==male?"Male":"FEMALE");
    printf("AGE: %d\n", item->age);
    printf("TELEPHONE: %s\n", item->tel);
    printf("SALARY: %d\n", item->salary);
    printf("ADDRESS: %s\n", item->addr);
}


void show_all_items(){
    Person *p;
    p = header;
    while(header != NULL){
        print_item(p);
    }
}