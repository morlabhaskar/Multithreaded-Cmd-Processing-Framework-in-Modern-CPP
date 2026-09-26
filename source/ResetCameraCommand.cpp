#include "ResetCameraCommand.hpp"
#include "Camera.hpp"
#include <iostream>

ResetCameraCommand::ResetCameraCommand(Camera& camera)
    : camera(camera)
{
    std::cout << "ResetCameraCommand object created\n";
}

void ResetCameraCommand::execute()
{
    camera.reset();
}