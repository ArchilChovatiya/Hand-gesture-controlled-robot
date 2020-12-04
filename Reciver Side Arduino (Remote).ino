#include <VirtualWire.h>  //Library Required

int RX_PIN = 7;// Tell Arduino on which pin you would like to receive data NOTE should be a PWM Pin
int RX_ID = 3;// Recever ID address 
int TX_ID;
int M11=3;
int M12=4;
int M21=5;
int M22=6;
int M31=8;
int M32=9;
int M41=10;
int M42=11;
int a=25;
typedef struct roverRemoteData //Data Structure 
{
int    TX_ID;      // Initialize a storage place for the incoming TX ID  
int    Sensor1Data;// Initialize a storage place for the first integar that you wish to Receive 
int    Sensor2Data;
};

void setup() {
              Serial.begin(9600);// Begin Serial port at a Buad speed of 9600bps 
              pinMode(M11,OUTPUT);
              pinMode(M12,OUTPUT);
              pinMode(M21,OUTPUT);
              pinMode(M22,OUTPUT);
              pinMode(M31,OUTPUT);
              pinMode(M32,OUTPUT);
              pinMode(M41,OUTPUT);
              pinMode(M42,OUTPUT);
              vw_setup(2000);// Setup and Begin communication over the radios at 2000bps( MIN Speed is 1000bps MAX 4000bps)
              vw_set_rx_pin(RX_PIN);// Set RX Pin 
              vw_rx_start(); 
                   
              }  
void loop()
{
      struct roverRemoteData receivedData;
      uint8_t rcvdSize = sizeof(receivedData);//Incoming data size 
      vw_wait_rx();// Start to Receive data now 

if (vw_get_message((uint8_t *)&receivedData, &rcvdSize)) // Check if data is available 
{
  if (receivedData.TX_ID == RX_ID) //Check if the radio signal recieved matches the ID of the Reciever
    { 
      // If data was Recieved print it to the serial monitor.
     
         Serial.print("TX ID:");
         Serial.print(TX_ID);
         Serial.print("           Sensor1Data:");
         Serial.print(receivedData.Sensor1Data);
         Serial.print("           Sensor2Data:");
         Serial.println(receivedData.Sensor2Data);
        if(receivedData.Sensor1Data >=a && (receivedData.Sensor2Data >= -a &&  receivedData.Sensor2Data <= a))
        {
          digitalWrite(M11,HIGH);
          digitalWrite(M12,LOW);
          digitalWrite(M21,HIGH);
          digitalWrite(M22,LOW);
          digitalWrite(M31,HIGH);
          digitalWrite(M32,LOW);
          digitalWrite(M41,HIGH);
          digitalWrite(M42,LOW);
        }
        else if(receivedData.Sensor1Data <=-a && (receivedData.Sensor2Data >= -a &&  receivedData.Sensor2Data <= a))
        {
          digitalWrite(M11,LOW);
          digitalWrite(M12,HIGH);
          digitalWrite(M21,LOW);
          digitalWrite(M22,HIGH);
          digitalWrite(M31,LOW);
          digitalWrite(M32,HIGH);
          digitalWrite(M41,LOW);
          digitalWrite(M42,HIGH);
        }
        else if(receivedData.Sensor2Data >=a && (receivedData.Sensor1Data >= -a &&  receivedData.Sensor1Data <= a))
        {
          digitalWrite(M11,LOW);
          digitalWrite(M12,HIGH);
          digitalWrite(M21,HIGH);
          digitalWrite(M22,LOW);
          digitalWrite(M31,HIGH);
          digitalWrite(M32,LOW);
          digitalWrite(M41,LOW);
          digitalWrite(M42,HIGH);
        }
        else if (receivedData.Sensor2Data <=-a && (receivedData.Sensor1Data >= -a &&  receivedData.Sensor1Data <= a))
        {
          digitalWrite(M11,HIGH);
          digitalWrite(M12,LOW);
          digitalWrite(M21,LOW);
          digitalWrite(M22,HIGH);
          digitalWrite(M41,HIGH);
          digitalWrite(M42,LOW);
          digitalWrite(M31,LOW);
          digitalWrite(M32,HIGH);
        }
        else if(receivedData.Sensor1Data >=a && (receivedData.Sensor2Data <= -a ))
        {
          
          digitalWrite(M11,HIGH);
          digitalWrite(M12,LOW);
          digitalWrite(M21,HIGH);
          digitalWrite(M22,LOW);
          digitalWrite(M31,LOW);
          digitalWrite(M32,HIGH);
          digitalWrite(M41,HIGH);
          digitalWrite(M42,LOW);
         
        }
        else if(receivedData.Sensor1Data >=a && (receivedData.Sensor2Data >= a ))
        {
          digitalWrite(M11,HIGH);
          digitalWrite(M12,LOW);
          digitalWrite(M21,HIGH);
          digitalWrite(M22,LOW);
          digitalWrite(M41,LOW);
          digitalWrite(M42,HIGH);
          digitalWrite(M31,HIGH);
          digitalWrite(M32,LOW);
         
        }
        else if(receivedData.Sensor1Data <=-a && (receivedData.Sensor2Data <= -a ))
        {
          digitalWrite(M11,LOW);
          digitalWrite(M12,HIGH);
          digitalWrite(M21,LOW);
          digitalWrite(M22,HIGH);
          digitalWrite(M41,LOW);
          digitalWrite(M42,HIGH);
          digitalWrite(M31,HIGH);
          digitalWrite(M32,LOW);
         
        }
        else if(receivedData.Sensor1Data <=-a && (receivedData.Sensor2Data >= a ))
        {
          digitalWrite(M11,LOW);
          digitalWrite(M12,HIGH);
          digitalWrite(M21,LOW);
          digitalWrite(M22,HIGH);
          digitalWrite(M41,HIGH);
          digitalWrite(M42,LOW);
          digitalWrite(M31,LOW);
          digitalWrite(M32,HIGH);
        }
       else
       {
          digitalWrite(M11,LOW);
          digitalWrite(M12,LOW);
          digitalWrite(M21,LOW);
          digitalWrite(M22,LOW);
          digitalWrite(M31,LOW);
          digitalWrite(M32,LOW);
          digitalWrite(M41,LOW);
          digitalWrite(M42,LOW);
       }
        } 
      else
        { 
Serial.println(" ID Does not match waiting for next transmission ");
        } 
      } 
    }

