#pragma once

#include "ICommand.hpp"

class Camera;

class StopCameraCommand : public ICommand
{
public:
    explicit StopCameraCommand(Camera& camera);

    void execute() override;

private:
    Camera& camera;
};