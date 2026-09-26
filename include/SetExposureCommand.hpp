#pragma once

#include "ICommand.hpp"

class Camera;

class SetExposureCommand : public ICommand
{
public:
    SetExposureCommand(Camera& camera, int value);

    void execute() override;

private:
    Camera& camera;
    int value;
};