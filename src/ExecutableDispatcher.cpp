#include "ExecutableDispatcher.h"

ExecutableDispatcher::ExecutableDispatcher()
{
}

ExecutableDispatcher::~ExecutableDispatcher()
{
}

void ExecutableDispatcher::run(char* cmd)
{
    std::thread application_thread (&ExecutableDispatcher::readOutput, *this, cmd);
    application_thread.join();
}

char* ExecutableDispatcher::trimWhiteSpace(char* buf)
{
    char* end;
    // Trim leading space
    while(isspace(*buf)) buf++;
    if(*buf == 0)  // All spaces?
      return buf;
    // Trim trailing space
    end = buf + strlen(buf) - 1;
    while(end > buf && (isspace(*end) || strcmp(end, "\n") == 0)) end--;

    // Write new null terminator
    *(end+1) = 0;

    return buf;
}

int ExecutableDispatcher::readOutput(char* cmd)
{
    // Open pipe to opening an external program
    int buffer_len = 64;
    sysPipe = popen(cmd, "r");
    if(!sysPipe)
    {
        throw std::invalid_argument( "TIPSO not found" );
        return -1;
    }
    char buffer[buffer_len];
    std::string result = "";
    int i = 0;
    while(!feof(sysPipe))
    {
        i++;
        if(fgets(buffer, buffer_len, sysPipe) != NULL)
        {
            result += buffer;
            char* temp = this->trimWhiteSpace(buffer);
            // caught by callback function
            std::cout << temp << std::endl;
        }

        memset(&buffer, 0, sizeof(buffer));
    }

    pclose(sysPipe);
    return 0;
}

void ExecutableDispatcher::stop()
{
}
