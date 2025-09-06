#include <cassert>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

// Log level enumeration
enum class Level { DEBUG = 0, INFO = 1, WARN = 2, ERROR = 3, FATAL = 4 };

// Log entry structure
class Log {
  public:
  static std::vector<std::string> logMsg;
    
    Log(Level level)
    {
      logEntry << "["<<levelTostring(level) << "]";
    };
    ~Log()
    {
      std::cout << "calling destructor "<<std::endl;
      logMsg.push_back(logEntry.str()); 
    }
    static Log Info();
    static Log Debug();
    static Log Warn();
    static Log Error();
    static Log Fatal();
    static void Dump();
    static int GetLogCount();
    static bool ContainsMessage(const std::string& target);


    Log& operator<<(const std::string & msg)
    {
      this->logEntry << msg << std::endl;
      return *this;
    }
    std::string levelTostring(Level level)
    {
      switch(level)
      {
        case Level::DEBUG:
          return "DEBUG";
          break;
        case Level::INFO:
          return "INFO";
          break;
        case Level::WARN:
          return "WARN";
          break;
        case Level::ERROR:
          return "ERROR";
          break;
        case Level::FATAL:
          return "FATAL";
          break;
        default:
          return "UNKNOWN";
          break;

      }
    }
    private:
      std::stringstream logEntry;
      
};
std::vector<std::string> Log::logMsg;
Log Log::Info(void)
{
  return Log(Level::INFO);      
}
Log Log::Debug()
{
  return Log(Level::DEBUG);
}
Log Log:: Error()
{
  return Log(Level::ERROR);
}
Log Log::Fatal()
{
  return Log(Level::FATAL);
}

Log Log::Warn()
{
  return Log(Level::WARN);
}
int Log::GetLogCount()
{
  return logMsg.size();
}
void Log::Dump()
{
  std::for_each(logMsg.begin(),logMsg.end(),[](const std::string& s){
  std::cout << s << std::endl; 
  });
}
bool Log::ContainsMessage(const std::string& target)
{
  for (const auto& str : logMsg)
  {
    if (str.find(target) != std::string::npos)
    {
      return true;
    }
  }
  return false;
}
#define LOG Log

int main() {
  std::cout << "==============================================\n";
  std::cout << "           LOGGING SYSTEM VALIDATOR\n";
  std::cout << "==============================================\n\n";

  // Test : Basic logging functionality
  std::cout << "--- Test 1: Basic Logging ---\n";

  LOG::Info() << "System started";
  LOG::Warn() << "Configuration file missing";
  LOG::Error() << "Database connection failed";
  LOG::Debug() << "This debug message should not appear";
  LOG::Fatal() << "Application must terminate";

  // Verify logs were stored
  assert(LOG::GetLogCount() == 5);
  assert(LOG::ContainsMessage("System started"));
  assert(LOG::ContainsMessage("Configuration file missing"));

  LOG::Dump();

  std::cout << "\n==============================================\n";
  std::cout << "         ALL TESTS PASSED! ✓\n";
  std::cout << "==============================================\n";

  return 0;
}
