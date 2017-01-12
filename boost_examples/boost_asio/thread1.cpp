#include <iostream>
#include <unistd.h>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>

void workerFunc()
{
  boost::posix_time::seconds workTime(10);

  std::cout << "Worker: running" << std::endl;

  // Pretend to do something useful...
  boost::this_thread::sleep(workTime);
  std::cout << "Worker: finished" << std::endl;
}

int main(int argc, char *argv[])
{
  std::cout << "main: starup" << std::endl;

  boost::thread workerThread(workerFunc);

  std::cout << "main: waiting for thread" << std::endl;
  workerThread.join();
  //sleep(1);
  std::cout << "main: done" << std::endl;

  return 0;
}

