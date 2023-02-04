// A men’s sports club keeps elaborate computerized records of all its members. The
// records contain typical information such as age, address, etc. of each person. 
// But there is also information about whether a member is an active playing members, 
// about whether he is married, and so on; if he is married the record contains information 
// about his wife’s name, the no. of children and their names. Write a program which 
// demonstrates how such a system might be implemented. Show how the names of the wives of 
// all active playing members might be printed.

#include<stdio.h>
#include<stdlib.h>
struct childdata{
    int noofchildren;
    char** names_of_children;
    };
struct playerbio{
    char name[50];
    int age,isactive,ismarried;
    char address[150];
    char wifename[50];
    struct childdata children;
}bio;

void takeinput(struct playerbio* arr,int n){
    char temp;
    for(int i=0;i<n;i++){
        printf("Enter name of player %d: ",i+1);
        scanf("%[^\n]%*c",arr[i].name);
        printf("Enter age of player %d: ",i+1);
        scanf("%d%*c",&(arr[i].age));
        printf("Enter address of player %d: ",i+1);
        scanf("%[^\n]%*c",arr[i].address);
        printf("Is the player active?: ");
        scanf("%c",&temp);
        while((getchar())!='\n');
        if(temp=='Y' || temp=='y'){
            arr[i].isactive=1;
        }
        printf("Is the player married?: ");
        scanf("%c",&temp);
        while((getchar())!='\n');
        if(temp=='Y' || temp=='y'){
            arr[i].ismarried=1;
            printf("Enter wife's name: ");
            scanf("%[^\n]%*c",arr[i].wifename);
            printf("Enter number of children: ");
            scanf("%d%*c",&arr[i].children.noofchildren);
            if(arr[i].children.noofchildren>0){
                arr[i].children.names_of_children=(char**)malloc(arr[i].children.noofchildren*sizeof(char *));
                for(int k=0;k<arr[i].children.noofchildren;k++){
                    arr[i].children.names_of_children[k]=(char *)malloc(50*sizeof(char));
                }
                printf("Enter names of all children\n");
                for(int j=0;j<arr[i].children.noofchildren;j++){
                    scanf("%[^\n]%*c",arr[i].children.names_of_children[j]);
                }
            }
        }
    }
}
void printoutput(struct playerbio* arr, int n){
    for(int i=0;i<n;i++){
    printf("The name of player %d is: %s\n",i+1,arr[i].name);
    printf("His age is: %d\n",arr[i].age);
    printf("His address is: %s",arr[i].address);
    if(arr[i].isactive==1){
        printf("\n%s is active\n",arr[i].name);
    }
    else{
        printf("\n%s is currently inactive\n",arr[i].name);
    }
    if(arr[i].ismarried==1){
        printf("%s is married with %d children\n",arr[i].name,arr[i].children.noofchildren);
        printf("The name of his wife is %s\n",arr[i].wifename);
        if(arr[i].children.noofchildren>0){
            printf("The names of his children are:\n");
            for(int x=0;x<arr[i].children.noofchildren;x++){
                printf("%s\n",arr[i].children.names_of_children[x]);
            }
        }
    }
    else{
        printf("He is not married\n");
    }
    printf("\n");
    }
}
int main(){
    int n;
    printf("Enter number of players to store data for: ");
    scanf("%d%*c",&n);
    struct playerbio arr[n];
    takeinput(arr,n);
    printf("\n\n");
    printoutput(arr,n);
    return 0;
}
