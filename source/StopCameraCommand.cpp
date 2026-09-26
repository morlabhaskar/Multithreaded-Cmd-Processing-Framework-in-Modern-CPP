#include "StopCameraCommand.hpp"
#include "Camera.hpp"
#include <iostream>

StopCameraCommand::StopCameraCommand(Camera& camera)
    : camera(camera)
{
    std::cout << "StopCameraCommand object created\n";
}

void StopCameraCommand::execute()
{
    camera.stop();
}