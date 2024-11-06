#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    char s[10000];
    char stack[100][10000];
    int top = -1;

    file = fopen("stack.txt", "w");
    if(file == NULL)
    {
        puts("cannot open file");
    }
    else
    {
        printf("Enter some content:\n");
        while(strlen(gets(s)) > 0)
        {
            fputs(s, file);
            fputs("\n", file);
        }
        fclose(file);
    }

    printf("Already entered contents..\n",s);
    file = fopen("stack.txt","r");
    if(file==NULL)
    {
        puts("cannot open file");
    }
    else
    {
        while(fgets(s,sizeof(s),file)!=NULL)
            printf("%s",s);
    }
    fclose(file);

    file = fopen("stack.txt", "r");
    while(fgets(s, sizeof(s), file) != NULL)

    {

        if (top < 99)
        {
            top++;
            strcpy(stack[top], s);
        }
    }
    fclose(file);


    printf("Reversed content of the file:\n");
    while(top >= 0)
    {
        printf("%s", stack[top]);
        top--;
    }


    return 0;
}
