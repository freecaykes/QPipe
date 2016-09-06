#include "ApplicationThread.h"

ApplicationThread::ApplicationThread():m_stop(true)
{
    executableDispatcher = new ExecutableDispatcher;
}

void ApplicationThread::stop()
{
    m_mutex.unlock();
    m_stop = true;
}

void ApplicationThread::run()
{
    if (m_stop)
    {
      this->m_mutex.lock();
      m_stop = false;
      executableDispatcher->run(external_argv);
    }
}

void ApplicationThread::setApplicationArguments(const char* args)
{
  if(m_stop) {external_argv = strdup(args);}
}

void ApplicationThread::get_external_argv()
{
  return this->external_argv;
}

void get_m_stop()
{
  return m_stop;
}
