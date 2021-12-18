void terbaru(Customer *info){
    int tp = 0;
    int tempID;
    char tempRoom[255];
    long long int tempPrice;

    FILE *fpp = fopen("../customer/customer_data.txt", "r");

    while(fscanf(fpp, "C%d,%[^,],%d,%[^,],%[^,],%d,R00%d\n", &info[tp].cus_id, info[tp].cus_name, &info[tp].age, info[tp].death, info[tp].place, &info[tp].died, &info[tp].x.room_id) != EOF){
        // printf("C%d,%s,%d,%s,%s,%d,R%d\n", info[i].cus_id, info[i].cus_name, info[i].age, info[i].death, info[i].place, info[i].died, info[i].x.room_id);

        FILE *fkk = fopen("../room/room.txt", "r");

        while(fscanf(fkk, "R%d,%[^,],%lld\n", &tempID, tempRoom, &tempPrice) != EOF){
            if(tempID == info[tp].x.room_id){
                strcpy(info[tp].x.room_name, tempRoom);
                info[tp].x.price = tempPrice;
            }

        }
        fclose(fkk);

        tp++;
    }
    
    fclose(fpp);
}

void read(Customer *info){
    terbaru(info);

    printf("|   | ID   | Name  | Age | Room   |\n");
    printf("|---|------|-------|-----|--------|\n");
    for(int k = 0; k < i; k++){
        if(info[k].cus_id < 10){
            printf("| %d | C00%d ", k+1, info[k].cus_id);
        }
        else if(info[k].cus_id < 100){
            printf("| %d | C0%d ", k+1, info[k].cus_id);
        }
        else{
            printf("| %d | C%d ", k+1, info[k].cus_id);
        }
        printf("| %s | %d  | %s |\n", info[k].cus_name, info[k].age, info[k].x.room_name);
    }
}

void create(Customer *info){
    char name[255];
    int flag;

    do{
        flag = 0;
        printf("Name (lowercaase letters): ");
        getchar();
        scanf("%[^\n]", name);
        for(int l = 0; l < strlen(name); l++){
            if(name[l] < 'a' || name[l] > 'z'){
                flag++;
            }
        }
    }while(flag != 0);

    int umur;
    do{
        printf("Age (0 - 100): ");
        scanf("%d", &umur);
    }while(umur < 0 || umur > 100);

    char cause[255];
    getchar();
    printf("Cause of Death (max 255 letters): ");
    scanf("%[^\n]", cause);

    char rest[255];
    getchar();
    printf("Resting Place (max 255 letters): ");
    scanf("%[^\n]", rest);

    char type[255];
    char pantai[] = "Pantai";
    char roof[] = "Rooftop";
    char taman[] = "Taman";
    char bar[] = "Bar";
    do{
        printf("Room Type (Pantai, Rooftop, Taman, Bar): ");
        getchar();
        scanf("%[^\n]", type);
    }while(strcmp(type, pantai) != 0 && strcmp(type, roof) != 0 && strcmp(type, taman) != 0 && strcmp(type, bar) != 0);
    
    printf("\nWelcome to Hotel del Jojo!\n");

    Customer *newInfo = (Customer*)malloc(sizeof(Customer));

    info[i].cus_id = i+1;
    strcpy(info[i].cus_name, name);
    info[i].age = umur;
    strcpy(info[i].death, cause);
    strcpy(info[i].place, rest);
    
    FILE *fo = fopen("../room/room.txt", "r");

    int tempID;
    char tempRoom[255];
    long long int tempPrice;

    while(fscanf(fo, "R%d,%[^,],%lld\n", &tempID, tempRoom, &tempPrice) != EOF){
        if(strcmp(tempRoom, type) == 0){
            info[i].x.room_id = tempID;
            strcpy(info[i].x.room_name, tempRoom);
            info[i].x.price = tempPrice;
        }
    }

    fclose(fo);

    printf("C%d,%s,%d,%s,%s,%d,R%d\n", info[i].cus_id, info[i].cus_name, info[i].age, info[i].death, info[i].place, info[i].age, info[i].x.room_id);

    FILE *fl = fopen("../customer/customer_data.txt", "a");

    if(info[i].cus_id < 10){
        fprintf(fl, "\nC00%d,%s,%d,%s,%s,%d,R00%d", info[i].cus_id, info[i].cus_name, info[i].age, info[i].death, info[i].place, info[i].age, info[i].x.room_id);
    }
    else if(info[i].cus_id < 100){
        fprintf(fl, "\nC0%d,%s,%d,%s,%s,%d,R00%d", info[i].cus_id, info[i].cus_name, info[i].age, info[i].death, info[i].place, info[i].age, info[i].x.room_id);
    }
    else{
        fprintf(fl, "\nC%d,%s,%d,%s,%s,%d,R00%d", info[i].cus_id, info[i].cus_name, info[i].age, info[i].death, info[i].place, info[i].age, info[i].x.room_id);
    }

    fclose(fl);
    i++;
    // read(info);
}

