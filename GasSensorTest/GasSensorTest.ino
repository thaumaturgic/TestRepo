//void setup()
//{
//  Serial.begin(9600);
//}
//void loop()
//{
//float sensor_volt;
//float RS_air; // Get the value of RS via in a clear air
//float R0; // Get the value of R0 via in H2
//float sensorValue;

/*--- Get a average data by testing 100 times ---*/
//for(int x = 0 ; x < 100 ; x++)
//{
//     sensorValue = sensorValue + analogRead(A0);
//}
//sensorValue = sensorValue/100.0;
/*-----------------------------------------------*/
//sensor_volt = sensorValue/1024*5.0;
//RS_air = (5.0-sensor_volt)/sensor_volt; // omit *RL
//R0 = RS_air/10.0; // The ratio of RS/R0 is 10 in a clear air


//Serial.print("sensor_volt = ");
//Serial.print(sensor_volt);
//Serial.println("V");
//Serial.print("R0 = ");
//Serial.println(R0);

//Serial.println(analogRead(A0));
//delay(1000);
//}


//void setup()
//{
// Serial.begin(9600);
//}
//void loop() {
// float sensor_volt;
// float RS_gas; // Get value of RS in a GAS
// float ratio; // Get ratio RS_GAS/RS_air
//
// int sensorValue = analogRead(A0);
// sensor_volt=(float)sensorValue/1024*5.0;
// RS_gas = (5.0-sensor_volt)/sensor_volt; // omit *RL
//
// /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
// ratio = RS_gas/(0.08); // ratio = RS/R0
// /*-----------------------------------------------------------------------*/
// Serial.print("sensor_volt = ");
// Serial.println(sensor_volt);
// Serial.print("RS_ratio = ");
// Serial.println(RS_gas);
// Serial.print("Rs/R0 = ");
// Serial.println(ratio);
// Serial.print("\n\n");
// delay(1000);
//}

//////////////////////////////////////////////////////////////
//
// "R0" determined to be around '200' in clean air. (0.97 volts)
// Compare ratio to Rs which is the measured value in gas. The radio 0 to 10 determines gas PPM
// Arduino Uno has a 10 bit ADC (1024)
//
////////////////////////////////////////////////////////////// 

#define R0_VALUE_IN_CLEAR_AIR 200 // Value that the ADC returns in clear air
int speakerPin = 7;

void setup()
{
  Serial.begin(115200);

  tone(speakerPin, 440);
  delay(1000);
  noTone(speakerPin);
}
void loop()
{
  float sensorValue = 0;

  for(int i = 0; i < 100; i++)
  {
      sensorValue += analogRead(A0);
  }

  float averageSensorValue = sensorValue / 100.0; // This is the Rs value of the air. 
  float sensorVoltage = averageSensorValue * 5.0 / 1023.0; // 10 bit Analog precision @ 5 volts;

  
  
  if(sensorVoltage > 3.0)
  {
      tone(speakerPin, 440);
  }
  else
  {
      noTone(speakerPin);
  }

  // Calculate the Rs / R0 ratio to determine if there is any concentration of smoke or gas in the air
  // OR just use the raw voltage / ADC value compared to an absolute threshold
  
  Serial.print(averageSensorValue);
  Serial.print(" ");
  Serial.print(sensorVoltage);
  Serial.println();
  delay(500);
}

