#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Roomdata();
void Roombooking();
void readdata();
void searchbooking();
void updatebooking();
void printreceipt();

struct room //Declaring struct so it will be well organized and used later
{
    int Room_Id[10],Room_Price[10];
    char Room_Type[10][20];
    char availability[100][100];
};struct room details[10];

struct bookroom
{
    int roomid,days;
    char contact[20];
    char name[100];
    char email[100];
    char passport[50];
};

struct updateroom
{
    int roomid[10];
    int days[10];
    char contact[20][20];
    char name[100][100];
    char email[100][100];
    char passport[50][50];
};struct updateroom updatebook[10];

int main()
{
    printf("\n\n\033[0;31m************** HOTEL BOOKING **************\033[0m\n\n");
    int choice;

    while(1)
    {
        printf("\n\033[0;36m1. Show Available Rooms \n");
        printf("2. Book a Room \n");
        printf("3. Search File \n");
        printf("4. Update Booking \n");
        printf("5. Print Receipt \n");
        printf("6. Exit\033[0m\n\n\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                {
                    Roomdata();
                    break;
                }
            case 2:
                {
                    Roombooking();
                    break;
                }
            case 3:
                {
                    searchbooking();
                    break;
                }
            case 4:
                {
                    updatebooking();
                    break;
                }
            case 5:
                {
                    printreceipt();
                    break;
                }
            case 6:
                printf("\n\n\t\t\tHave A Nice Day !\n\n\n");
                exit(0);    // terminates the complete program execution
            default:
                printf("\n*******Enter Correct Input*******\n");
        }
    }
    printf("\n\n\t\t\tHave A Nice Day !\n\n\n");
    return 0;
}

void Roomdata()
{
//initializing that struct
    printf("\033[0;35m\t  Welcome to our Hotel!\033[0m\n");
    printf("\033[0;36m    These are room we have Currently\033[0m\n");
    for (int i = 0; i < 10; i++) // Here we are assigning room numbers to that struct
    {
        if (i <5)
        {
            details->Room_Id[i] = 101 + i;
        }
        if (i >4)
        {
            details->Room_Id[i] = 200 + i-4;
        }
    }

    for (int i = 0; i < 1; i++) // Here we are assigning room type to that struct
    {
        strcpy(details->Room_Type[i],"Superior");
        strcpy(details->Room_Type[i+1],"Deluxe");
        strcpy(details->Room_Type[i+2],"Studio");
        strcpy(details->Room_Type[i+3],"Executive Suite");
        strcpy(details->Room_Type[i+4],"Deluxe Suite");
        strcpy(details->Room_Type[i+5],"Superior");
        strcpy(details->Room_Type[i+6],"Deluxe");
        strcpy(details->Room_Type[i+7],"Studio");
        strcpy(details->Room_Type[i+8],"Executive Suite");
        strcpy(details->Room_Type[i+9],"Deluxe Suite");
    }
    for (int i = 0; i < 1; i++) // Here we are assigning room price to that struct
    {
        details->Room_Price[i] = 180; 
        details->Room_Price[i+1] = 200;
        details->Room_Price[i+2] = 250;
        details->Room_Price[i+3] = 400;
        details->Room_Price[i+4] = 500;
        details->Room_Price[i+5] = 180; 
        details->Room_Price[i+6] = 200;
        details->Room_Price[i+7] = 250;
        details->Room_Price[i+8] = 400;
        details->Room_Price[i+9] = 500;
    }
    int y = 0;
    while ( y < 10)
    {
        strcpy(details->availability[y],"YES");
        readdata();
        y++;
    }
    
    printf("\033[1;31m"); //Changing Color to RED
    printf(" Room ID\t Room Type\t Room Price\t Available\n");
    printf("\033[0m"); //Changing color back to DEFAULT

    int i = 0;
    while ( i < 10) //Looping through the struct to print data
    {
        if (i ==0 || i == 5)
        {
            printf("   %d\t\t %s %13d %15s\n",details->Room_Id[i],details->Room_Type[i],details->Room_Price[i],details->availability[i]);
            //i++;
        }
        else if (i ==3 || i == 8)
        {
            printf("   %d\t %20s %9d %15s\n",details->Room_Id[i],details->Room_Type[i],details->Room_Price[i],details->availability[i]);
            //i++;
        }
        else if (i ==4 || i == 9)
        {
            printf("   %d\t %19s %10d %15s\n",details->Room_Id[i],details->Room_Type[i],details->Room_Price[i],details->availability[i]);
            //i++;
        }
        else
            printf("   %d\t\t %s %15d %15s\n",details->Room_Id[i],details->Room_Type[i],details->Room_Price[i],details->availability[i]);
        i++;
    }
}

