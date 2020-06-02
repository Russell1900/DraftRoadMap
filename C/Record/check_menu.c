#include <stdio.h>
#include <info.h>

void disp_search_item_name();
void disp_search_item_id();

void disp_check_menu(void){
    
    char c;

    do{
        show_header("DELETE ITEM");
        printf("A.Search by ID.\n");
        printf("B.Search by Name.\n");
        printf("X.Return.\n");
        printf("\nCommand:");
        scanf("%c", &c);
        getchar(); // this is used to handle the LF char after last input.
        switch(c){
            case 'a':
            case 'A':
                disp_search_item_id();
                break;
            case 'b':
            case 'B':
                disp_search_item_name();
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

void disp_search_item_id(){
    int id;
    Person **p=NULL;
    printf("Type in ID: ");
    scanf("%d", id);
    p = search_item_id(id);

    if(p==NULL){
        printf("\nNot found.");
    }else{
        while(*p!=NULL){
            print_item(*p);
            p++;
        }
    }
}

void disp_search_item_name(){
    char name[20];
    Person **p=NULL;
    printf("Type in ID: ");
    scanf("%s", &name);
    getchar();
    p = search_item_name(name);

    if(p==NULL){
        printf("\nNot found.");
    }else{
        while(*p!=NULL){
            print_item(*p);
            p++;
        }
    }

}