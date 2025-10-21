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
void deliveryRequest(char city[MAX_CITIES][50], int count, int capacity[3], char type[3][20],int deliverySrc[MAX_DEL],
                     int deliveryDes[MAX_DEL],float deliveryWei[MAX_DEL],int deliveryVehicle[MAX_DEL],int *deliveryCount);
void calcCTF(float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50], int count,int capacity[3], float ratePerKm[3],
             float avgSpeed[3], float fuelEff[3], char type[3][20],int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL],
             float deliveryWei[MAX_DEL],int deliveryVehicle[MAX_DEL], float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],
             float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL], float profit[MAX_DEL], float customerCharge[MAX_DEL],int deliveryCount,
             float totalCost[MAX_DEL],int *indicator);
void deliveryRecords(float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50], int count,int capacity[3], float ratePerKm[3],
                     float avgSpeed[3], float fuelEff[3], char type[3][20],int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL],
                     float deliveryWei[MAX_DEL], int deliveryVehicle[MAX_DEL],float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],
                     float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL],float profit[MAX_DEL], float customerCharge[MAX_DEL],
                     int deliveryCount, float totalCost[MAX_DEL],int *indicator);
void leastDistance(float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50], int count,int srcCity,int desCity);
void performanceReport(int deliveryCount, int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL],
                       float deliveryTime[MAX_DEL], float customerCharge[MAX_DEL], float profit[MAX_DEL],
                       float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50]);
void saveRoutes(char city[MAX_CITIES][50], float distance[MAX_CITIES][MAX_CITIES], int count);
void loadRoutes(char city[MAX_CITIES][50], float distance[MAX_CITIES][MAX_CITIES], int *count);
void saveDeliveries(int deliveryCount, int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL],
                    float deliveryWei[MAX_DEL], int deliveryVehicle[MAX_DEL],
                    float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],
                    float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL],
                    float profit[MAX_DEL], float customerCharge[MAX_DEL]);
void loadDeliveries(int *deliveryCount, int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL],
                    float deliveryWei[MAX_DEL], int deliveryVehicle[MAX_DEL],
                    float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],
                    float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL],
                    float profit[MAX_DEL], float customerCharge[MAX_DEL]);
int main()
{
    int choice;
    int count=0;
    char city[MAX_CITIES][50];
    float distance[MAX_CITIES][MAX_CITIES] = {0};
    char type[3][20] = {"Van", "Truck", "Lorry"};
    int capacity[3]={1000,5000,10000};
    float ratePerKm[3]={30,40,80};
    float avgSpeed[3]={60,50,45};
    float fuelEff[3]={12,6,4};

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
    int deliveryCount = 0,srcCity,desCity;
    int indicator=0;

    loadRoutes(city, distance, &count);
    loadDeliveries(&deliveryCount, deliverySrc, deliveryDes, deliveryWei, deliveryVehicle,
               deliveryCost, deliveryTime, fuelUsed, fuelCost, profit, customerCharge);
    printf("Data Loaded Successfully!\n");


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
        printf("8.Report\n");
        printf("9.Exit\n\n");
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
            calcCTF(distance,city,count,capacity,ratePerKm,avgSpeed,fuelEff,type,deliverySrc,deliveryDes,deliveryWei,deliveryVehicle,
                    deliveryCost,deliveryTime,fuelUsed,fuelCost,profit,customerCharge,deliveryCount,totalCost, &indicator);

            break;
        case 6:
            deliveryRecords( distance, city, count, capacity,  ratePerKm,  avgSpeed, fuelEff,  type,deliverySrc, deliveryDes,
                            deliveryWei,  deliveryVehicle,deliveryCost, deliveryTime,  fuelUsed, fuelCost,profit, customerCharge,
                            deliveryCount, totalCost, &indicator);
            break;
        case 7:
            printf("Enter the source city index:");
            scanf("%d",&srcCity);
            printf("Enter the destination city index:");
            scanf("%d",&desCity);

            srcCity--;
            desCity--;
            leastDistance(distance,city,count,srcCity,desCity);
            break;
        case 8:
            performanceReport(deliveryCount,deliverySrc,deliveryDes,deliveryTime,customerCharge,profit,distance,city);
            break;
        case 9:
            break;
        default:
            printf("Invalid option\n");
        }
    }while(choice!=9);

    saveRoutes(city, distance, count);
    saveDeliveries(deliveryCount, deliverySrc, deliveryDes, deliveryWei, deliveryVehicle,
               deliveryCost, deliveryTime, fuelUsed, fuelCost, profit, customerCharge);
    printf("Data Saved Successfully!\n");

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
void deliveryRequest(char city[MAX_CITIES][50], int count, int capacity[3], char type[3][20],int deliverySrc[MAX_DEL],
                     int deliveryDes[MAX_DEL],float deliveryWei[MAX_DEL],int deliveryVehicle[MAX_DEL],int *deliveryCount)
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
        if(deliverySrc[*deliveryCount] < 1 || deliverySrc[*deliveryCount] > count ||deliveryDes[*deliveryCount] < 1 || deliveryDes[*deliveryCount] > count)
        {
            printf("Invalid city index.\n");
            continue;
        }

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