void Roombooking()
{
    struct bookroom Roombook[10];
    int book;
    FILE *fp;
    fp = fopen("BookingDetails.txt","a+");

    printf("\n\033[0;35mTo Book a Room Please Enter the Following Details\n");
    printf("Name: ");
    scanf("%s",Roombook->name);
    printf("IC/Passport: ");
    scanf("%s",Roombook->passport);
    printf("Contact Number: ");
    scanf("%s",Roombook->contact);
    printf("Email Address: ");
    scanf("%s",Roombook->email);
    printf("Enter Room ID: ");
    scanf("%d",&Roombook->roomid);
    printf("Number of Days Your want to stay: ");
    scanf("%d",&Roombook->days);
    printf("\033[0m"); //TO END COLOR
    fprintf(fp,"%s %s %s %s %d %d\n",Roombook->name,Roombook->passport,Roombook->contact,Roombook->email,Roombook->roomid,Roombook->days);
    fclose (fp);
}

void readdata()
{
    FILE *f;
    f = fopen("BookingDetails.txt","r");
    int roomid[10];
    int days[10];
    char contact[20][20];
    char name[100][100];
    char email[100][100];
    char passport[50][50];
    int checkroom[10] = {101,102,103,104,105,201,202,203,204,205};
    
    FILE *fp2;
    int count = 0;  // Line counter (result)
    char filename[] = "BookingDetails.txt";
    char c;  // To store a character read from file
    
    // Open the file
    fp2 = fopen("BookingDetails.txt", "r");
    
    // Check if file exists
    if (fp2 == NULL)
        {
            printf("Could not open file %s", filename);
        }
    
    // Extract characters from file and store in character c
    for (c = getc(fp2); c != EOF; c = getc(fp2))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
    
    // Close the file
    fclose(fp2);
    for (int i = 0; i < count; i++) {
        fscanf(f,"%s",name[i]);
        fscanf(f,"%s",passport[i]);
        fscanf(f,"%s",contact[i]);
        fscanf(f,"%s",email[i]);
        fscanf(f,"%d",&roomid[i]);
        fscanf(f,"%d",&days[i]);
    }
    for(int i = 0; i<10; i++)
    {
        if (roomid[i]==101)
        {
            strcpy(details->availability[0],"NO");
        }
        if (roomid[i]==102)
        {
            strcpy(details->availability[1],"NO");
        }
        if (roomid[i]==103)
        {
            strcpy(details->availability[2],"NO");
        }
        if (roomid[i]==104)
        {
            strcpy(details->availability[3],"NO");
        }
        if (roomid[i]==105)
        {
            strcpy(details->availability[4],"NO");
        }
        if (roomid[i]==201)
        {
            strcpy(details->availability[5],"NO");
        }
        if (roomid[i]==202)
        {
            strcpy(details->availability[6],"NO");
        }
        if (roomid[i]==203)
        {
            strcpy(details->availability[7],"NO");
        }
        if (roomid[i]==204)
        {
            strcpy(details->availability[8],"NO");
        }
        if (roomid[i]==205)
        {
            strcpy(details->availability[9],"NO");
        }
    }
}

void searchbooking()
{
    char searchid[10];
    int found = 0;
    char line[300];

    printf("\033[0;35mEnter The Room ID : ");
    scanf("%s",searchid);
    printf("\033[0m");
    FILE *fp = fopen("BookingDetails.txt","r");

    if(fp == NULL)
    {
        printf("\nERROR: File cannot open");
        return;
    }

    while (!feof(fp))
    {
        fgets(line,300,fp);
        if (strstr(line,searchid)!=NULL)
        {
            printf("\n\033[0;31m%s\033[0m",line);
            found = 1;
            break;
        }
        
    }
    printf("\n");
    if (found == 0)
    {
        printf("Sorry We could not find the booking details. Please Book Again");
    }
}

