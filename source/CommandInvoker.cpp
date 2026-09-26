#include "CommandInvoker.hpp"
#include "ICommand.hpp"
#include <iostream>

CommandInvoker::CommandInvoker()
{
    std::cout << "CommandInvoker object created\n";
}

void CommandInvoker::setCommand(ICommand& command)
{
    currentCommand = &command;
}

void CommandInvoker::executeCommand()
{
    if (currentCommand != nullptr)
    {
        currentCommand->execute();
    }
    else
    {
        std::cout << "No command available\n";
    }
}