#include <stdio.h>
#include "common_display.h"
#include "add_menu.h"
#include "check_menu.h"
#include "info.h"

int show_main_menu(void){
    int c;
    int i = 0;
    do{
        show_header("MAIN");
        printf("A.Check Items.\n");
        printf("B.Add Items.\n");
        printf("C.Delete Items.\n");
        printf("D.Show All Items.\n");
        printf("S.Save.\n");
        printf("X.Close.\n");
        printf("\nCommand:\n");
        scanf("%c", &c);
        getchar(); // this is used to handle the LF char after last input.
        //printf("input is %d\n", c);
        //printf("loop is %d\n", i++);
        switch(c){
            case 'a':
            case 'A':
                //disp_check_menu();
                printf("disp_check_menu\n");
                break;
            case 'b':
            case 'B':
                disp_add_menu();
                break;
            case 'c':
            case 'C':
                disp_del_menu();
                break;
            case 'd':
            case 'D':
                show_all_items();
                break;
            case 's':
            case 'S':
                save_items();
                break;
            case 'x':
            case 'X':
                printf("BYE!\n");
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