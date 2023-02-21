// A publishing company holds in a file details (ISBN, Title, Author)of all the books they publish.However, in the future, they wish to maintain two distinct files 

// (i)paperbacks (ii) hardbacks. 

// Write a program which reads a file containing details of both paperback and hardback books and creates two files as specified above. 

// Assume that the first character in each input record indicates if the book is paperback(p) or hardback(h) or both(b).
#include<stdio.h>

int main(){
    int n;
    char type;
    char isbn[14],title[50],author[50];
    FILE* library,* hardback,* paperback;
    library=fopen("all_books.txt","a");
    hardback=fopen("hardbacks.txt","a");
    paperback=fopen("paperbacks.txt","a");
    printf("Enter number of records you want to add: ");
    scanf("%d",&n);
    if(n>0){printf("Enter all records in the format Type(p,h or b),ISBN,Title,author, each in a new line\n");}
    fprintf(library,"TYPE AVAILABLE | ISBN          | TITLE                          | AUTHOR\n");
    fprintf(hardback,"ISBN          | TITLE                          | AUTHOR\n");
    fprintf(paperback,"ISBN          | TITLE                          | AUTHOR\n");
    for(int i=0;i<n;i++){
        while((getchar())!='\n');
        scanf("%c",&type);
        while((getchar())!='\n');
        scanf("%[^\n]",isbn);
        while((getchar())!='\n');
        scanf("%[^\n]",title);
        while((getchar())!='\n');
        scanf("%[^\n]",author);
        fprintf(library,"%-14c | %13s | %-30s | %s\n",type,isbn,title,author);
        if(type=='p' || type=='b'){
            fprintf(paperback,"%13s | %-30s | %s\n",isbn,title,author);
        }
        if(type=='h' || type=='b'){
            fprintf(hardback,"%13s | %-30s | %s\n",isbn,title,author);
        }
    }
    fclose(library);
    fclose(paperback);
    fclose(hardback);
    return 0;
}