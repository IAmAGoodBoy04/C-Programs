// // A men’s sports club keeps elaborate computerized records of all its members. The
// // records contain typical information such as age, address, etc. of each person. 
// // But there is also information about whether a member is an active playing members, 
// // about whether he is married, and so on; if he is married the record contains information 
// // about his wife’s name, the no. of children and their names. Write a program which 
// // demonstrates how such a system might be implemented. Show how the names of the wives of 
// // all active playing members might be printed.

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// struct childdata{
//     int noofchildren;
//     char** names_of_children;
//     };
// struct playerbio{
//     char name[50];
//     int age,isactive,ismarried;
//     char address[150];
//     char *wifename;
//     struct childdata children;
// }bio;

// void takeinput(struct playerbio* arr,int n){
//     char temp;
//     for(int i=0;i<n;i++){
//         printf("Enter name of player %d: ",i+1);
//         scanf("%[^\n]%*c",arr[i].name);
//         printf("Enter age of player %d: ",i+1);
//         scanf("%d%*c",&(arr[i].age));
//         printf("Enter address of player %d: ",i+1);
//         scanf("%[^\n]%*c",arr[i].address);
//         printf("Is the player active?: ");
//         scanf("%c",&temp);
//         while((getchar())!='\n');
//         if(temp=='Y' || temp=='y'){
//             arr[i].isactive=1;
//         }
//         printf("Is the player married?: ");
//         scanf("%c",&temp);
//         while((getchar())!='\n');
//         if(temp=='Y' || temp=='y'){
//             arr[i].ismarried=1;
//             printf("Enter wife's name: ");
//             arr[i].wifename=(char *)malloc(51*sizeof(char));
//             scanf("%[^\n]%*c",arr[i].wifename);
//             printf("Enter number of children: ");
//             scanf("%d%*c",&arr[i].children.noofchildren);
//             if(arr[i].children.noofchildren>0){
//                 arr[i].children.names_of_children=(char**)malloc(arr[i].children.noofchildren*sizeof(char *));
//                 for(int k=0;k<arr[i].children.noofchildren;k++){
//                     arr[i].children.names_of_children[k]=(char *)malloc(50*sizeof(char));
//                 }
//                 printf("Enter names of all children\n");
//                 for(int j=0;j<arr[i].children.noofchildren;j++){
//                     scanf("%[^\n]%*c",arr[i].children.names_of_children[j]);
//                 }
//             }
//         }
//         else{arr[i].children.noofchildren=0;}
//     }
// }
// void printoutput(struct playerbio* arr, int n){
//     int longest_name=0,longest_address=0,longest_wifename=0,longest_childname=0,temp;
//     for(int i=0;i<n;i++){
//         temp=strlen(arr[i].name);
//         if(temp>longest_name){longest_name=temp;}
//         temp=strlen(arr[i].address);
//         if(temp>longest_address){longest_address=temp;}
//         if(arr[i].ismarried==1){
//             temp=strlen(arr[i].wifename);
//             if(temp>longest_wifename){longest_wifename=temp;}
//             if(arr[i].children.noofchildren>0){
//                 for(int p=0;p<arr[i].children.noofchildren;p++){
//                     temp=strlen(arr[i].children.names_of_children[p]);
//                     if(temp>longest_childname){
//                         longest_childname=temp;
//                     }
//                 }
//             }
//         }
//     }
//     char* name="NAME";
//     char * address="ADDRESS";
//     char * wife_name="WIFE NAME";
//     char * children_name="NAME OF CHILD(REN)";
//     char *childcount="NO. OF CHILDREN";
//     char *no_child="-";
//     if(longest_name<5){longest_name=4;}
//     if(longest_address<8){longest_address=7;}
//     if(longest_wifename<11){longest_wifename=10;}
//     if(longest_childname<19){longest_childname=18;}
//     printf("%-*s | AGE | %-*s | status     | marital status | %-*s | %-15s | %-*s\n\n\n",longest_name,name,longest_address,address,longest_wifename,wife_name,childcount,longest_childname,children_name);
//     while(1){static int i=0;
//         char* status;
//         char * marital_status;
//         char *wifename;
//         if(arr[i].isactive==1){status="active";}
//         else{status="inactive";}
//         if(arr[i].ismarried==1){marital_status="married";}
//         else{marital_status="unmarried";}
//         if(arr[i].ismarried==1){
//         printf("%-*s | %3d | %-*s | %-10s | %-14s | %-*s | %-15d ",longest_name,arr[i].name,arr[i].age,longest_address,arr[i].address,status,marital_status,longest_wifename,arr[i].wifename,arr[i].children.noofchildren);}
//         else{printf("%-*s | %3d | %-*s | %-10s | %-14s | %-*s | %-15d ",longest_name,arr[i].name,arr[i].age,longest_address,arr[i].address,status,marital_status,longest_wifename,no_child,arr[i].children.noofchildren);}
//         if(arr[i].children.noofchildren==0){printf("| %s\n",no_child);}
//         else{
//             for(int q=0;q<arr[i].children.noofchildren;q++){
//                 if(q!=0){
//                 for(int r=0;r<(longest_name+longest_address+longest_wifename+61);r++){
//                 printf(" ");}
//                 }
//                 printf("| %s\n",arr[i].children.names_of_children[q]);
//             }
//         }
//         printf("\n");
//         i++;
//         if(i==n){break;}
//     }
//     //For non tabular output
//     // for(int i=0;i<n;i++){
//     // printf("The name of player %d is: %s\n",i+1,arr[i].name);
//     // printf("His age is: %d\n",arr[i].age);
//     // printf("His address is: %s",arr[i].address);
//     // if(arr[i].isactive==1){
//     //     printf("\n%s is active\n",arr[i].name);
//     // }
//     // else{
//     //     printf("\n%s is currently inactive\n",arr[i].name);
//     // }
//     // if(arr[i].ismarried==1){
//     //     printf("%s is married with %d children\n",arr[i].name,arr[i].children.noofchildren);
//     //     printf("The name of his wife is %s\n",arr[i].wifename);
//     //     if(arr[i].children.noofchildren>0){
//     //         printf("The names of his children are:\n");
//     //         for(int x=0;x<arr[i].children.noofchildren;x++){
//     //             printf("%s\n",arr[i].children.names_of_children[x]);
//     //         }
//     //     }
//     // }
//     // else{
//     //     printf("He is not married\n");
//     // }
//     // printf("\n");
//     // }
// }
// int main(){
//     int n;
//     printf("Enter number of players to store data for: ");
//     scanf("%d%*c",&n);
//     struct playerbio arr[n];
//     takeinput(arr,n);
//     printf("\n\n");
//     printoutput(arr,n);
//     for(int i=0;i<n;i++){
//         free(arr[i].wifename);
//         free(arr[i].children.names_of_children);
//     }
//     return 0;
// }



// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// typedef struct flight{
//     char source_city_code[10];
//     char destination_code[10];
//     int departure_time,arrival_time,no_of_seats;
// }flights;
// void admin_portal(flights *arr,int *n){
//     char c_yn;
//     int i=*n;
//     printf("\nWelcome to admin portal\nDo you want to add a flight to the list?(Yes/No)\n");
    
//     while(1){
//         scanf("%c",&c_yn);
//         while((getchar())!='\n');
//         if(c_yn=='n' || c_yn=='N'){
//             break;
//         }
        
//         printf("For flight %d :-\n",i+1);
//         printf("Enter 3 letter airport code of source city: ");
//         scanf("%s%*c",arr[i].source_city_code);
//         printf("Enter 3 letter airport code of destination city: ");
//         scanf("%s%*c",arr[i].destination_code);
//         printf("Enter no. of available seats: ");
//         scanf("%d%*c",&arr[i].no_of_seats);
//         printf("Enter time of departure(in 24 hour format): ");
//         scanf("%d%*c",&arr[i].departure_time);
//         printf("Enter time of arrival at destination (in 24 hour format): ");
//         scanf("%d%*c",&arr[i].arrival_time);
//         printf("Do you want to add another flight to the list?(Yes/No)\n");
//         i++;
//     }
//     *n=i;
//     printf("Admin portal closed\n\n");
// }
// void booking_portal(flights *arr,int n){
//     char *source;
//         char *dest;
//         source=malloc(10*sizeof(char));
//         dest=malloc(10*sizeof(char));
//         char c;
//         int dep;
//     if(n<1){printf("No flights available");}
//     else{
//         printf("\nSource City | Destination | Time of Departure | Time of arrival | No of available seats\n\n");
//         for(int j=0;j<n;j++){
//             printf("%-11s | %-11s | %-17d | %-15d | %d\n",arr[j].source_city_code,arr[j].destination_code,arr[j].departure_time,arr[j].arrival_time,arr[j].no_of_seats);
//         }
//         printf("\n");
//         printf("Enter source city: ");
//         scanf("%s%*c",source);
//         printf("Enter destination city: ");
//         scanf("%s",dest);
//         printf("Enter time of departure(in 24 hour format): ");
//         scanf("%d",&dep);
//         while((getchar())!='\n');
//         for(int i=0;i<=n;i++){
//             if(i>n-1){printf("No such flight was found,or no seats are left.\n");break;}
//             else if(strcmp(source,arr[i].source_city_code)==0 && strcmp(dest,arr[i].destination_code)==0 && dep==arr[i].departure_time && arr[i].no_of_seats>0){
//                 printf("Flight booked! Thanks for choosing us.\n");
//                 arr[i].no_of_seats--;
//                 break;
//             }
//         }
//         printf("Do you want to book another ticket?\n");
//         scanf("%c%*c",&c);
//         if(c=='y' || c=='Y'){
//             booking_portal(arr,n);
//         }
//         else{
//             printf("Booking portal closed");
//         }
//     }
//     free(source);
//     free(dest);
// }
// int main(){
//     flights flight_data[30];
//     int n=0;
//     int *p=&n;
//     char *portal_string;
//     printf("WELCOME TO SINGH AIRLINES\nType password for admin portal, or next for booking portal, or exit to exit\n");
//     while(1){
//     scanf("%s%*c",portal_string);
//     char password[5]="2309";
//     if(strcmp(portal_string,"exit")==0){
//         break;
//     }
//     else if(strcmp(portal_string,password)==0){
//         admin_portal(flight_data,p);
//     }
//     else if(portal_string[0]=='n'||portal_string[0]=='N'){
//         booking_portal(flight_data,n);
//     }
//     else{printf("Wrong password!\n");}
//     printf("\nType password for admin portal, or next for booking portal, or exit to exit\n");
//     }
//     printf("Thank you for visiting!\n");
// return 0;
// }