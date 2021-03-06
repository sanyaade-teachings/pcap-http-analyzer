#ifndef __ARGS_H__
#define __ARGS_H__

#include <list>
#include <set>
#include <string>

#include "tcp.h"

using namespace std;

class Args {
 public:
  Args();
  Args(int argc, char** argv);
  virtual ~Args();

  bool useShortOutputFormat();
  bool useStopwatchFormat();
  bool isFormatJsonEnabled();
  list<Netmask> getFilters();
  set<unsigned short>& getHttpPorts();
  set<unsigned short>& getWebSocketPorts();
  list<string>& getFiles();

 private:
  void parseFilter(string filter);
  void parseHttpPorts(string ports);
  void parseWebSocketPorts(string ports);
  void printUsage(string programName);

 private:
  bool mUseShortOutputFormat;
  bool mUseStopwatchFormat;
  bool mFormatJson;
  list<Netmask> mFilters;
  set<unsigned short> mHttpPorts;
  set<unsigned short> mWebSocketPorts;
  list<string> mFiles;
};

#endif /* __ARGS_H__ */
