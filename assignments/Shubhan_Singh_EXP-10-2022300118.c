// A publishing company holds in a file details (ISBN, Title, Author)of all the books they publish.However, in the future, they wish to maintain two distinct files 

// (i)paperbacks (ii) hardbacks. 

// Write a program which reads a file containing details of both paperback and hardback books and creates two files as specified above. 

// Assume that the first character in each input record indicates if the book is paperback(p) or hardback(h) or both(b).
// #include<stdio.h>

// int main(){
//     int n;
//     char type;
//     char isbn[14],title[50],author[50];
//     FILE* library,* hardback,* paperback;
//     library=fopen("all_books.txt","a");
//     hardback=fopen("hardbacks.txt","a");
//     paperback=fopen("paperbacks.txt","a");
//     printf("Enter number of records you want to add: ");
//     scanf("%d",&n);
//     if(n>0){printf("Enter all records in the format Type(p,h or b),ISBN,Title,author, each in a new line\n");}
//     fprintf(library,"TYPE AVAILABLE | ISBN          | TITLE                          | AUTHOR\n");
//     fprintf(hardback,"ISBN          | TITLE                          | AUTHOR\n");
//     fprintf(paperback,"ISBN          | TITLE                          | AUTHOR\n");
//     for(int i=0;i<n;i++){
//         while((getchar())!='\n');
//         scanf("%c",&type);
//         while((getchar())!='\n');
//         scanf("%[^\n]",isbn);
//         while((getchar())!='\n');
//         scanf("%[^\n]",title);
//         while((getchar())!='\n');
//         scanf("%[^\n]",author);
//         fprintf(library,"%-14c | %13s | %-30s | %s\n",type,isbn,title,author);
//         if(type=='p' || type=='b'){
//             fprintf(paperback,"%13s | %-30s | %s\n",isbn,title,author);
//         }
//         if(type=='h' || type=='b'){
//             fprintf(hardback,"%13s | %-30s | %s\n",isbn,title,author);
//         }
//     }
//     fclose(library);
//     fclose(paperback);
//     fclose(hardback);
//     return 0;
// }





// Set up a file containing vehicle rEcords which hold registration number and owner information (name and address).
//  Write a program which, given a vehicle’s registration number, will rapidly retrieve and print the owner information.

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// typedef struct vrecords{
//     char reg_no[15];
//     char name[50];
//     char address[100];
// }vrec;
// int main(){
//     int x,n;
//     vrec temprecord;
//     FILE *records;
    
//     while(1){
//     printf("Enter 1 to append vehicle records, 0 to access them or -1 to exit: ");
//     scanf("%d",&x);
//     if(x==-1){break;}
//     if(x==1){
//         records=fopen("Vehicle_records.txt","a+");
//         printf("Enter number of records to add: ");
//         scanf("%d",&n);
//         for(int i=0;i<n;i++){
//             if(x==1){
//             printf("Enter registration number, owners name and address(each in a new line) for record %d\n",i+1);
//             while((getchar())!='\n');
//             scanf("%s%*c%[^\n]%*c%[^\n]",temprecord.reg_no,temprecord.name,temprecord.address);
//             fwrite(temprecord.reg_no,strlen(temprecord.reg_no)*sizeof(char),1,records);  
//             fprintf(records,"\n");
//             fwrite(temprecord.name,strlen(temprecord.name)*sizeof(char),1,records);
//             fprintf(records,"\n");
//             fwrite(temprecord.address,strlen(temprecord.address)*sizeof(char),1,records);
//             fprintf(records,"\n");
//             }
//         }
//         fclose(records);
//     }
//     if(x==0){
//         records=fopen("Vehicle_records.txt","a+");
//         char *tempstr,*tempstr2,*tempstr3;
//         char reg[15];
//         tempstr=(char*)calloc(51,sizeof(char));
//         tempstr2=(char*)calloc(51,sizeof(char));
//         tempstr3=(char*)calloc(51,sizeof(char));
//         int flag=0;
//         printf("Enter a registration number: ");
//         while((getchar())!='\n');
//         scanf("%s%*c",reg);
//         while(1){
//             fscanf(records,"%[^\n]%*c",tempstr);
//             if(feof(records)){break;}
//             if(strcmp(tempstr,reg)==0){
//                 flag=1;
//                 fscanf(records,"%[^\n]%*c",tempstr2);
//                 printf("The name of the driver is: %s\n",tempstr2);
//                 fscanf(records,"%[^\n]%*c",tempstr3);
//                 printf("His address is: %s\n",tempstr3);
//                 break;
//             }
//         }

//         if(flag==0){
//             printf("Record not found!\n");
//         }
//         flag=0;
//         free(tempstr);
//         free(tempstr2);
//         free(tempstr3);
//         fclose(records);
//     }
//     }
// return 0;
// }