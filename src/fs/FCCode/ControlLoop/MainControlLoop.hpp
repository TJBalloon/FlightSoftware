#ifndef _MCL_HPP
#define _MCL_HPP
#include <fs/FCCode/ClockManager/ClockManager.hpp>
#include <fs/FCCode/IMU/IMUMonitor.hpp>
#include <fs/FCCode/DataCollection/DataCollection.hpp>
#include <fs/FCCode/Radio/Radio.hpp>

class MainControlLoop
{
protected:
    ClockManager clock_manager;
    IMUMonitor imu_monitor;
    Radio radio;
    DataCollection dc;

public:
    MainControlLoop(StateFieldRegistry &);
    void execute();
}