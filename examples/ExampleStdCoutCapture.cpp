#include "StdDirector.hpp"
#include "XMLWriter.h"
#include "ApplicationThread.h"

#define MAX_BYTE = 1024;

void outcallback_ext( const char* ptr, std::streamsize count, void* outStream )
{
  printf("From over the wall: %s\n", ptr);
}

int main(int argc, char *argv[])
{
  // catching cout from an external application
  StdDirector<>* stdExternal = new StdDirector<>(std::cout, outcallback_ext, logStream);
  ApplicationThread* app_T = new ApplicationThread();
  app_T->setApplicationArguments("firefox");
  app_T->run();
}
