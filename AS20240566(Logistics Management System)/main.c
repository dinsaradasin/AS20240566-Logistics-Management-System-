#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_CITIES 30

void cityManage(char city[MAX_CITIES][50],int *count);
void distanceManage(float distance[MAX_CITIES][MAX_CITIES],char city[MAX_CITIES][50],int count);
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
    float distance[MAX_CITIES][MAX_CITIES] = {0};
    printf("\n===============================\n\n");
    printf("  logistics management system\n");
    do
    {
        printf("\n===============================\n");
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
            distanceManage(distance,city,count);
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
    do
    {
        found=0;
        printf("\n1.Add a new city\n");
        printf("2.Rename a city\n");
        printf("3.Remove a city\n");
        printf("4.Display Cities\n");
        printf("5.Exit\n\n");
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
        else if(option==5)
        {
            break;
        }
        else
        {
            printf("Invalid option\n");
        }
    }while(option!=5);

}
void distanceManage(float distance[MAX_CITIES][MAX_CITIES],char city[MAX_CITIES][50],int count)
{
    int option,found1=0,found2=0;
    int tempCity1=0,tempCity2=0;
    char temp[2][50];
    do
    {
        printf("1.Enter the Distance between cities\n");
        printf("2.Update the distance between cities\n");
        printf("3.Display the distances\n");
        printf("4.Exit\n\n");
        printf("Enter the option:");
        scanf("%d",&option);
        if(option==1)
        {
            for(int i=0;i<count;i++)
            {
                for(int j=i+1;j<count;j++)
                {
                     if(distance[i][j]!=0)
                     {
                         continue;
                     }
                 printf("Enter the Distance between city %s and %s:",city[i],city[j]);
                 scanf("%f",&distance[i][j]);
                 distance[j][i]=distance[i][j];
                }
            distance[i][i]=0;
            }
        }
        else if(option==2)
        {
            found1=0;
            found2=0;
            getchar();
            printf("Enter the name city 1 :");
            fgets(temp[0],sizeof(temp[0]),stdin);
            temp[0][strcspn(temp[0], "\n")] = '\0';
            printf("Enter the name city 2 :");
            fgets(temp[1],sizeof(temp[1]),stdin);
            temp[1][strcspn(temp[1], "\n")] = '\0';

            for(int a=0;a<count;a++)
            {
                if(strcmp(city[a], temp[0]) == 0)
                {
                    found1=1;
                    tempCity1=a;
                }
                if(strcmp(city[a], temp[1]) == 0)
                {
                    found2=1;
                    tempCity2=a;
                }
            }
            if(found1==1 && found2==1)
            {
                printf("Enter the distance between cities %s and %s:",temp[0],temp[1]);
                scanf("%f",&distance[tempCity1][tempCity2]);
                distance[tempCity2][tempCity1]=distance[tempCity1][tempCity2];
            }
            else if(found1==1 && found2==0)
            {
                printf("City name %s is incorrect:\n",temp[0]);
            }
            else if(found1==0 && found2==1)
            {
                printf("City name %s is incorrect:\n",temp[1]);
            }
            else
            {
                printf("Invalid City names\n");
            }
        }
        else if(option==3)
        {
            if (count == 0)
            {
                printf("No cities to display.\n");
                break;
            }
            printf("\nDistance Table\n\n");
            printf("%-20s", "City");

            for(int b=0;b<count;b++)
            {
                printf("%-20s",city[b]);
            }
            printf("\n");
            for(int l=0;l<count;l++)//
            {
                printf("-------------------------");
            }
            printf("\n");
            for(int c=0;c<count;c++)
            {
                printf("%-20s",city[c]);
                for(int d=0;d<count;d++)
                {
                    printf("%-20.2f",distance[c][d]);
                }
                printf("\n");
                for(int l=0;l<count;l++)//
                {
                    printf("-------------------------");
                }
                printf("\n");
            }

            printf("\n");
        }
        else if(option==4)
        {
            break;
        }
        else
        {
            printf("Invalid Option\n");

        }
    }while(option!=4);


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