void calcCTF(float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50], int count,int capacity[3], float ratePerKm[3],
             float avgSpeed[3], float fuelEff[3], char type[3][20],int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL],
             float deliveryWei[MAX_DEL],int deliveryVehicle[MAX_DEL], float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],
             float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL], float profit[MAX_DEL], float customerCharge[MAX_DEL],int deliveryCount,
             float totalCost[MAX_DEL],int *indicator)
{
    if(*indicator==0)
    {
        printf("\nCities\n");
        for(int i=0;i<count;i++)
        {
            printf("%d.%s\n",i+1,city[i]);
        }
    }
    if(deliveryCount == 0)
    {
        printf("No deliveries to calculate.\n");
        return;
    }
     for(int i = 0; i < deliveryCount; i++)
     {
        int src = deliverySrc[i] - 1;
        int des = deliveryDes[i] - 1;
        int vType = deliveryVehicle[i] - 1;
        float weight = deliveryWei[i];

        if(src < 0 || src >= count || des < 0 || des >= count)
        {
            printf("Error: Invalid city index for delivery %d\n", i + 1);
            continue;
        }
        float dist = distance[src][des];


        if(vType < 0 || vType >= 3)
        {
            printf("Error: Invalid vehicle type for delivery %d\n", i + 1);
            continue;
        }

        if(weight <= 0 || weight > capacity[vType])
        {
            printf("Error: Invalid weight for delivery %d with vehicle %s\n", i + 1, type[vType]);
            continue;
        }

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
        printf("Delivary %d sucessfully Calculated\n\n",i+1);

     }
}
void deliveryRecords(float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50], int count,int capacity[3], float ratePerKm[3],
                     float avgSpeed[3], float fuelEff[3], char type[3][20],int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL],
                     float deliveryWei[MAX_DEL], int deliveryVehicle[MAX_DEL],float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],
                     float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL],float profit[MAX_DEL], float customerCharge[MAX_DEL],
                     int deliveryCount, float totalCost[MAX_DEL],int *indicator)
{
    *indicator=-1;
    calcCTF(distance, city,count,capacity,ratePerKm,avgSpeed,fuelEff,type,deliverySrc,deliveryDes,deliveryWei,deliveryVehicle,
            deliveryCost, deliveryTime,fuelUsed, fuelCost, profit, customerCharge,deliveryCount,totalCost,indicator);
    *indicator=0;
    for(int i=0; i<deliveryCount; i++)
    {
        int src = deliverySrc[i] - 1;
        int des = deliveryDes[i] - 1;
        int vType = deliveryVehicle[i] - 1;
        float weight = deliveryWei[i];
        if(src < 0 || src >= count || des < 0 || des >= count || vType < 0 || vType >= 3 || weight <= 0)
        {
            continue;
        }
        float dist = distance[src][des];

        printf("======================================================\n");
        printf("DELIVERY COST ESTIMATION\n");
        printf("------------------------------------------------------\n");
        printf("From: %s\n", city[src]);
        printf("To: %s\n", city[des]);
        leastDistance(distance, city, count,src,des);
        printf("Vehicle: %s\n", type[vType]);
        printf("Weight: %.2f kg\n", weight);
        printf("------------------------------------------------------\n");
        printf("Base Cost: %.2f x %.2f(1+%.2f/10000)=%.2f LKR\n", dist,ratePerKm[vType],weight,deliveryCost[i]);
        printf("Fuel Used: %.2f liters\n", fuelUsed[i]);
        printf("Fuel Cost: %.2f LKR\n", fuelCost[i]);
        printf("Operational Cost: %.2f LKR\n", totalCost[i]);
        printf("Profit: %.2f LKR\n", profit[i]);
        printf("Customer Charge: %.2f LKR\n", customerCharge[i]);
        printf("Estimated Time: %.2f hours\n", deliveryTime[i]);
        printf("======================================================\n\n");
    }
}

