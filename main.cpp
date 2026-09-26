#include <iostream>

#include "Camera.hpp"
#include "CommandInvoker.hpp"

#include "StartCameraCommand.hpp"
#include "StopCameraCommand.hpp"
#include "ResetCameraCommand.hpp"
#include "CaptureFrameCommand.hpp"
#include "SetExposureCommand.hpp"

int main()
{
    std::cout << "========== Program Started ==========\n";

    Camera camera;

    StartCameraCommand startCommand(camera);
    StopCameraCommand stopCommand(camera);
    ResetCameraCommand resetCommand(camera);
    CaptureFrameCommand captureCommand(camera);
    SetExposureCommand exposureCommand(camera, 80);

    CommandInvoker invoker;

    std::cout << "\n--- Start Camera ---\n";

    invoker.setCommand(startCommand);
    invoker.executeCommand();

    std::cout << "\n--- Set Exposure ---\n";

    invoker.setCommand(exposureCommand);
    invoker.executeCommand();

    std::cout << "\n--- Capture Frame ---\n";

    invoker.setCommand(captureCommand);
    invoker.executeCommand();

    std::cout << "\n--- Reset Camera ---\n";

    invoker.setCommand(resetCommand);
    invoker.executeCommand();

    std::cout << "\n--- Stop Camera ---\n";

    invoker.setCommand(stopCommand);
    invoker.executeCommand();

    std::cout << "\n========== Program Finished ==========\n";

    return 0;
}