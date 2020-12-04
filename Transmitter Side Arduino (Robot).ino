int TX_ID = 3;
int TX_PIN = 7;
#include <MPU6050_tockn.h>
#include <Wire.h>
#include<VirtualWire.h>
int X,Y;
typedef struct roverRemoteData
{
int    TX_ID;      
int    Sensor1Data;
int    Sensor2Data;
};
MPU6050 mpu6050(Wire);

void setup() {
  Wire.begin();
  mpu6050.begin();
  vw_setup(2000);
  vw_set_tx_pin(TX_PIN);
  mpu6050.calcGyroOffsets(true);
  Serial.begin(9600);
}

void loop() {
  struct roverRemoteData payload;
  
  mpu6050.update();
  Serial.print("angleX : ");
  X=mpu6050.getAngleX();
  Serial.print(X);
  Serial.print("\tangleY : ");
  Y=mpu6050.getAngleY();
  Serial.println(Y);
  payload.TX_ID = TX_ID; 
  payload.Sensor1Data =X;
  payload.Sensor2Data =Y;
  vw_send((uint8_t *)&payload, sizeof(payload)); 
  vw_wait_tx();
  
}
