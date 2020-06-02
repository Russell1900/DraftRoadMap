#include <stdio.h>
#include <stdlib.h>
#include "info.h"
#include "common_display.h"
#include "info.h"

void add_item(void);

void disp_add_menu(void){
    char c;

    do{
        show_header("ADD ITEM");
        printf("A.Add Items.\n");
        printf("R.Return.\n");
        printf("\nCommand:");
        scanf("%c", &c);
        switch(c){
            case 'a':
            case 'A':
                add_item();
                break;
            case 'r':
            case 'R':
                break;
            default:
                printf("Wrong selection, type again.\n");
                break;
        }
    }while(c!='r'&&c!='R');

}

void add_item(void){
    Person *p;
    char ge, c;

    p = (Person*)malloc(ITEM_SIZE);

    printf("ID: ");
    scanf("%d", &p->id);
    printf("\nName: ");
    scanf("%s", &p->name);
    printf("\nGender(M/F): ");
    scanf("%c", &ge);
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

    printf("\nsave?(Y/N):");
    scanf("%c", &c);
    if(c=='y'||c=='y'){
        append(p);
    }else{
        free(p);
    }
    printf("\n");
}