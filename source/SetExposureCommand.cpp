#include "SetExposureCommand.hpp"
#include "Camera.hpp"
#include <iostream>

SetExposureCommand::SetExposureCommand(Camera& camera, int value)
    : camera(camera),
      value(value)
{
    std::cout << "SetExposureCommand object created\n";
}

void SetExposureCommand::execute()
{
    camera.setExposure(value);
}