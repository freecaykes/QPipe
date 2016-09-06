#include "StdDirector.hpp"
#include "XMLWriter.h"
#include "ApplicationThread.h"

#define MAX_BYTE = 1024;

void outcallback( const char* ptr, std::streamsize count, void* outStream )
{
  printf("Within the wall: %s\n", ptr);
}


int main(int argc, char *argv[])
{
  // catching std::cout from internal program
  XMLWriter* logStream = new XMLWriter("logfile");
  StdDirector<>* stdOut = new StdDirector<>(std::cout, outcallback, logStream);

  // catching cout from an external application
  StdDirector<>* stdExternal = new StdDirector<>(std::cout, outcallback_ext, logStream);
  ApplicationThread* app_T = new ApplicationThread();
  app_T->setApplicationArguments("firefox");
  app_T->run();

}
