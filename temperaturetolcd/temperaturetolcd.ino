#include <Wire.h>
#include "rgb_lcd.h"

// Define the pin to which the temperature sensor is connected.
const int pinTemp = A0;

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

// Define the B-value of the thermistor.
// This value is a property of the thermistor used in the Grove - Temperature Sensor,
// and used to convert from the analog value it measures and a temperature value.
const int B = 3975;

void setup()
{

    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    // Configure the serial communication line at 9600 baud (bits per second.)
    Serial.begin(9600);
}

void loop()
{
    // Get the (raw) value of the temperature sensor.
    int val = analogRead(pinTemp);

    // Determine the current resistance of the thermistor based on the sensor value.
    float resistance = (float)(1023-val)*10000/val;

    // Calculate the temperature based on the resistance value.
    float temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15;

    // Print the temperature to the serial console.
    // Serial.println(temperature);

    lcd.begin(16, 2);
    

    lcd.print(temperature);

    // Wait one second between measurements.
    delay(1000);
    lcd.clear();
}

