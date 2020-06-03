#include <stdio.h>
#include <stdlib.h>
#include "info.h"
#include "common_display.h"
#include "info.h"
#include <string.h>
#include "add_menu.h"

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

