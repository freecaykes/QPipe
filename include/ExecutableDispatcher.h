#ifndef EXECUTABLEDISPATCHER_H
#define EXECUTABLEDISPATCHER_H

#include <thread>
#include <iostream>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


class ExecutableDispatcher
{
public:
    ExecutableDispatcher();
    ~ExecutableDispatcher();

    void run(char* cmd);
    void stop();
    char* trimWhiteSpace(char* buf);
private:
    FILE* sysPipe;

    int readOutput(char* cmd);
};

#endif // EXECUTABLEDISPATCHER_H
