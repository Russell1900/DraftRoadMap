#include <stdio.h>
#include <stdlib.h>
#include "info.h"

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
            }else{
                p_mov->Next = p;
                p_mov = p_mov->Next;
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
    tailer->Next = per;
    tailer = tailer->Next;
}

void show_all(){
    
}