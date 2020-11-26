//PROYECTO CDIO DONDE ESTAN COMBINADOS LOS SENSORES DE SALINIDAD Y HUMEDAD


#include <Wire.h>
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads1115(0x48);

#include "sensores.h"


int salinity_power_pin = 5; 


const int AirValue = 20146;   //Valor humedad en aire
const int WaterValue = 9637; //Valor humedad en agua
const int SinSal = 1004;     //Valor salinidad en un vaso sin sal 
const int ConSal = 604;     //Valor salinidad en un vaso con sal


void setup()
{
  Serial.print("INICIANDO EL PROGRAMA");
  /*delay(1000);
  Serial.println(".");
  delay(1000);
  Serial.println(".");
  delay(1000);
  Serial.println(".");
  delay(1000);*/
  Serial.begin(9600);
  ads1115.begin(); //Inicializar ADS
  ads1115.setGain(GAIN_ONE);
  pinMode(salinity_power_pin, OUTPUT);
  
}

void loop()
{
    
double medida_humedad = Humedad(AirValue, WaterValue);

Serial.println (medida_humedad);

delay (1000);

}
  /*

   //Espacio de texto para que no se junten los valores
  
 
  //Para CALIBRAR
// Serial.print(h);

 
 -----------------------------SAL--------------------------------- 
 int16_t sal; //Valor del ADC y a la vez la variable de sal final
 //int salinity_input_pin = 2; //Pin de corriente de la salinidad
 //int16_t salinity;
 digitalWrite( salinity_power_pin, HIGH ); // Subida de corriente

 
 sal = ads1115.readADC_SingleEnded(0);
 sal = 10000*SinSal/(SinSal-ConSal)-sal*10000/(SinSal-ConSal);
 sal = sal/100;

if(sal<=10){
   Serial.println("La salinidad es del 0%");
}
else{
  if(sal>=100){
     Serial.println("La salinidad es del 100%");
  }
  else{
     Serial.println("La salinidad es del ");
     Serial.println(sal); 
     Serial.println("%");
  }
}

delay(2000);
digitalWrite( salinity_power_pin, LOW ); // Bajada de corriente
delay(2000);

Serial.println("------------------------------------");
 //Para CALIBRAR
 //sal = ads1115.readADC_SingleEnded(0);
//Serial.println(sal); 
 
}

*/