void leastDistance(float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50], int count,int srcCity,int desCity)
{

    if(count<2 || count>4)
    {
       printf("Error: This function only supports 2 to 4 cities.\n");
        return;
    }


        if(srcCity==desCity)
        {
            printf("Enter 2 different cities");
            return;
        }

        float minDis=distance[srcCity][desCity];
        int temp1=-1,temp2=-1;

        if(count==3)
        {
            for(int j=0;j<count;j++)
            {
                if(srcCity==j || desCity==j)
                {
                    continue;
                }
                float d=distance[srcCity][j]+distance[j][desCity];
                if(minDis>d)
                {
                    minDis=d;
                    temp1=j;
                }
            }
            if(temp1 != -1)
            {
                printf("Minimum Distance is from %s to %s to %s: %.2f\n", city[srcCity], city[temp1], city[desCity], minDis);
            }
            else
            {
                printf("Minimum Distance is from %s to %s: %.2f\n", city[srcCity], city[desCity], minDis);
            }

        }
        if(count==4)
        {
            for(int i=0;i<count;i++)
            {
                if(srcCity==i || desCity==i)
                {
                    continue;
                }
                float d=distance[srcCity][i]+distance[i][desCity];
                if(d<minDis)
                {
                    minDis=d;
                    temp1=i;
                    temp2=-1;

                }
            }

            for(int i=0;i<count;i++)
            {
                if(srcCity==i || desCity==i)
                {
                    continue;
                }
                for(int j=0;j<count;j++)
                {
                    if(j==srcCity || j==desCity || j==i)
                    {
                      continue;
                    }
                    float d=distance[srcCity][i]+ distance[i][j]+distance[j][desCity];
                    if(d<minDis)
                    {
                        minDis=d;
                        temp1=i;
                        temp2=j;
                    }
                }
            }

            if(temp1 == -1 && temp2 == -1)
            {
                printf("Minimum Distance is from %s to %s:%.2f\n",city[srcCity],city[desCity],minDis);
            }
            else if(temp2==-1)
            {
                printf("Minimum Distance is from %s to %s to %s:%.2f\n",city[srcCity],city[temp1],city[desCity],minDis);
            }
            else
            {
                printf("Minimum Distance is from %s to %s to %s to %s:%.2f\n",city[srcCity],city[temp1],city[temp2],city[desCity],minDis);
            }
        }
}

