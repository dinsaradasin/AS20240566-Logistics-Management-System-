#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_CITIES 30

void cityManage(char city[MAX_CITIES][50],int *count);
void distanceManage();
void vehicleManage();
void deliveryRequest();
void calcCTF();
void deliveryRecords();
void leastDistance();
void performanceReport();
void fileHandle();

int main()
{
    int choice;
    int count=0;
    char city[MAX_CITIES][50];
    do
    {
        printf("1.City Management\n");
        printf("2.Distance Management between Cities\n");
        printf("3.Vehicle Management\n");
        printf("4.Delivery Request Handling\n");
        printf("5.Cost,Time and Fuel Calculations\n");
        printf("6.Delivery Records\n");
        printf("7.Least Cost Route\n");
        printf("8.Performance Report\n");
        printf("9.File Management\n");
        printf("10.Exit\n\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            cityManage(city,&count);
            break;
        case 2:
            distanceManage();
            break;
        case 3:
            vehicleManage();
            break;
        case 4:
            deliveryRequest();
            break;
        case 5:
            calcCTF();
            break;
        case 6:
            deliveryRecords();
            break;
        case 7:
            leastDistance();
            break;
        case 8:
            performanceReport();
            break;
        case 9:
            fileHandle();
            break;
        case 10:
            break;
        default:
            printf("Invalid option\n");
        }
    }while(choice!=10);

    return 0;
}
void cityManage(char city[MAX_CITIES][50],int *count)
{
    int option;
    int found=0;
    char temp[50];
    printf("1.Add a new city\n");
    printf("2.Rename a city\n");
    printf("3.Remove a city\n");
    printf("4.Display Cities\n\n");
    printf("Enter the option:");
    scanf("%d",&option);
    if(option==1)
    {
        getchar();
        printf("Enter the name of city %d:",*count+1);
        fgets(city[*count],sizeof(city[*count]),stdin);
        city[*count][strcspn(city[*count], "\n")] = '\0';
        (*count)++;
        printf("\n");
    }

    else if(option==2)
    {
        getchar();
        printf("Enter the current name of the city:");
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';
        for(int i=0;i<*count;i++)
        {
            if (strcmp(city[i], temp) == 0)
            {
                printf("Enter the new name of city %s:",city[i]);
                fgets(city[i], sizeof(city[i]), stdin);
                city[i][strcspn(city[i], "\n")] = '\0';
                printf("City renamed successfully!\n\n");
                found=1;
                printf("\n");
                break;
            }
        }
        if(found==0)
        {
            printf("Enter a valid city name\n\n");
        }
    }
    else if(option==3)
    {
        getchar();
        printf("Enter the current name of the city:");
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';
        for(int j=0;j<*count;j++)
        {
            if (strcmp(city[j], temp) == 0)
            {
                for(int n=j;n<*count-1;n++)
                {
                    strcpy(city[n], city[n+1]);
                }
                (*count)--;
                printf("City removed successfully\n\n");
                found=1;
                break;
            }
        }
        if(found==0)
        {
            printf("Enter a valid city name\n\n");
        }
    }

    else if(option==4)
    {
        for(int a=0;a<*count;a++)
        {
            printf("City %d:%s\n\n",a+1,city[a]);
        }
    }
    else
    {
        printf("Invalid option\n");
    }

}
void distanceManage()
{

}
void vehicleManage()
{

}
void deliveryRequest()
{

}
void calcCTF()
{

}
void deliveryRecords()
{

}
void leastDistance()
{

}
void performanceReport()
{

}
void fileHandle()
{

}
