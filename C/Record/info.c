#include <stdio.h>
#include <stdlib.h>
#include "info.h"
#include <string.h>

void load_items(void){
    /* this function is to load items from database, if database is empty or 
       not found, return NULL, else return head ptr */

    FILE *fp;
    Person *head=NULL, *p, *p_mov, buffer;
    p = p_mov = head;
    total_num = 0;
    if((fp=fopen(DB_FILE, "r"))!=NULL){
        while(fread(&buffer, ITEM_SIZE, 1, fp) == 1){
            total_num++;
            p = (Person*)malloc(ITEM_SIZE);
            *p = buffer;
            p->Next = NULL;
            if(head==NULL){
                head = p;
                p_mov = p;
                head->Next = NULL;
                head->Prev = NULL;
            }else{
                p_mov->Next = p;
                p->Prev = p_mov;
                p_mov = p_mov->Next;
                p_mov->Next = NULL;
            }
        }
    }
    header = head;
    tailer = p_mov;
}

void clearall(){
    Person *p, *tmp;
    p = header;
    while(p!=NULL){
        tmp = p;
        p = p->Next;
        free(tmp);
    }
    header = NULL;
}

void append(Person* per){
    per->Next = NULL;
    per->Prev = tailer;
    tailer->Next = per;
    tailer = tailer->Next;
}

void search_item_id(int id){
    Person *p;
    p_len = 0;
    memset((void*)parr, 0, sizeof(parr));
    p = header;
    while(p!=NULL){
        if(p->id==id){
            parr[p_len] = p;
            p_len++;
        }
        p = p->Next;
    }
}

void search_item_name(char* name){
    Person *p;
    p_len = 0;
    memset((void*)parr, 0, sizeof(parr));
    p = header;
    while(p!=NULL){
        if(strcmp(p->name, name)!=0){
            parr[p_len] = p;
            p_len++;
        }
        p = p->Next;
    }
}


void save_items(){
    Person *p;
    FILE *fp = NULL;
    p = header;
    if((fp = fopen(DB_FILE, "w"))!=NULL){
        while(p!=NULL){
            fwrite(p, ITEM_SIZE, 1, fp);
        }
        fclose(fp);
    }
}

void add_item(void){
    Person *p;
    char ge, c;

    p = (Person*)malloc(ITEM_SIZE);

    printf("ID: ");
    scanf("%d", &p->id);
    printf("\nName: ");
    scanf("%s", p->name);
    getchar(); // this is used to handle the LF char after last input.
    printf("\nGender(M/F): ");
    scanf("%c", &ge);
    getchar(); // this is used to handle the LF char after last input.
    if(ge=='m'||ge=='M'){
        p->ged = male;
    }else{
        p->ged = female;
    }
    printf("\nAge: ");
    scanf("%d", &p->age);
    printf("\nTelephone: ");
    scanf("%s", p->tel);
    printf("\nSalary: ");
    scanf("%d", &p->salary);
    printf("\nAddress: ");
    scanf("%s", p->addr);
    getchar(); // this is used to handle the LF char after last input.
    printf("\nsave?(Y/N):");
    scanf("%c", &c);
    getchar(); // this is used to handle the LF char after last input.
    if(c=='y'||c=='Y'){
        append(p);
    }else{
        free(p);
    }
    printf("\n");
}

void delete_items(Person *p){
    
}