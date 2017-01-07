#include "QTExtensionThread.h"

QTExtensionThread::QTExtensionThread():m_stop(false)
{
    execDispatched = new ExecutableDispatcher;
}

void QTExtensionThread::stop()
{
    //qDebug()<<"Thread::stop called from main thread: "<<currentThreadId();
    QMutexLocker locker(&m_mutex);
    m_stop=true;
}

void QTExtensionThread::run()
{
    //qDebug()<<"From worker thread: "<<currentThreadId();
    execDispatched->run(external_argv);
}

void QTExtensionThread::setApplicationArguments(std::string args)
{
    external_argv = strdup(args.c_str());
}

char* QTExtensionThread::get_external_argv()
{
  return this->external_argv;
}

bool QTExtensionThread::get_m_stop()
{
  return this->m_stop;
}
