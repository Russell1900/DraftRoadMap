#include <stdio.h>
#include <stdlib.h>
#include "info.h"
#include "common_display.h"
#include "info.h"
#include <string.h>

void add_item(void);

void disp_add_menu(void){
    char c;

    do{
        show_header("ADD ITEM");
        printf("A.Add Items.\n");
        printf("X.Return.\n");
        printf("\nCommand:");
        scanf("%c", &c);
        getchar(); // this is used to handle the LF char after last input.
        switch(c){
            case 'a':
            case 'A':
                add_item();
                break;
            case 'x':
            case 'X':
                break;
            default:
                printf("Wrong selection, type again.\n");
                break;
        }
    }while(c!='x'&&c!='X');

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