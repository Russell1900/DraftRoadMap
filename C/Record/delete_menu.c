#include <stdio.h>

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
                del_item_id();
                break;
            case 'b':
            case 'B':
                del_item_name();
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

