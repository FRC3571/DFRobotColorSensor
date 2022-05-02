// Example code for how to use the class

#include <Arduino.h>
#include <DFRobotColorSensor.h>

#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define SENSOR_OUT 2

char colorString[20];

ColorSensor::Sensor colorSensor(S0, S1, S2, S3, SENSOR_OUT);

void setup() {
  colorSensor.setScalingMode(ColorSensor::ScalingMode::TWENTY);
  Serial.begin(9600);
}

void loop() {
  // Grab colours using ColorSensor::Sensor::tick()
  colorSensor.tick();
  ColorSensor::Color color = colorSensor.getRGB();

  sprintf(colorString, "(%d, %d, %d)", color.r, color.g, color.b);

  if (color.r <= 30 && color.g <= 40) {
    Serial.print("YELLOW");
  } else if (color.r <= 25 && color.g >= 40)  {
    Serial.print("RED");
  } else if (color.b <= 40) {
    Serial.print("BLUE");
  } else {
    Serial.print("No colour found :(");
  }
  Serial.println(colorString);

  delay(100);
}