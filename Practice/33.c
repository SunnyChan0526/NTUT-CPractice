#include <stdio.h>
#include <string.h>
#define TransportationText(TYPE) \
char name[20];\
double speed;\
double distance;\
int (*price)(struct TYPE*);\
double (*time)(struct TYPE*);

typedef struct car_s { 
    int oilPrice; 
    int parkPrice; 
    int tolls; 
    TransportationText(car_s); 
} car_t; 
int CarPrice(car_t* obj){ 
    double t;
    int d;
    t = obj->distance / 100;
    d = t / 1;
    if(t - d > 0){
        d++;
    } 
    return obj->oilPrice * 10 * d + obj->parkPrice + obj->tolls * d;
} 
double CarTime(car_t* obj){ 
    double time;
    time = obj->distance/obj->speed;
    return time;
} 
void CarCreate(car_t *obj){ 
    strcpy(obj->name, "Car"); 
    obj->speed = 100; 
    obj->price = CarPrice; 
    obj->time = CarTime; 
}

typedef struct bike_s { 
    int rentPrice; 
    TransportationText(bike_s); 
} bike_t; 
int BikePrice(bike_t* obj){ 
    return obj->rentPrice;
} 
double BikeTime(bike_t* obj){ 
    double time;
    time = obj->distance/obj->speed;
    return time;
} 
void BikeCreate(bike_t *obj){ 
    strcpy(obj->name, "Bike"); 
    obj->speed = 20; 
    obj->price = BikePrice; 
    obj->time = BikeTime; 
}

typedef struct intercityBus_s { 
    int basicPrice; 
    int additionPrice; 
    TransportationText(intercityBus_s); 
} intercityBus_t; 
int IntercityBusPrice(intercityBus_t* obj){ 
    double t;
    int d;
    t = (obj->distance - 100) / 50;
    d = t / 1;
    if(t - d > 0){
        d++;
    }
    return obj->basicPrice + obj->additionPrice * d;
} 
double IntercityBusTime(intercityBus_t* obj){ 
    double time;
    time = obj->distance/obj->speed;
    return time;
} 
void IntercityBusCreate(intercityBus_t *obj){ 
    strcpy(obj->name, "IntercityBus"); 
    obj->speed = 75; 
    obj->price = IntercityBusPrice; 
    obj->time = IntercityBusTime; 
}

typedef struct scooter_s { 
    int oilPrice; 
    TransportationText(scooter_s); 
} scooter_t; 
int ScooterPrice(scooter_t* obj){ 
    double t;
    int d;
    t = obj->distance / 100;
    d = t / 1;
    if(t - d > 0){
        d++;
    }
    return obj->oilPrice * 4 * d;
} 
double ScooterTime(scooter_t* obj){ 
    double time;
    time = obj->distance/obj->speed;
    return time;
} 
void ScooterCreate(scooter_t *obj){ 
    strcpy(obj->name, "Scooter"); 
    obj->speed = 50; 
    obj->price = ScooterPrice; 
    obj->time = ScooterTime; 
}

int main(){
    int i, j;
    int x, y, price[4];
    double time[4], min = 0;
    char name[4][15] = {"Car", "Bike", "Intercity Bus", "Scooter"};
    car_t car;
    CarCreate(&car);
    bike_t bike;
    BikeCreate(&bike);
    intercityBus_t intercityBus;
    IntercityBusCreate(&intercityBus);
    scooter_t scooter;
    ScooterCreate(&scooter);

    scanf("%d %d", &x, &y);
    getchar();
    scanf("%d %d %d", &car.oilPrice, &car.parkPrice, &car.tolls);
    getchar();
    scanf("%d", &bike.rentPrice);
    getchar();
    scanf("%d %d", &intercityBus.basicPrice, &intercityBus.additionPrice);
    getchar();
    scanf("%d", &scooter.oilPrice);

    car.distance = x;
    bike.distance = x;
    intercityBus.distance = x;
    scooter.distance = x;

    // printf("price:%d %d %d %d\n", car.price(&car), bike.price(&bike), intercityBus.price(&intercityBus), scooter.price(&scooter));
    // printf("time:%lf %lf %lf %lf\n", car.time(&car), bike.time(&bike), intercityBus.time(&intercityBus), scooter.time(&scooter));

    price[0] = car.price(&car);
    price[1] = bike.price(&bike);
    price[2] = intercityBus.price(&intercityBus);
    price[3] = scooter.price(&scooter);

    time[0] = car.time(&car);
    time[1] = bike.time(&bike);
    time[2] = intercityBus.time(&intercityBus);
    time[3] = scooter.time(&scooter);

    for(i=0; i<4; i++){
        if(price[i] <= y){
            min = time[i];
            break;
        }
    }
    for(j=i+1; j<4; j++){
        if(price[j] <= y && time[j] < min){
            min = time[j];
        }
    }
    if(min == 0){
        printf("No Transportation");
    }
    else{
        for(i=0; i<4; i++){
            if(min == time[i]){
                printf("%s\n", name[i]);
                printf("%d\n", price[i]);
                printf("%.2lf", time[i]);
            }
        }
    }
    

    
    return 0;
}