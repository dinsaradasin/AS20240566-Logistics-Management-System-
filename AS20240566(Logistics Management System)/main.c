#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_CITIES 30
#define FUEL_PRICE 310
#define MAX_DEL 50

void cityManage(char city[MAX_CITIES][50],int *count);
void distanceManage(float distance[MAX_CITIES][MAX_CITIES],char city[MAX_CITIES][50],int count);
void vehicleManage(int capacity[3],float ratePerKm[3],float avgSpeed[3],float fuelEff[3],char type[3][20]);
void deliveryRequest(char city[MAX_CITIES][50], int count, int capacity[3], char type[3][20],int deliverySrc[MAX_DEL],int deliveryDes[MAX_DEL],float deliveryWei[MAX_DEL],int deliveryVehicle[MAX_DEL],int *deliveryCount);
void calcCTF(float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50], int count,int capacity[3], float ratePerKm[3], float avgSpeed[3], float fuelEff[3], char type[3][20],int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL], float deliveryWei[MAX_DEL],int deliveryVehicle[MAX_DEL], float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL], float profit[MAX_DEL], float customerCharge[MAX_DEL],int *deliveryCount,float totalCost[MAX_DEL]);
void deliveryRecords(float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50], int count,int capacity[3], float ratePerKm[3], float avgSpeed[3], float fuelEff[3], char type[3][20],int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL], float deliveryWei[MAX_DEL],int deliveryVehicle[MAX_DEL], float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL], float profit[MAX_DEL], float customerCharge[MAX_DEL],int deliveryCount,float totalCost[MAX_DEL]);
void leastDistance();
void performanceReport();
void fileHandle();

