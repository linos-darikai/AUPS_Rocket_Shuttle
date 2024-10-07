//Libraries for MPU6050
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>// for the I2C connection of the MPU6050(mpu-->microcontroller)
//Libraries for Servo Motor
#include <Servo.h>
// BMP Libraries
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <GY6050.h>

#include <TinyGPS++.h>
#include <SoftwareSerial.h>



static const int RXPin = 2, TXPin = 1;
static const uint32_t GPSBaud = 9600;


// The TinyGPS++ object
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);
//Creating an object for MPU6050
Adafruit_MPU6050 mpu;
GY6050 gyro(0x68);
// creating an object for the servo motor 
Servo servo4;
Servo servo2;
Servo servo3;
Servo hatch_servo;//hatch deployement servo
Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();


float altitude, current_altitude;
float sealevel = 1025.8;
int x1,y1,z1;
//rotating angles variables
int X, Y, Z;
int pos = 0;
int i;




void setup() 
{
  Serial.begin(9600);
  Serial.println("Working");
  ss.begin(GPSBaud);
  Serial.begin(9600);
  bmp.begin(0x76);
  
  Serial.println("Hi");
  gyro.initialisation();
  hatch_servo.attach(3);  // attaches the servo on pin 9 to the servo object
  servo2.attach(10);  // attaches the servo on pin 9 to the servo object
  servo3.attach(5);  // attaches the servo on pin 9 to the servo object
  servo4.attach(6);
  //Enabling I2C communication for MPU6050, OLED, AND ANY other sensor that uses I2C
  while(!Serial)
  {
    delay(10);
    yield(); // pause for Zero, Learnado, etc until Serial console opens
  }
  Wire.begin();
altitude = bmp.readAltitude(sealevel);
sensors_event_t a, g, temp;//getting data from MPU6050 accelaration, gravity, temperature.
mpu.getEvent(&a, &g, &temp);
servo2.write(0);
servo3.write(0);
servo4.write(0);
hatch_servo.write(90);


} 

void loop()
{

   sensors_event_t a, g, temp;//getting data from MPU6050 accelaration, gravity, temperature.
  mpu.getEvent(&a, &g, &temp);
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");
  Serial.println("");
  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);
  altitude = bmp.readAltitude(sealevel);
  Serial.print(F("Temperature = "));
  Serial.print(temp_event.temperature);
  Serial.println(" *C");

  Serial.print(F("Pressure = "));
  Serial.print(pressure_event.pressure);
  Serial.println(" hPa");

  Serial.print(F("Altitude =  "));
  Serial.print(altitude);
  Serial.println(" m");

  Serial.println();
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      // Latitude in degrees (double)
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);      
      // Longitude in degrees (double)
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6); 
       
      // Raw latitude in whole degrees
      Serial.print("Raw latitude = "); 
      Serial.print(gps.location.rawLat().negative ? "-" : "+");
      Serial.println(gps.location.rawLat().deg); 
      // ... and billionths (u16/u32)
      Serial.println(gps.location.rawLat().billionths);
      
      // Raw longitude in whole degrees
      Serial.print("Raw longitude = "); 
      Serial.print(gps.location.rawLng().negative ? "-" : "+");
      Serial.println(gps.location.rawLng().deg); 
      // ... and billionths (u16/u32)
      Serial.println(gps.location.rawLng().billionths);

      // Raw date in DDMMYY format (u32)
      Serial.print("Raw date DDMMYY = ");
      Serial.println(gps.date.value()); 

      // Year (2000+) (u16)
      Serial.print("Year = "); 
      Serial.println(gps.date.year()); 
      // Month (1-12) (u8)
      Serial.print("Month = "); 
      Serial.println(gps.date.month()); 
      // Day (1-31) (u8)
      Serial.print("Day = "); 
      Serial.println(gps.date.day()); 

      // Raw time in HHMMSSCC format (u32)
      Serial.print("Raw time in HHMMSSCC = "); 
      Serial.println(gps.time.value()); 

      // Hour (0-23) (u8)
      Serial.print("Hour = "); 
      Serial.println(gps.time.hour()); 
      // Minute (0-59) (u8)
      Serial.print("Minute = "); 
      Serial.println(gps.time.minute()); 
      // Second (0-59) (u8)
      Serial.print("Second = "); 
      Serial.println(gps.time.second()); 
      // 100ths of a second (0-99) (u8)
      Serial.print("Centisecond = "); 
      Serial.println(gps.time.centisecond()); 

      // Raw speed in 100ths of a knot (i32)
      Serial.print("Raw speed in 100ths/knot = ");
      Serial.println(gps.speed.value()); 
      // Speed in knots (double)
      Serial.print("Speed in knots/h = ");
      Serial.println(gps.speed.knots()); 
      // Speed in miles per hour (double)
      Serial.print("Speed in miles/h = ");
      Serial.println(gps.speed.mph()); 
      // Speed in meters per second (double)
      Serial.print("Speed in m/s = ");
      Serial.println(gps.speed.mps()); 
      // Speed in kilometers per hour (double)
      Serial.print("Speed in km/h = "); 
      Serial.println(gps.speed.kmph()); 

      // Raw course in 100ths of a degree (i32)
      Serial.print("Raw course in degrees = "); 
      Serial.println(gps.course.value()); 
      // Course in degrees (double)
      Serial.print("Course in degrees = "); 
      Serial.println(gps.course.deg()); 

      // Raw altitude in centimeters (i32)
      Serial.print("Raw altitude in centimeters = "); 
      Serial.println(gps.altitude.value()); 
      // Altitude in meters (double)
      Serial.print("Altitude in meters = "); 
      Serial.println(gps.altitude.meters()); 
      // Altitude in miles (double)
      Serial.print("Altitude in miles = "); 
      Serial.println(gps.altitude.miles()); 
      // Altitude in kilometers (double)
      Serial.print("Altitude in kilometers = "); 
      Serial.println(gps.altitude.kilometers()); 
      // Altitude in feet (double)
      Serial.print("Altitude in feet = "); 
      Serial.println(gps.altitude.feet()); 

      // Number of satellites in use (u32)
      Serial.print("Number os satellites in use = "); 
      Serial.println(gps.satellites.value()); 

      // Horizontal Dim. of Precision (100ths-i32)
      Serial.print("HDOP = "); 
      Serial.println(gps.hdop.value()); 
    }
  }
  
  current_altitude = bmp.readAltitude(sealevel);
  rocketMovement();// the control system for the rocket
  // values that need to be seen in the 
  release_paraload();//release system of parachute and load



 
  
}

