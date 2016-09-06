#ifndef THREAD_H
#define THREAD_H

#include <thread>
#include <mutex>

#include "ExecutableDispatcher.h"

class ApplicationThread : public std::thread
{
public:

  ApplicationThread();
  ~ApplicationThread(){
   m_stop = true;
   m_mutex.unlock();
  }

  void setApplicationArguments(const char* args);
  void run();
  void stop();

  void get_external_argv();
  void get_m_stop();

private:
  ExecutableDispatcher* executableDispatcher;

  char* external_argv;
  std::mutex m_mutex;
  bool m_stop;
};

#endif // THREAD_H