void update(Customer *info){
    terbaru(info);

    printf("|   | ID   | Name  | Age | Room   |\n");
    printf("|---|------|-------|-----|--------|\n");
    for(int k = 0; k < i; k++){
        if(info[k].cus_id < 10){
            printf("| %d | C00%d ", k+1, info[k].cus_id);
        }
        else if(info[k].cus_id < 100){
            printf("| %d | C0%d ", k+1, info[k].cus_id);
        }
        else{
            printf("| %d | C%d ", k+1, info[k].cus_id);
        }
        printf("| %s | %d  | %s |\n", info[k].cus_name, info[k].age, info[k].x.room_name);
    }
    
    int num;

    do{
        num = 1;
        printf("Enter ID: ");
        getchar();
        scanf("C%d", &num);
    }while(num > i || num - 1 < 0);

    printf("C%d,%s,%d,%s,%s,%d,R%d\n", info[num-1].cus_id, info[num-1].cus_name, info[num-1].age, info[num-1].death, info[num-1].place, info[num-1].died, info[num-1].x.room_id);
    
    char type[255];
    char pantai[] = "Pantai";
    char roof[] = "Rooftop";
    char taman[] = "Taman";
    char bar[] = "Bar";
    do{
        printf("Insert New Room (Pantai, Rooftop, Taman, Bar): ");
        getchar();
        scanf("%[^\n]", type);
    }while(strcmp(type, pantai) != 0 && strcmp(type, roof) != 0 && strcmp(type, taman) != 0 && strcmp(type, bar) != 0);

    // Customer *info = (Customer*)malloc(sizeof(Customer));

    FILE *fj = fopen("../room/room.txt", "r");

    int tempID;
    char tempRoom[255];
    long long int tempPrice;

    while(fscanf(fj, "R%d,%[^,],%lld\n", &tempID, tempRoom, &tempPrice) != EOF){
        if(strcmp(type, tempRoom) == 0){
            info[num-1].x.room_id = tempID;
            strcpy(info[num-1].x.room_name, tempRoom);
            info[num-1].x.price = tempPrice;
        }
    }
    fclose(fj);

    FILE *ff = fopen("../customer/customer_data.txt", "w");

    for(int n = 0; n < i; n++){
        if(i < 10){
            fprintf(ff, "C00%d,%s,%d,%s,%s,%d,R00%d\n", info[n].cus_id, info[n].cus_name, info[n].age, info[n].death, info[n].place, info[n].died, info[n].x.room_id);
        } 
        else if (i < 100){
            fprintf(ff, "C0%d,%s,%d,%s,%s,%d,R00%d\n", info[n].cus_id, info[n].cus_name, info[n].age, info[n].death, info[n].place, info[n].died, info[n].x.room_id);
        }
        else{
            fprintf(ff, "C%d,%s,%d,%s,%s,%d,R00%d\n", info[n].cus_id, info[n].cus_name, info[n].age, info[n].death, info[n].place, info[n].died, info[n].x.room_id);
        }
    }
    fclose(ff);
}


void remove(Customer *info){

    printf("|   | ID   | Name  | Age | Room   |\n");
    printf("|---|------|-------|-----|--------|\n");
    for(int k = 0; k < i; k++){
        if(info[k].cus_id < 10){
            printf("| %d | C00%d ", k+1, info[k].cus_id);
        }
        else if(info[k].cus_id < 100){
            printf("| %d | C0%d ", k+1, info[k].cus_id);
        }
        else{
            printf("| %d | C%d ", k+1, info[k].cus_id);
        }
        printf("| %s | %d  | %s |\n", info[k].cus_name, info[k].age, info[k].x.room_name);
    }
    int num;
    do{
        num = 1;
        printf("Enter ID: ");
        getchar();
        scanf("C%d", &num);
    }while(num > i || num - 1 < 0);

    for(int n = 0; n < i - 1; n++){
        if(n == num-1){
            info[n].cus_id = info[n+1].cus_id;
            strcpy(info[n+1].cus_name, info[n].cus_name);
            info[n].age = info[n+1].age;
            strcpy(info[n+1].death, info[n].death);
            strcpy(info[n+1].place, info[n].place);
            info[n].x.room_id = info[n+1].x.room_id;
        }
    }

    FILE *fz = fopen("../customer/customer_data.txt", "w");

    for(int n = 0; n < i; n++){
        if(n != num-1){
            if(i < 10){
            fprintf(fz, "C00%d,%s,%d,%s,%s,%d,R00%d\n", info[n].cus_id, info[n].cus_name, info[n].age, info[n].death, info[n].place, info[n].died, info[n].x.room_id);
            } 
            else if (i < 100){
                fprintf(fz, "C0%d,%s,%d,%s,%s,%d,R00%d\n", info[n].cus_id, info[n].cus_name, info[n].age, info[n].death, info[n].place, info[n].died, info[n].x.room_id);
            }
            else{
                fprintf(fz, "C%d,%s,%d,%s,%s,%d,R00%d\n", info[n].cus_id, info[n].cus_name, info[n].age, info[n].death, info[n].place, info[n].died, info[n].x.room_id);
            }
        }
    }

    fclose(fz);
    terbaru(info);
    i--;

    printf("|   | ID   | Name  | Age | Room   |\n");
    printf("|---|------|-------|-----|--------|\n");
    for(int k = 0; k < i; k++){
        if(info[k].cus_id < 10){
            printf("| %d | C00%d ", k+1, info[k].cus_id);
        }
        else if(info[k].cus_id < 100){
            printf("| %d | C0%d ", k+1, info[k].cus_id);
        }
        else{
            printf("| %d | C%d ", k+1, info[k].cus_id);
        }
        printf("| %s | %d  | %s |\n", info[k].cus_name, info[k].age, info[k].x.room_name);
    }
}