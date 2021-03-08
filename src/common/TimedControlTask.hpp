#ifndef TIMED_CONTROL_TASK_HPP_
#define TIMED_CONTROL_TASK_HPP_

#include "ControlTask.hpp"
#include <string>

class TimedControlTaskBase
{
protected:
    static unsigned int control_cycle_start_time;

public:
    static unsigned int wait_duration(const unsigned int &delta_t)
    {
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
        // get time to start task
        // wait until this time
        // call execute
    }

    unsigned int wait_until_time(const unsigned int &time)
    {
    }

    const std::string &get_name() const
    {
        return this->_name;
    }
};

#endif