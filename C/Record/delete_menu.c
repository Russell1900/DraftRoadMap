#include <stdio.h>
#include "info.h"
#include "common_display.h"

void disp_del_menu(void){
    char c;

    do{
        show_header("DELETE ITEM");
        printf("A.Delete by ID.\n");
        printf("B.Delete by Name.\n");
        printf("X.Return.\n");
        printf("\nCommand:");
        scanf("%c", &c);
        getchar(); // this is used to handle the LF char after last input.
        switch(c){
            case 'a':
            case 'A':
                disp_del_item_id();
                break;
            case 'b':
            case 'B':
                disp_del_item_name();
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

void disp_del_item_id(){
    int id, i, choice=-1;
    Person *p=NULL;
    printf("Type in ID: ");
    scanf("%d", id);
    search_item_id(id);

    if(p_len == 0){
        printf("\nNot found.");
        return;
    }
    
    do{
        for(i=0;i<p_len;i++){
            printf("%d.------\n", i+1);
            if(parr[i]!=NULL){
                print_item(parr[i]);
            }else{
                printf("  \n");
            }
            
        }
        printf("0.Return.\n");
        printf("Choose which to delete: ");
        scanf("%d", &choice);
        if(choice!=0){
            delete_item(parr[choice-1]);
        }

    }while(choice!=0);
    
}

void disp_del_item_name(){
    int i, choice=-1;
    char name[20];
    Person *p=NULL;
    printf("Type in NAME: ");
    scanf("%s", name);
    getchar();
    search_item_name(name);

    if(p_len == 0){
        printf("\nNot found.");
        return;
    }
    
    do{
        for(i=0;i<p_len;i++){
            printf("%d.------\n", i+1);
            if(parr[i]!=NULL){
                print_item(parr[i]);
            }else{
                printf("  \n");
            }
            
        }
        printf("0.Return.\n");
        printf("Choose which to delete: ");
        scanf("%d", &choice);
        if(choice!=0){
            delete_item(parr[choice-1]);
        }

    }while(choice!=0);
    
}