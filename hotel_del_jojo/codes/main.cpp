#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Room{
    int room_id;
    char room_name[10];
    long long int price;
};

struct Customer{
    int cus_id;
    char cus_name[255];
    int age;
    char death[255];
    char place[255];
    int died;
    Room x;
};

Customer info[100];

int i = 0;
int choose;

#include "customer.h"
void menu(Customer *info);

void menu(Customer *info){
    printf("\n");
    printf("Hotel del Jojo\n");
    printf("1. Add new customer\n");
    printf("2. Read data\n");
    printf("3. Update data\n");
    printf("4. Remove data\n");
    printf("5. Exit\n");
    printf("\n");
    printf("Choice [1-5] >> ");

    do{
        scanf("%d", &choose);
    }while(choose < 1 || choose > 5);
    
    switch(choose){
        case 1:
            create(info);
            break;

        case 2:
            read(info);
            menu(info);
            break;

        case 3:
            update(info);
            break;

        case 4:
            remove(info);
            break;
    }
}

void import_data_from_file(Customer *info){

    int tempID;
    char tempRoom[255];
    long long int tempPrice;

    FILE *fp = fopen("../customer/customer_data.txt", "r");

    while(fscanf(fp, "C%d,%[^,],%d,%[^,],%[^,],%d,R%d\n", &info[i].cus_id, info[i].cus_name, &info[i].age, info[i].death, info[i].place, &info[i].died, &info[i].x.room_id) != EOF){

        FILE *fk = fopen("../room/room.txt", "r");

        while(fscanf(fk, "R%d,%[^,],%lld\n", &tempID, tempRoom, &tempPrice) != EOF){
            if(tempID == info[i].x.room_id){
                strcpy(info[i].x.room_name, tempRoom);
                info[i].x.price = tempPrice;
            }

        }
        fclose(fk);

        i++;
    }


    
    fclose(fp);
}


int main(){
    import_data_from_file(info);
    menu(info);
}