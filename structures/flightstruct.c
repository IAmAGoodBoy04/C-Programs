#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct flight{
    char source_city_code[10];
    char destination_code[10];
    int departure_time,arrival_time,no_of_seats;
}flights;
void admin_portal(flights *arr,int *n){
    char c_yn;
    int i=*n;
    printf("\nWelcome to admin portal\nDo you want to add a flight to the list?(Yes/No)\n");
    
    while(1){
        scanf("%c",&c_yn);
        while((getchar())!='\n');
        if(c_yn=='n' || c_yn=='N'){
            break;
        }
        
        printf("For flight %d :-\n",i+1);
        printf("Enter 3 letter airport code of source city: ");
        scanf("%s%*c",arr[i].source_city_code);
        printf("Enter 3 letter airport code of destination city: ");
        scanf("%s%*c",arr[i].destination_code);
        printf("Enter no. of available seats: ");
        scanf("%d%*c",&arr[i].no_of_seats);
        printf("Enter time of departure(in 24 hour format): ");
        scanf("%d%*c",&arr[i].departure_time);
        printf("Enter time of arrival at destination (in 24 hour format): ");
        scanf("%d%*c",&arr[i].arrival_time);
        printf("Do you want to add another flight to the list?(Yes/No)\n");
        i++;
    }
    *n=i;
    printf("Admin portal closed\n\n");
}
void booking_portal(flights *arr,int n){
    if(n<1){printf("No flights available");}
    else{
        char source[4];
        char dest[4];
        char c;
        int dep;
        printf("\nSource City | Destination | Time of Departure | Time of arrival | No of available seats\n\n");
        for(int j=0;j<n;j++){
            printf("%-11s | %-11s | %-17d | %-15d | %d\n",arr[j].source_city_code,arr[j].destination_code,arr[j].departure_time,arr[j].arrival_time,arr[j].no_of_seats);
        }
        printf("\n");
        printf("Enter source city: ");
        scanf("%s%*c",source);
        printf("Enter destination city: ");
        scanf("%s%*c",dest);
        printf("Enter time of departure(in 24 hour format): ");
        scanf("%d%*c",&dep);
        for(int i=0;i<=n;i++){
            if(i==n){printf("No such flight was found,or no seats are left.\n");break;}
            if(strcmp(source,arr[i].source_city_code)==0 && strcmp(dest,arr[i].destination_code)==0 && dep==arr[i].departure_time && arr[i].no_of_seats>0){
                printf("Flight booked! Thanks for choosing us.\n");
                arr[i].no_of_seats--;
                break;
            }
        }
        printf("Do you want to book another ticket?\n");
        scanf("%c%*c",&c);
        if(c=='y' || c=='Y'){
            booking_portal(arr,n);
        }
        else{
            printf("Booking portal closed");
        }
    }

}
int main(){
    flights flight_data[30];
    int n=0;
    int *p=&n;
    char *portal_string;
    printf("WELCOME TO SINGH AIRLINES\nType password for admin portal, or next for booking portal, or exit to exit\n");
    while(1){
    scanf("%s%*c",portal_string);
    char password[5]="2309";
    if(strcmp(portal_string,"exit")==0){
        break;
    }
    else if(strcmp(portal_string,password)==0){
        admin_portal(flight_data,p);
    }
    else if(portal_string[0]=='n'||portal_string[0]=='N'){
        booking_portal(flight_data,n);
    }
    else{printf("Wrong password!\n");}
    printf("\nType password for admin portal, or next for booking portal, or exit to exit\n");
    }
    printf("Thank you for visiting!\n");
return 0;
}