void rocketMovement()
{
  X = map(gyro.refresh('A','X'), -90, 90, 0, 45);
  Y = map(gyro.refresh('A','Y'), -90, 90, 0, 45);
  Z = map(gyro.refresh('A','Z'), -90, 90, 0, 45);
 
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  x1 = a.acceleration.x;
  //Serial.println(x1);
  y1 = a.acceleration.y;
  //Serial.println(y1);
  z1 = a.acceleration.z;
  //Serial.println(z1);
servo2.write(0);
servo3.write(0);
servo4.write(0);
 
if (x1 < 10 && x1> 0 && y1 < 4 && y1 > -4){    //זה טוב
  Serial.println("up");
   int value1 = map(x1,  0, 10, 0, -45);
   for(int i = value1; i>0; i= i-3)
   {
    servo3.write(value1);
   }
   
   int value2 = map(x1,  0, 10, 0, -45);
   for(int i = value2; i>0; i=i-3)
   {
    servo4.write(value1);
   }
   
   
   Serial.print(value2);
  }
else if (x1 > -10 && x1 < 0 && y1 < 4 && y1 > -4){
  Serial.println("down");
  int value3 = map(x1,  -10, 0,0, 45);
  for(int i = value3; i>0; i=i-3)
   {
    servo2.write(value3);
  
   }
   
  int value4 = map(x1,  -10, 0, 0, 45);
   for(int i = value4; i>0; i=i-3)
   {
    servo3.write(value4);
   }
   
  Serial.print(value4);
  }

if (y1 < 10 && y1 > 0 && x1 < 4 && x1 > -4){ //זה טוב 
  Serial.println("Right");
  int value5 = map(y1,  0, 10, 0, -45);
  for(int i = value5; i>0; i=i-3)
   {
    servo3.write(value5);
    delay(100);
   }
   
  int value6 = map(y1,  0, 10, 0, -45);
  for(int i = value6; i>0; i=i-3)
   {
    servo2.write(value6);
    delay(100);
   }
   
  Serial.print(value6);
  }
else if (y1 > -10 && y1 < 0  && x1 < 4 && x1 > -4){
  Serial.println("left");
  int value7 = map(y1,  -10, 0, 0, 45);
  for(int i = value7; i>0; i=i-3)
   {
    servo2.write(value7);
    delay(100);
   }
   
  int value8 = map(y1,  -10, 0, 0, 45);
  for(int i = value8; i>0; i=i-3)
   {
    servo3.write(value8);
    delay(100);
   }
   
  Serial.print(value8);
  }
  
}

void printValues()
{
  
  sensors_event_t a, g, temp;//getting data from MPU6050 accelaration, gravity, temperature.
  mpu.getEvent(&a, &g, &temp);
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");
  Serial.println("");
  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);
  altitude = bmp.readAltitude(sealevel);
  Serial.print(F("Temperature = "));
  Serial.print(temp_event.temperature);
  Serial.println(" *C");

  Serial.print(F("Pressure = "));
  Serial.print(pressure_event.pressure);
  Serial.println(" hPa");

  Serial.print(F("Altitude =  "));
  Serial.print(altitude);
  Serial.println(" m");

  Serial.println();

  
}



void release_paraload()
{
  //check if current altitude is greater than previous altitude
  if(current_altitude > altitude)
  {
    current_altitude= altitude;
    altitude = bmp.readAltitude(sealevel);
  }
  else if 
  {
    hatch_servo.write(0);
    Serial.println("OBJECT IS FALLING, PARACHUTE IS BEING RELEASED");
  }

}