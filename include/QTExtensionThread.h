#ifndef THREAD_H
#define THREAD_H

#include <QtWidgets>
#include <QtGui>
#include "ApplicationThread.h"
#include "ExecutableDispatcher.h"

class QTExtensionThread : public QThread
{
    Q_OBJECT

   public:
       QTExtensionThread();
       ~QTExtensionThread(){
        m_stop = true;
        m_mutex.unlock();
       }

       void setApplicationArguments(std::string arg);
       void run();
       void stop();

       char* get_external_argv();
       bool get_m_stop();

   private:
       ExecutableDispatcher* execDispatched;

       char* external_argv;
       QMutex m_mutex;
       bool m_stop;

};

#endif // THREAD_H
