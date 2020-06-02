#include <stdio.h>
#include "common_display.h"
#include "add_menu.h"
#include "check_menu.h"

int show_main_menu(void){
    char c;

    do{
        show_header("MAIN");
        printf("A.Check Items.\n");
        printf("B.Add Items.\n");
        printf("C.Delete Items.\n");
        printf("D.Show All Items.\n");
        printf("X.Close.\n");
        printf("\nCommand:");
        scanf("%c", &c);
        switch(c){
            case 'a':
            case 'A':
                disp_check_menu();
                break;
            case 'b':
            case 'B':
                disp_add_menu();
                break;
            case 'c':
            case 'C':
                //disp_del_menu();
                break;
            case 'd':
            case 'D':
                show_all();
                break;
            case 'x':
            case 'X':
                printf("BYE!");
                break;
            default:
                printf("Wrong selection, type again.\n");
                break;
        }
    }while(c!='x'&&c!='X');

    return 0;

}

int main(int argc, char* argv[]){
    printf("Welcome to RECORDER!!!\n");
    load_items();
    show_main_menu();
    return 0;
}