void updatebooking()
{
    FILE *f;
    f = fopen("BookingDetails.txt","r");

    int updateroom,countupdate;
    
    FILE *fp2;
    int count = 0;  // Line counter (result)
    char filename[] = "BookingDetails.txt";
    char c;  // To store a character read from file
    // Open the file
    fp2 = fopen("BookingDetails.txt", "r");  
    // Check if file exists
    if (fp2 == NULL)
        {
            printf("Could not open file %s", filename);
        }
    // Extract characters from file and store in character c
    for (c = getc(fp2); c != EOF; c = getc(fp2))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
    // Close the file
    fclose(fp2);

    for (int i = 0; i < count; i++) {
        fscanf(f,"%s",updatebook->name[i]);
        fscanf(f,"%s",updatebook->passport[i]);
        fscanf(f,"%s",updatebook->contact[i]);
        fscanf(f,"%s",updatebook->email[i]);
        fscanf(f,"%d",&updatebook->roomid[i]);
        fscanf(f,"%d",&updatebook->days[i]);
    }
    fclose(f);
    printf("Please Enter your Room ID to Update Your Details: ");
    scanf("%d",&updateroom);

    for (int i = 0; i < count; i++)
    {
        if (updateroom == updatebook->roomid[i])
        {
            printf("\n\033[0;32m%s %s %s %s %d %d\033[0m\n",updatebook->name[i],updatebook->passport[i],updatebook->contact[i],updatebook->email[i],updatebook->roomid[i],updatebook->days[i]);
            printf("\n\033[0;35mWhat Do you want to update? 1. Name, 2.IC/Passport, 3.Contact Number, 4.Email ID, 5.Days of Stay: ");
            scanf("%d",&countupdate);

            if (countupdate == 1)
            {
                printf("UPDATE Name: ");
                scanf("%s",updatebook->name[i]);
                printf("Updated Name is %s\n",updatebook->name[i]);
            }
            else if (countupdate == 2)
            {
                printf("UPDATE IC/Passport: ");
                scanf("%s",updatebook->passport[i]);
                printf("Updated Passport is %s\n",updatebook->passport[i]);
            }
            else if (countupdate == 3)
            {
                printf("UPDATE Contact Number: ");
                scanf("%s",updatebook->contact[i]);
                printf("Updated Contact Number is %s\n",updatebook->contact[i]);
            }
            else if (countupdate == 4)
            {
                printf("UPDATE Email ID: ");
                scanf("%s",updatebook->email[i]);
                printf("Updated Email ID is %s\n",updatebook->email[i]);
            }
            else if (countupdate == 5)
            {
                printf("UPDATE Days of Stay: ");
                scanf("%d",&updatebook->days[i]);
                printf("Updated Days of Stay is %d\033[0m\n",updatebook->days[i]);
            }
            else
            {
                printf("\nPlease Enter Correct ROOM ID or Book Again with US");
            }
        }
    }
    
    FILE *fpointer;
    fpointer = fopen("BookingDetails.txt","w");

    for (int i = 0; i < count; i++)
    {
        fprintf(fpointer,"%s %s %s %s %d %d\n",updatebook->name[i],updatebook->passport[i],updatebook->contact[i],updatebook->email[i],updatebook->roomid[i],updatebook->days[i]);
        
    }
    fclose(fpointer);
}

void printreceipt()
{
    struct updateroom viewreceipt[10];
    int roomno,tax,price,tourismtax,total=0;
    FILE *f;
    f = fopen("BookingDetails.txt","r");
    
    FILE *fp2;
    int count = 0;  // Line counter (result)
    char filename[] = "BookingDetails.txt";
    char c;  // To store a character read from file
    // Open the file
    fp2 = fopen("BookingDetails.txt", "r");  
    // Check if file exists
    if (fp2 == NULL)
        {
            printf("Could not open file %s", filename);
        }
    // Extract characters from file and store in character c
    for (c = getc(fp2); c != EOF; c = getc(fp2))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
    // Close the file
    fclose(fp2);

    for (int i = 0; i < count; i++) {
        fscanf(f,"%s",viewreceipt->name[i]);
        fscanf(f,"%s",viewreceipt->passport[i]);
        fscanf(f,"%s",viewreceipt->contact[i]);
        fscanf(f,"%s",viewreceipt->email[i]);
        fscanf(f,"%d",&viewreceipt->roomid[i]);
        fscanf(f,"%d",&viewreceipt->days[i]);
    }
    fclose(f);

    printf("\033[0;31mEnter Your Room No: ");
    scanf("%d",&roomno);

    for (int i = 0; i < count; i++)
    {
        if (roomno == viewreceipt->roomid[i])
        {
            printf("\n**** Your Recipt ****\n");
            printf("Your Name: %s\n",viewreceipt->name[i]);
            printf("Your Email ID: %s\n",viewreceipt->email[i]);
            printf("Your Contact: %s\n",viewreceipt->contact[i]);
            printf("Your Booked Room: %d\n",viewreceipt->roomid[i]);
            printf("Your Days Of Stay: %d\n",viewreceipt->days[i]);

            if (viewreceipt->roomid[i] == 101 || viewreceipt->roomid[i] == 201 )
            {
                price = 180;
            }
            else if (viewreceipt->roomid[i] == 102 || viewreceipt->roomid[i] == 202 )
            {
                price = 200;
            }
            else if (viewreceipt->roomid[i] == 103 || viewreceipt->roomid[i] == 203 )
            {
                price = 250;
            }
            else if (viewreceipt->roomid[i] == 104 || viewreceipt->roomid[i] == 204 )
            {
                price = 400;
            }
            else if (viewreceipt->roomid[i] == 105 || viewreceipt->roomid[i] == 205 )
            {
                price = 500;
            }
            else
            {
                printf("\nEnter Correct Room No\n");
            }
            
            price = price * viewreceipt->days[i];
            tax = price * 0.10;
            tourismtax = 10 * viewreceipt->days[i];
            total = price + tax + tourismtax;
            printf("Your Total Including 10 Percent tax and Tourism tax is RM%d\033[0m\n",total);

            FILE *fpp;
            fpp = fopen("BookingDetails.txt","w");

            for (int i = 0; i < count; i++)
            {
                if (roomno != viewreceipt->roomid[i])
                {
                    fprintf(fpp,"%s %s %s %s %d %d\n",viewreceipt->name[i],viewreceipt->passport[i],viewreceipt->contact[i],viewreceipt->email[i],viewreceipt->roomid[i],viewreceipt->days[i]);
                }
            }
            fclose(fpp);
        }
    }
}