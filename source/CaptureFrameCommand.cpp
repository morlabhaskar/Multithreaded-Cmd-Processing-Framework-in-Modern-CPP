#include "CaptureFrameCommand.hpp"
#include "Camera.hpp"
#include <iostream>

CaptureFrameCommand::CaptureFrameCommand(Camera& camera)
    : camera(camera)
{
    std::cout << "CaptureFrameCommand object created\n";
}

void CaptureFrameCommand::execute()
{
    camera.captureFrame();
}