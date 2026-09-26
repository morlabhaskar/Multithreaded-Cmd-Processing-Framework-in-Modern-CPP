#pragma once

#include "ICommand.hpp"

class Camera;

class ResetCameraCommand : public ICommand
{
public:
    explicit ResetCameraCommand(Camera& camera);

    void execute() override;

private:
    Camera& camera;
};