void performanceReport(int deliveryCount, int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL],
                       float deliveryTime[MAX_DEL], float customerCharge[MAX_DEL], float profit[MAX_DEL],
                       float distance[MAX_CITIES][MAX_CITIES], char city[MAX_CITIES][50])
{
    if(deliveryCount == 0)
    {
        printf("No deliveries completed yet.\n");
        return;
    }

    float totalDistance = 0, totalTime = 0, totalRevenue = 0, totalProfit = 0;
    float longRoute = -1, shortRoute = 9999;
    int longSrc=-1, longDes=-1, shortSrc=-1, shortDes=-1;

    for(int i=0; i<deliveryCount; i++)
    {
        int src = deliverySrc[i]-1;
        int des = deliveryDes[i]-1;

        float dist = distance[src][des];
        totalDistance += dist;
        totalTime += deliveryTime[i];
        totalRevenue += customerCharge[i];
        totalProfit += profit[i];

        if(dist > longRoute)
        {
            longRoute = dist;
            longSrc = src;
            longDes = des;
        }
        if(dist < shortRoute)
        {
            shortRoute = dist;
            shortSrc = src;
            shortDes = des;
        }
    }

    printf("\n==================== PERFORMANCE REPORT ====================\n");
    printf("Total Deliveries Completed : %d\n", deliveryCount);
    printf("Total Distance Covered     : %.2f km\n", totalDistance);
    printf("Average Delivery Time      : %.2f hours\n", totalTime/deliveryCount);
    printf("Total Revenue              : %.2f LKR\n", totalRevenue);
    printf("Total Profit               : %.2f LKR\n", totalProfit);
    printf("Longest Route Completed    : %s to %s (%.2f km)\n", city[longSrc], city[longDes], longRoute);
    printf("Shortest Route Completed   : %s to %s (%.2f km)\n", city[shortSrc], city[shortDes], shortRoute);
    printf("=============================================================\n\n");
}

void saveRoutes(char city[MAX_CITIES][50], float distance[MAX_CITIES][MAX_CITIES], int count)
{
    FILE *fp = fopen("routes.txt", "w");
    if(!fp)
    {
        return;
    }
    fprintf(fp, "%d\n", count);
    for(int i=0; i<count; i++)
    {
        fprintf(fp, "%s\n", city[i]);
    }
    for(int i=0; i<count; i++)
    {
        for(int j=0; j<count; j++)
        {
            fprintf(fp, "%.2f\n", distance[i][j]);
        }
    }
    fclose(fp);
}

void loadRoutes(char city[MAX_CITIES][50], float distance[MAX_CITIES][MAX_CITIES], int *count)
{
    FILE *fp = fopen("routes.txt", "r");
    if(!fp)
    {
         return;
    }
    fscanf(fp, "%d\n", count);
    for(int i=0; i<*count; i++)
     {
         fgets(city[i], 50, fp), city[i][strcspn(city[i], "\n")] = '\0';
     }
    for(int i=0; i<*count; i++)
      {
          for(int j=0; j<*count; j++)
           {
               fscanf(fp, "%f\n", &distance[i][j]);
           }
      }
    fclose(fp);
}
void saveDeliveries(int deliveryCount, int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL],
                    float deliveryWei[MAX_DEL], int deliveryVehicle[MAX_DEL],
                    float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],
                    float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL],
                    float profit[MAX_DEL], float customerCharge[MAX_DEL]) {
    FILE *fp = fopen("deliveries.txt", "w");
    if(!fp)
    {
        return;
    }
    fprintf(fp, "%d\n", deliveryCount);
    for(int i=0; i<deliveryCount; i++)
    {
        fprintf(fp, "%d %d %.2f %d %.2f %.2f %.2f %.2f %.2f %.2f\n",deliverySrc[i], deliveryDes[i], deliveryWei[i], deliveryVehicle[i],deliveryCost[i], deliveryTime[i], fuelUsed[i], fuelCost[i], profit[i], customerCharge[i]);
    }
    fclose(fp);
}

void loadDeliveries(int *deliveryCount, int deliverySrc[MAX_DEL], int deliveryDes[MAX_DEL],
                    float deliveryWei[MAX_DEL], int deliveryVehicle[MAX_DEL],
                    float deliveryCost[MAX_DEL], float deliveryTime[MAX_DEL],
                    float fuelUsed[MAX_DEL], float fuelCost[MAX_DEL],
                    float profit[MAX_DEL], float customerCharge[MAX_DEL]) {
    FILE *fp = fopen("deliveries.txt", "r");
    if(!fp)
        {
             return;
        }
    fscanf(fp, "%d\n", deliveryCount);
    for(int i=0; i<*deliveryCount; i++)
    {
        fscanf(fp, "%d %d %f %d %f %f %f %f %f %f\n",&deliverySrc[i], &deliveryDes[i], &deliveryWei[i], &deliveryVehicle[i],&deliveryCost[i], &deliveryTime[i], &fuelUsed[i], &fuelCost[i],&profit[i], &customerCharge[i]);
    }
    fclose(fp);
}
