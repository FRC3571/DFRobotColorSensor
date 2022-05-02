#ifndef DF_ROBOT_COLOR_SENSOR_HEADER
#define DF_ROBOT_COLOR_SENSOR_HEADER

#include <Arduino.h>

namespace ColorSensor {
    struct Color {
        int r;
        int g;
        int b;
    };

    enum ScalingMode {
        ZERO,
        TWO,
        TWENTY,
        FULL
    };

    class Sensor {
    private:
        int _s0;
        int _s1;
        int _s2;
        int _s3;
        int _out;
        Color _colors {
            0,
            0,
            0
        };

    public:
        Sensor(int s0, int s1, int s2, int s3, int out);

        void tick();
        void setScalingMode(ScalingMode scale);
        Color getRGB() const;
    };
}

#endif