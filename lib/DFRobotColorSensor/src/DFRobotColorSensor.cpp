#include <Arduino.h>
#include <DFRobotColorSensor.h>


ColorSensor::Sensor::Sensor(int s0, int s1, int s2, int s3, int out) : _s0(s0), _s1(s1), _s2(s2), _s3(s3), _out(out) {
    pinMode(_s0,OUTPUT);
    pinMode(_s1,OUTPUT);
    pinMode(_s2,OUTPUT);
    pinMode(_s3,OUTPUT);

    digitalWrite(_s0,LOW);
    digitalWrite(_s1,LOW);
}

void ColorSensor::Sensor::tick() {
    int frequency = 0;
    // Setting red filtered photodiodes to be read
    digitalWrite(_s2,LOW);
    digitalWrite(_s3,LOW);
    // Reading the output frequency
    frequency = pulseIn(_out, LOW);
    _colors.r = frequency;

    // Setting Green filtered photodiodes to be read
    digitalWrite(_s2,HIGH);
    digitalWrite(_s3,HIGH);
    // Reading the output frequency
    frequency = pulseIn(_out, LOW);
    // Printing the value on the serial monitor
    _colors.g = frequency;

    // Setting Blue filtered photodiodes to be read
    digitalWrite(_s2,LOW);
    digitalWrite(_s3,HIGH);
    // Reading the output frequency
    frequency = pulseIn(_out, LOW);
    _colors.b = frequency;
}

ColorSensor::Color ColorSensor::Sensor::getRGB() const {
    return _colors;
}

void ColorSensor::Sensor::setScalingMode(ColorSensor::ScalingMode scale) {
    // The upper 2 numbers (2 and 3) are divisible by 2 and therefore would write HIGH vs LOW
    digitalWrite(_s0, scale / 2);

    // scale % 2 for item 1 and 3 would have a modulus of 1, and therefore write HIGH
    digitalWrite(_s1, scale % 2);
}