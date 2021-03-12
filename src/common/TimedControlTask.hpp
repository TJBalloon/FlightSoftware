#ifndef TIMED_CONTROL_TASK_HPP_
#define TIMED_CONTROL_TASK_HPP_

#include "ControlTask.hpp"
#include <string>
#include "constants.hpp"
#include <unistd.h>
#include <thread>
#include <chrono>
#include <time.h>

typedef std::chrono::steady_clock::time_point sys_time_t;
typedef std::chrono::steady_clock::duration systime_duration_t;


class TimedControlTaskBase
{
protected:
    static unsigned int control_cycle_start_time;

public:
    static unsigned int duration_to_us(const systime_duration_t& delta) {
       return std::chrono::duration_cast<std::chrono::microseconds>(delta).count();
    }
    static sys_time_t get_system_time() {
      return std::chrono::steady_clock::now();
    }
    static void wait_duration(const unsigned int &delta_t)
    {
      const sys_time_t start = get_system_time();
      // Wait until execution time
      while(duration_to_us(get_system_time() - start) < delta_t) {
          usleep(delta_t);
        
      }


    }
};

class TimedControlTask : public ControlTask, public TimedControlTaskBase
{
private:
    unsigned int _offset;
    const std::string &_name;

public:
    TimedControlTask(StateFieldRegistry &registry, const std::string &name, const unsigned int &offset)
        : ControlTask(registry), _name(name), _offset(offset){};

    void execute_on_time()
    {
      sys_time_t earliest_start_time = 
        TimedControlTaskBase::control_cycle_start_time + offset;
      wait_until_time(earliest_start_time);
      return this->execute();
    }

    void wait_until_time(const unsigned int &time)
    {
      // Compute timing statistics and publish them to state fields
      const signed int delta_t = (signed int) duration_to_us(time - get_system_time());
      const unsigned int wait_time = std::max(delta_t, 0)

      wait_duration(wait_time); 
 
    }

    const std::string &get_name() const
    {
        return this->_name;
    } 
};

#endif