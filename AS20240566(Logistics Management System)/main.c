#include <stdio.h>
#include <stdlib.h>

void cityManage();
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
    char city[30][50];
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
            cityManage();
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
        }
    }while(choice!=10);

    return 0;
}
void cityManage()
{

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
