

double  Humedad( int AirValue, int WaterValue){

int16_t adc0;
double humedad;
adc0 = ads1115.readADC_SingleEnded(1);
humedad = 100*AirValue/(AirValue-WaterValue)-adc0*100/(AirValue-WaterValue);
  return humedad;

}
