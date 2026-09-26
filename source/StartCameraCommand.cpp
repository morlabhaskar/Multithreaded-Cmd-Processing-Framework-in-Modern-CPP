#include "StartCameraCommand.hpp"
#include "Camera.hpp"
#include <iostream>

StartCameraCommand::StartCameraCommand(Camera& camera)
    : camera(camera)
{
    std::cout << "StartCameraCommand object created\n";
}

void StartCameraCommand::execute()
{
    camera.start();
}