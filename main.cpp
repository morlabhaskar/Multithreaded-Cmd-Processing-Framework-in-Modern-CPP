#include <iostream>

using namespace std;

// ============================================================
// Command Interface
// ============================================================

class ICommand
{
public:

    ICommand()
    {
        cout << "ICommand object created" << endl;
    }

    virtual ~ICommand() = default;

    virtual void execute() = 0;
};


// ============================================================
// Receiver
// ============================================================

class Camera
{
public:

    Camera()
    {
        cout << "Camera object created" << endl;
    }

    void start()
    {
        cout << "Camera started" << endl;
    }

    void stop()
    {
        cout << "Camera stopped" << endl;
    }

    void reset()
    {
        cout << "Camera reset" << endl;
    }

    void captureFrame()
    {
        cout << "Frame captured" << endl;
    }

    void setExposure(int value)
    {
        cout << "Exposure set to " << value << endl;
    }
};


// ============================================================
// Start Camera Command
// ============================================================

class StartCameraCommand : public ICommand
{
public:

    explicit StartCameraCommand(Camera& camera)
        : camera(camera)
    {
        cout << "StartCameraCommand object created" << endl;
    }

    void execute() override
    {
        camera.start();
    }

private:

    Camera& camera;
};


// ============================================================
// Stop Camera Command
// ============================================================

class StopCameraCommand : public ICommand
{
public:

    explicit StopCameraCommand(Camera& camera)
        : camera(camera)
    {
        cout << "StopCameraCommand object created" << endl;
    }

    void execute() override
    {
        camera.stop();
    }

private:

    Camera& camera;
};


// ============================================================
// Reset Camera Command
// ============================================================

class ResetCameraCommand : public ICommand
{
public:

    explicit ResetCameraCommand(Camera& camera)
        : camera(camera)
    {
        cout << "ResetCameraCommand object created" << endl;
    }

    void execute() override
    {
        camera.reset();
    }

private:

    Camera& camera;
};


// ============================================================
// Capture Frame Command
// ============================================================

class CaptureFrameCommand : public ICommand
{
public:

    explicit CaptureFrameCommand(Camera& camera)
        : camera(camera)
    {
        cout << "CaptureFrameCommand object created" << endl;
    }

    void execute() override
    {
        camera.captureFrame();
    }

private:

    Camera& camera;
};


// ============================================================
// Set Exposure Command
// ============================================================

class SetExposureCommand : public ICommand
{
public:

    explicit SetExposureCommand(Camera& camera, int value)
        : camera(camera), value(value)
    {
        cout << "SetExposureCommand object created" << endl;
    }

    void execute() override
    {
        camera.setExposure(value);
    }

private:

    Camera& camera;
    int value;
};


// ============================================================
// Command Invoker
// ============================================================

class CommandInvoker
{
public:

    CommandInvoker()
    {
        cout << "CommandInvoker object created" << endl;
    }

    void setCommand(ICommand& command)
    {
        currentCommand = &command;
    }

    void executeCommand()
    {
        if (currentCommand != nullptr)
        {
            currentCommand->execute();
        }
        else
        {
            cout << "No command available" << endl;
        }
    }

private:

    ICommand* currentCommand{nullptr};
};


// ============================================================
// Client
// ============================================================

int main()
{
    cout << "========== Program Started ==========" << endl;

    // --------------------------------------------------------
    // Receiver
    // --------------------------------------------------------

    Camera camera;

    // --------------------------------------------------------
    // Concrete Commands
    // --------------------------------------------------------

    StartCameraCommand startCommand(camera);

    StopCameraCommand stopCommand(camera);

    ResetCameraCommand resetCommand(camera);

    CaptureFrameCommand captureCommand(camera);

    SetExposureCommand exposureCommand(camera, 80);

    // --------------------------------------------------------
    // Invoker
    // --------------------------------------------------------

    CommandInvoker invoker;

    // --------------------------------------------------------
    // Execute Start
    // --------------------------------------------------------

    cout << "\n--- Start Camera ---" << endl;

    invoker.setCommand(startCommand);
    invoker.executeCommand();

    // --------------------------------------------------------
    // Execute Set Exposure
    // --------------------------------------------------------

    cout << "\n--- Set Exposure ---" << endl;

    invoker.setCommand(exposureCommand);
    invoker.executeCommand();

    // --------------------------------------------------------
    // Execute Capture
    // --------------------------------------------------------

    cout << "\n--- Capture Frame ---" << endl;

    invoker.setCommand(captureCommand);
    invoker.executeCommand();

    // --------------------------------------------------------
    // Execute Reset
    // --------------------------------------------------------

    cout << "\n--- Reset Camera ---" << endl;

    invoker.setCommand(resetCommand);
    invoker.executeCommand();

    // --------------------------------------------------------
    // Execute Stop
    // --------------------------------------------------------

    cout << "\n--- Stop Camera ---" << endl;

    invoker.setCommand(stopCommand);
    invoker.executeCommand();

    cout << "\n========== Program Finished ==========" << endl;

    return 0;
}