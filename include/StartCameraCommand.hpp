#pragma once

#include "ICommand.hpp"

class Camera;

class StartCameraCommand : public ICommand
{
public:
    explicit StartCameraCommand(Camera& camera);

    void execute() override;

private:
    Camera& camera;
};