/*
0000000001 Author RomLabo
1000111000 ReRad
1000000001 Created on 24/11/2023.
1000100011111000000001100001110000
1000110001111000110001100010101000
0000011000011000000001100011011000
*/

#include <stdio.h>
#include <stdlib.h>

/* Globals constants */
const unsigned short int USR_IN_SIZE = 2;
const unsigned short int RES_YES = 0;
const unsigned short int RES_NO = 1;
const unsigned short int RES_ERR = 2;

/* Globals variables */
char usr_in_val[USR_IN_SIZE];
int usr_in_bin = 0;
int is_quit = RES_ERR;

/* Declaration of functions */
int do_quit(void);
int empty_buffer(void);

/* Main */
int main(int argc, const char * argv[]) {
    if (argc > 0 && argc < 3) {
        printf("%c\n", *(argv[1]));
    }
    
    printf("Welcome on MemRo !!\n");
    int do_quit_val = 0;
    do {
        do_quit_val = do_quit();
    } while (do_quit_val >= 2);
    
    /* Test de la fonction do_quit */
    if (do_quit_val == 0) {
        printf("Your response : %s !\n", usr_in_val);
        printf("Bye Bye !\n");
    } else {
        printf("Your response : %s !\n", usr_in_val);
        printf("Oh nice you stay here !\n");
    }
    return 0;
}


/* Definition of functions */
int do_quit(void) {
    is_quit = RES_ERR;
    printf("Quit MemRo (y/n) ? ");
    if (fgets(usr_in_val, USR_IN_SIZE, stdin) != NULL) {
        switch (usr_in_val[0]) {
            case 'y': is_quit = RES_YES; break;
            case 'Y': is_quit = RES_YES; break;
            case 'n': is_quit = RES_NO; break;
            case 'N': is_quit = RES_NO; break;
            default: is_quit = RES_ERR; break;
        }
    }
    empty_buffer();
    return is_quit;
}

int empty_buffer(void) {
    usr_in_bin = 0;
    while (usr_in_bin != '\n' && usr_in_bin != EOF) {
        usr_in_bin = getchar();
    }
    return 0;
}
