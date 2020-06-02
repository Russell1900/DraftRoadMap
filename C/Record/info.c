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
        fclose(fp);
    }
    header = head;
    tailer = p_mov;
}

void save_items(void){
    /* this function is to save items to database, if database is empty or 
       not found, return NULL, else return head ptr */

    FILE *fp;
    Person *p;
    p = header;
    if((fp=fopen(DB_FILE, "w"))!=NULL){
        while(p!=NULL){
            fwrite(p, ITEM_SIZE, 1, fp);
        }
        fclose(fp);
    }
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
    if(header==NULL){
        header = per;
        tailer = per;
    }else{
        tailer->Next = per;
        tailer = tailer->Next;
    }
}
