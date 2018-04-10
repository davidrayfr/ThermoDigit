
/***************************************************************************
  This is a library for the BME280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
// #include <SPI.h> // Remove not used for I2C
#include <Adafruit_Sensor.h>
#include <DR_BME280.h> // Modification on Adafruit_BME280.h with SDA on GPIO0 & SCL GPIO2

/*#define BME_SCK 13  // Only for SPI
#define BME_MISO 12 // Only for SPI
#define BME_MOSI 11 // Only for SPI
#define BME_CS 10 // Only for SPI*/

#define SEALEVELPRESSURE_HPA (1013.25)

#define SDA_PIN 0 // D3 on NodeMCU
#define SCL_PIN 2 // D4 on NodeMCU
#define BME280_ADDRESS (0x76)
#define OLED_address  (0x3c)


DR_BME280 bme;
char buffer[16];                // Buffer pour convertir en chaine

static void StartUp_OLED();
static void clear_display();
static void sendStrXY( char *string, int X, int Y);

void i2c_Scanner()
{
  byte error, address;
  int nDevices;
  Serial.println("\nI2C Scanner");
  Serial.println("\nI2C looking for I2C components with");
  Serial.println("\nSDA on GPIO0 & SCL on GPIO2");
  Serial.println("Scanning...");
  nDevices = 0;
  while (nDevices == 0){
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("\nI2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknow error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found");
    else {
    Serial.println("Number of Device found : ");
    Serial.println(nDevices);
    }
  delay (5000);
  }
  
}
 
// I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);

void setup() {
  Serial.begin(9600);
  Wire.begin(SDA_PIN,SCL_PIN);
  
  /* Scanner i2c */
  Serial.println("Scanner I2C");
  i2c_Scanner();

  /* Démarrage de l'écran */
  Serial.println("Démarrage de l écran");
  StartUp_OLED(); 
  clear_display();
  sendStrXY(" ARDUINAULT TEAM ", 0, 1); // 16 caractères par ligne
  sendStrXY(" OLED + ESP-12 + BME280 ", 2, 1);
  sendStrXY(" DEMARRAGE....  ", 4, 1);
  
  Serial.println(F("BME280 test with I2 on ESP8266"));
  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);

  delay(2000);
  Serial.println("Fin du setup");  
  }
}

void loop() {
    String Temperature, Pressure, Altitude, Humidity;
    /*Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();*/

    Temperature= "Temp " + String(bme.readTemperature()) + " °C";
    Humidity = "Humi " + String(bme.readHumidity()) + " %";
    Altitude = "Alti " + String(bme.readAltitude(SEALEVELPRESSURE_HPA))+ " m";
    Pressure = "Pres " + String(bme.readPressure() / 100.0F)+"hPa";

    /*Affichage sur liaison Serie */
    Serial.println(Temperature);
    Serial.println(Humidity);
    Serial.println(Altitude);
    Serial.println(Pressure);
 
    /* Affichage sur Ecran OLED */
    clear_display();
    // On actualise l'affichage sur l'écran OLED
    sendStrXY("ESP8266*BME280", 0, 1);
    Temperature.toCharArray(buffer,16);    
    sendStrXY(buffer, 2, 1);
    Humidity.toCharArray(buffer,16);
    sendStrXY(buffer, 3, 1);
    Altitude.toCharArray(buffer,16);
    sendStrXY(buffer, 5, 1);
    Pressure.toCharArray(buffer,16);
    sendStrXY(buffer, 6, 1);
   delay(5000);
}

