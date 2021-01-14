#include <Arduino.h>
#include
class ClockManager
{
private:
    ReadableStateField<uint> controlCycleCount;
    system_time_t startTime;
    uint total;

public:
    ClockManager();
    void execute();
}