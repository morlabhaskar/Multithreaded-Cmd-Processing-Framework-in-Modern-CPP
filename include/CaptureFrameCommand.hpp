#pragma once

#include "ICommand.hpp"

class Camera;

class CaptureFrameCommand : public ICommand
{
public:
    explicit CaptureFrameCommand(Camera& camera);

    void execute() override;

private:
    Camera& camera;
};