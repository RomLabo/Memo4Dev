/*
0000000001 Author RomLabo 111111111
1000111000 Memo4Dev 111111111111111
1000000001 Created on 22/12/2023 11
10001000111110000000011000011100001
10001100011110001100011000101010001
00000110000110000000011000110110001
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BADOPT -1

typedef struct {
    char *value;
    int id;
} m_opt;

static m_opt all_opt[] = {
    { "git", 0 }, { "js", 1 }, { "php", 2 }, { "css", 3 }
};

#define NBOPT (sizeof(all_opt)/sizeof(m_opt))

/* 
    Globals constants
*/
const unsigned short int USR_IN_SIZE = 2;
const unsigned short int RES_YES = 0;
const unsigned short int RES_NO = 1;
const unsigned short int RES_ERR = 2;

/*
    Globals variables
*/
char usr_in_val[USR_IN_SIZE];
int usr_in_bin = 0;
int is_quit = RES_ERR;

/* 
    Declaration of functions
*/
int id_from_opt(const char *option);
int do_quit(void);
int empty_buffer(void);

/*
    Main
*/
int main(int argc, const char * argv[]) {
    printf("::: Memo4Dev :::\n\n");
    int i;
    
    if (argc == 2) {
        switch (id_from_opt(argv[1])) {
            case 0: printf("call git\n"); break;
            case 1: printf("call js\n"); break;
            case 2: printf("call php\n"); break;
            case 3: printf("call css\n"); break;
            case -1: printf("Error \n"); break;
        }
    } else {
        printf("all options :\n");
        for (i = 0; i < NBOPT; i+= 2) {
            printf("%s  %s\n", all_opt[i].value, all_opt[i+1].value);
        }
    }
    
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

/*
    Definition of functions
*/
int id_from_opt(const char *option) {
    int i;
    for (i=0; i < NBOPT; i++) {
        m_opt *opt = &all_opt[i];
        if (strcmp(opt->value, option) == 0)
            return opt->id;
    }
    return BADOPT;
}

int do_quit(void) {
    is_quit = RES_ERR;
    printf("Quit (y/n) ? ");
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
