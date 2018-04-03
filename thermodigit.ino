// Use thermistor and write the result on the 4 digits screen

int aPin = 6;  //
int bPin = 7;  //      ____A____
int cPin = 8;  //     |        |
int dPin = 9;  //  F  |        |  B
int ePin = 10;  //     |        |
int fPin = 11;  //     |____G___|
int gPin = 12;  //     |        |
int GND1 = 2;  //     |        |
int GND2 = 3; //   E |        |   C
int GND3 = 4; //     |________|
int GND4 = 5; //          D
int hPin = 13; //                ° H
int num;       // not used
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;
int DTime = 4;
int AnalogPin = 1; // Analog Read for Thermistor
int temperature = 0;
int i;
void setup()
{
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT); 
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(hPin, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);
  Serial.begin(9600); //  Serial.begin(115200) for thermistor;
}
void loop()
{
  temperature = int(Thermistor(analogRead(AnalogPin))*100);
  Serial.println(temperature);  // display Celsius
  digitalWrite( GND1, HIGH);
  digitalWrite( GND2, HIGH);
  digitalWrite( GND3, HIGH);
  digitalWrite( GND4, HIGH);


  num=temperature;
    dig1 = num / 1000;
    num = num - (dig1 * 1000);
    dig2 = num / 100;
    num = num - (dig2 * 100);
    dig3 = num / 10;
    dig4 = num - (dig3 *10);
  
  for (i=1; i<5; i++){
  digitalWrite( GND4, LOW);    //digit 4
  pickNumber(dig4,0);
  delay(DTime);
  digitalWrite( GND4, HIGH);
 
  digitalWrite( GND3, LOW);    //digit 3
  pickNumber(dig3,0);
  delay(DTime);
  digitalWrite( GND3, HIGH);
 
  digitalWrite( GND2, LOW);   //digit 2
  pickNumber(dig2,1);
  delay(DTime);
  digitalWrite( GND2, HIGH);
 
  digitalWrite( GND1, LOW);   //digit 1
  pickNumber(dig1,0);
  delay(DTime);
  digitalWrite( GND1, HIGH);
  }
}
 
void pickNumber(int x,int point){
  if (point==1) digitalWrite( hPin, HIGH);
  else digitalWrite( hPin, LOW);
   switch(x){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     default: zero(); break;
   }
}

void pickLetter(char x){
  switch(x){
    case 'A': printA(); break;
    case 'C': printC(); break;
    case 'R': printRond(); break;
    case 'E': printE(); break;
    case '-': printMoins();break;
    default: printError(); break;
  }
} 

void clearLEDs()
{  
  digitalWrite(  2, LOW); // A
  digitalWrite(  3, LOW); // B
  digitalWrite(  4, LOW); // C
  digitalWrite(  5, LOW); // D
  digitalWrite(  6, LOW); // E
  digitalWrite(  7, LOW); // F
  digitalWrite(  8, LOW); // G
}
void printA()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
digitalWrite( hPin, LOW);
}
void printC()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, LOW);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, LOW);
  digitalWrite( hPin, LOW);
}
void printE()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, LOW);
  digitalWrite( hPin, LOW);
}
void printError()
{
  printE();
  digitalWrite( hPin, HIGH);
}
void printMoins()
{
  digitalWrite( aPin, LOW);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, LOW);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, HIGH);
}

void printRond()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, LOW);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}
void one()
{
  digitalWrite( aPin, LOW);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, LOW);
}

void two()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, LOW);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, HIGH);
}

void three()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, HIGH);
}

void four()
{
  digitalWrite( aPin, LOW);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void five()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void six()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void seven()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, LOW);
}

void eight()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void nine()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void zero()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, LOW);
}

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
//         =log(10000.0/(1024.0/RawADC-1)) // for pull-up configuration
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp);
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius
 return Temp;
}
