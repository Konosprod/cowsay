#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* cow[] = {"     \\   ^__^                 ",                
               "      \\  (OO)\\__________    ",
               "         (__)\\          )\\/\\",
               "              | |----W  |   ",
               "              | |     | |   "};
/*
char* cow[] = {"   | ",
               "   | ",
               "  @ _ @", 
               " (='o'=)",  
               " *(___)*"};
*/

void print_cow(void);
void print_message(char*, int);
void print_message_multilines(char*, int);
void clean_stdin(void);

int main(int argc, char* argv[])
{
    int length = 0;
    char message[1000] = {0};
    
    if(argc >= 2)
   {
        if((length = strlen(argv[1])) < 42)
        {
            print_message(argv[1], length);
        }
        else
        {
            print_message_multilines(argv[1], length);
        }
    }
    else
    {
        printf("Entrez le message que vous voulez afficher : \n");
        scanf("%[^\n]s", message);
        printf("\n\n");
        
        if((length = strlen(message)) < 42)
        {
            print_message(message, length);
        }
        else
        {
            print_message_multilines(message, length);
        }
    }
    print_cow();
    clean_stdin();
    getchar();
    
    return 0;
}

void clean_stdin(void)
{
    int c;
 
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void print_cow(void)
{
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", cow[i]);
    }
}

void print_message_multilines(char* message, int length)
{
    int nb_chunk = (length/42)+1;
    char** strings = calloc(nb_chunk, sizeof(char*));
    
    for(int i = 0; i < nb_chunk; i++)
    {
        strings[i] = calloc(43, sizeof(char));
    }
    
    for(int i = 0; i < nb_chunk; i++)
    {
        for(int j = 0; j < 42; j++)
        {
            strings[i][j] = message[i*42+j];
        }
    }
    
    for(int i =(length%42); i < 42; i++)
    {
        strings[nb_chunk-1][i] = ' ';
    }
    
    
    putc(' ', stdout);
    putc('/', stdout);
    
    for(int i = 0; i < strlen(strings[0]); i++)
    {
        putc('-', stdout);
    }
    putc('\\', stdout);
    putc('\n', stdout);
    
    for(int i = 0; i < nb_chunk; i++)
    {
        printf("| %s |\n", strings[i]);
    }
    
    putc(' ', stdout);
    putc('\\', stdout);
    
    for(int i = 0; i < strlen(strings[0]); i++)
    {
        putc('-', stdout);
    }
    putc('/', stdout);
    putc('\n', stdout);
    
    for(int i = 0; i < nb_chunk+1; i++)
    {
        free(strings[i]);
    }
    
    free(strings);
}

void print_message(char* message, int length)
{
    int message_length = length;
    
    putc(' ', stdout);
    for(int i = 0; i < message_length+1; i++)
    {
        putc('_', stdout);
    }
    putc('\n', stdout);
    putc('<', stdout);
    putc(' ', stdout);
    
    printf("%s>\n", message);
    putc(' ', stdout);
    for(int i = 0; i < message_length+1; i++)
    {
        putc('-', stdout);
    }
    putc('\n', stdout);
}