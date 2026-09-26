#include "Camera.hpp"
#include <iostream>

Camera::Camera()
{
    std::cout << "Camera object created\n";
}

void Camera::start()
{
    std::cout << "Camera started\n";
}

void Camera::stop()
{
    std::cout << "Camera stopped\n";
}

void Camera::reset()
{
    std::cout << "Camera reset\n";
}

void Camera::captureFrame()
{
    std::cout << "Frame captured\n";
}

void Camera::setExposure(int value)
{
    std::cout << "Exposure set to " << value << '\n';
}