int main()
{
    int choice;
    int count=0;
    char city[MAX_CITIES][50];
    float distance[MAX_CITIES][MAX_CITIES] = {0};
    char type[3][20] = {"Van", "Truck", "Lorry"};
    int capacity[3];
    float ratePerKm[3];
    float avgSpeed[3];
    float fuelEff[3];

    int deliverySrc[MAX_DEL];
    int deliveryDes[MAX_DEL];
    float deliveryWei[MAX_DEL];
    int deliveryVehicle[MAX_DEL];
    float deliveryCost[MAX_DEL];
    float deliveryTime[MAX_DEL];
    float fuelUsed[MAX_DEL];
    float fuelCost[MAX_DEL];
    float profit[MAX_DEL];
    float customerCharge[MAX_DEL];
    float totalCost[MAX_DEL];
    int deliveryCount = 0;

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
            vehicleManage(capacity,ratePerKm,avgSpeed,fuelEff,type);
            break;
        case 4:
            deliveryRequest(city,count, capacity, type,deliverySrc,deliveryDes,deliveryWei,deliveryVehicle,&deliveryCount);

            break;
        case 5:
            calcCTF(distance,city,count,capacity,ratePerKm,avgSpeed,fuelEff,type,deliverySrc,deliveryDes,deliveryWei,deliveryVehicle,deliveryCost,deliveryTime,fuelUsed,fuelCost,profit,customerCharge,&deliveryCount,totalCost);

            break;
        case 6:
            deliveryRecords(distance,city,count,capacity,ratePerKm,avgSpeed,fuelEff,type,deliverySrc,deliveryDes,deliveryWei,deliveryVehicle,deliveryCost,deliveryTime,fuelUsed,fuelCost,profit,customerCharge,deliveryCount,totalCost);
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
void vehicleManage(int capacity[3],float ratePerKm[3],float avgSpeed[3],float fuelEff[3],char type[3][20])
{
    capacity[0] = 1000; ratePerKm[0] = 30; avgSpeed[0] = 60; fuelEff[0] = 12;
    capacity[1] = 5000; ratePerKm[1] = 40; avgSpeed[1] = 50; fuelEff[1] = 6;
    capacity[2] = 10000; ratePerKm[2] = 80; avgSpeed[2] = 45; fuelEff[2] = 4;
    printf("|-----------------------------------------------------------------------------------|\n");
    printf("|   Type    |Capacity(kg) |Rate per km(LKR) |Avg Speed(km/h) |Fuel Efficiency(km/l) |\n");
    printf("|-----------------------------------------------------------------------------------|\n");
    printf("|   %s     |    %d     |      %.2f      |     %.2f      |       %.2f          |\n",type[0],capacity[0],ratePerKm[0],avgSpeed[0],fuelEff[0]);
    printf("|-----------------------------------------------------------------------------------|\n");
    printf("|   %s   |    %d     |      %.2f      |     %.2f      |       %.2f           |\n",type[1],capacity[1],ratePerKm[1],avgSpeed[1],fuelEff[1]);
    printf("|-----------------------------------------------------------------------------------|\n");
    printf("|   %s   |    %d    |      %.2f      |     %.2f      |       %.2f           |\n",type[2],capacity[2],ratePerKm[2],avgSpeed[2],fuelEff[2]);
    printf("|-----------------------------------------------------------------------------------|\n");
}
void deliveryRequest(char city[MAX_CITIES][50], int count, int capacity[3], char type[3][20],int deliverySrc[MAX_DEL],int deliveryDes[MAX_DEL],float deliveryWei[MAX_DEL],int deliveryVehicle[MAX_DEL],int *deliveryCount)
{
    int option=0;
    if (*deliveryCount >= MAX_DEL)
    {
        printf("Maximum delivery records reached (%d). Cannot add more.\n", MAX_DEL);
        return;
    }
    printf("\nCities\n");
     for (int i = 0; i < count; i++)
        {
            printf("%d. %s\n", i + 1, city[i]);
        }
    do
    {
        printf("Enter the source city index:");
        scanf("%d",&deliverySrc[*deliveryCount]);
        printf("Enter the destination city index:");
        scanf("%d",&deliveryDes[*deliveryCount]);
        printf("Enter the weight of the cargo:");
        scanf("%f",&deliveryWei[*deliveryCount]);
        printf("\n1.Van\n2.Truck\n3.Lorry\n\n");
        printf("Enter the vehicle Type:");
        scanf("%d",&deliveryVehicle[*deliveryCount]);
        if(deliverySrc[*deliveryCount] == deliveryDes[*deliveryCount])
        {
            printf("Enter two different cities\n\n");

        }
        else if (deliveryVehicle[*deliveryCount] == 1 && (deliveryWei[*deliveryCount] > 1000 || deliveryWei[*deliveryCount] <= 0))
        {
                printf("Weight capacity of the van is 1000kg\n\n");

        }
         else if (deliveryVehicle[*deliveryCount] == 2 && (deliveryWei[*deliveryCount] > 5000 || deliveryWei[*deliveryCount] <= 0))
        {
                printf("Weight capacity of the truck is 5000kg\n\n");

        }
         else if (deliveryVehicle[*deliveryCount] == 3 && (deliveryWei[*deliveryCount] > 10000 || deliveryWei[*deliveryCount] <= 0))
        {

                printf("Weight capacity of the lorry is 10000kg\n\n");

        }
        else if(deliveryVehicle[*deliveryCount]>3 || deliveryVehicle[*deliveryCount]<1)
        {
            printf("Invalid vehicle Type\n\n");
        }
        else
        {
            printf("\nDelivery Request Accepted!\n");
            printf("From: %s\n", city[deliverySrc[*deliveryCount] - 1]);
            printf("To: %s\n", city[deliveryDes[*deliveryCount] - 1]);
            printf("Weight: %.2f kg\n", deliveryWei[*deliveryCount]);
            printf("Vehicle: %s\n\n", type[deliveryVehicle[*deliveryCount] - 1]);
            (*deliveryCount)++;
            break;
        }
        printf("To exit the loop enter 1");
        scanf("%d",&option);
    }while(option!=1);
}

void calcCTF(float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50], int count,int capacity[3], float ratePerKm[3], float avgSpeed[3], float fuelEff[3], char type[3][20],int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL], float deliveryWei[MAX_DEL],int deliveryVehicle[MAX_DEL], float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL], float profit[MAX_DEL], float customerCharge[MAX_DEL],int *deliveryCount,float totalCost[MAX_DEL])
{
    if(*deliveryCount == 0)
    {
        printf("No deliveries to calculate.\n");
        return;
    }
     for(int i = 0; i < *deliveryCount; i++)
     {
        int src = deliverySrc[i] - 1;
        int des = deliveryDes[i] - 1;
        int vType = deliveryVehicle[i] - 1;
        float weight = deliveryWei[i];
        float dist = distance[src][des];

        //a.Delivery Cost
        deliveryCost[i] = dist * ratePerKm[vType] * (1 + weight / 10000);

        //b.Delivery Time hours
        deliveryTime[i] = dist / avgSpeed[vType];

        //c.Fuel Consumption
        fuelUsed[i] = dist / fuelEff[vType];

        //d.Fuel Cost
        fuelCost[i] = fuelUsed[i] * FUEL_PRICE;

        //e,Total Operational Cost
        totalCost[i]= deliveryCost[i] + fuelCost[i];

        //f.Profit
        profit[i] = deliveryCost[i] * 0.25;

        //h.Final Charge to Customer
        customerCharge[i] = totalCost[i] + profit[i];
     }
}
void deliveryRecords(float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50], int count,int capacity[3], float ratePerKm[3], float avgSpeed[3], float fuelEff[3], char type[3][20],int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL], float deliveryWei[MAX_DEL],int deliveryVehicle[MAX_DEL], float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL], float profit[MAX_DEL], float customerCharge[MAX_DEL],int deliveryCount,float totalCost[MAX_DEL])
{
    calcCTF(distance,city,count,capacity,ratePerKm,avgSpeed,fuelEff,type,deliverySrc,deliveryDes,deliveryWei,deliveryVehicle,deliveryCost,deliveryTime,fuelUsed,fuelCost,profit,customerCharge,deliveryCount,totalCost);
    for(int i=0;i<deliveryCount;i++)
    {
            int src = deliverySrc[i] - 1;
            int des = deliveryDes[i] - 1;
            int vType = deliveryVehicle[i] - 1;
            float weight = deliveryWei[i];
            float dist = distance[src][des];
            printf("====================================================\n");
            printf("\nDelivery %d:\n", i + 1);
            printf("From: %s\n", city[src]);
            printf("To: %s\n", city[des]);
            printf("Vehicle: %s\n", type[vType]);
            printf("Distance: %.2f km\n", dist);
            printf("Weight: %.2f kg\n", weight);
            printf("Delivery Cost: Rs.%.2f \n", deliveryCost[i]);
            printf("Delivery Time: %.2f hours\n", deliveryTime[i]);
            printf("Fuel Used: %.2f liters\n", fuelUsed[i]);
            printf("Fuel Cost: Rs.%.2f \n", fuelCost[i]);
            printf("Profit: Rs.%.2f \n", profit[i]);
            printf("Customer Charge: Rs.%.2f \n", customerCharge[i]);
            printf("====================================================\n\n");
    }
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
