#pragma once

class ICommand;

class CommandInvoker
{
public:
    CommandInvoker();

    void setCommand(ICommand& command);
    void executeCommand();

private:
    ICommand* currentCommand{nullptr};
};