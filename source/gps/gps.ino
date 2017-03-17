#include "string.h"
#include "ctype.h"
#include "SoftwareSerial.h"
#include "dGPS.h"
//Code added to set up LCD screen. Add library
#include <LiquidCrystal.h>

// Software serial TX & RX Pins for the GPS module
// Initiate the software serial connection

int ledPin = 13;                  // LED test pin
float desLat=0;                   //Destination Latitude filled by user in Serial Monitor Box
float desLon=0;                   //Destination Longitude filled by user in Serial Monitor Box
char fla[2];                      //flag (Y/N) whether to print checksum or not. Filled by user in Serial Monitor Box
char fla2[2];                     //flag (Y/N) whether to print Altitude, number of satellites used and HDOP. Filled by user in Serial Monitor Box
dGPS dgps = dGPS();               // Construct dGPS class

//Code added to set up LCD screen. Pins needed
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(ledPin, OUTPUT);       // Initialize LED pin
  Serial.end();                  // Close any previously established connections
  Serial.begin(9600);            // Serial output back to computer.  On.
  dgps.init();                   // Run initialization routine for dGPS.
  
  //Code added to set up LCD screen. Screen Size
  lcd.begin(16, 2);
  delay(1000);   
}

void loop() {
 
  dgps.update(desLat, desLon); // Code to update GPS coordinates
  
  lcd.setCursor(0, 0); // sets cursor on the first line
  lcd.print("Lat: ");
  lcd.print(dgps.Lat(), 6); //outputs gps latitude measurement to LCD screen
  
  lcd.setCursor(0, 1); // sets cursor on next line
  lcd.print("Lon: "); 
  lcd.print(dgps.Lon(), 6); //outputs gps longitude measurment to LCD screen
  
  //Serial.println(dgps.Lat(), 6); 
  //Serial.println(dgps.Lon(), 6);   

  delay(1000);

  /*Serial.print("Velocity: ");
  Serial.print(dgps.Vel(), 6);    // Velocity, in knots.
  Serial.println(" knots");
  
  Serial.print("Heading: ");
  Serial.print(dgps.Head(), 6);   // Heading, in degrees
  Serial.println(" degrees");
  Serial.println(""); */
}
