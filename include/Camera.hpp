#pragma once

class Camera
{
public:
    Camera();

    void start();
    void stop();
    void reset();
    void captureFrame();
    void setExposure(int value);
};