#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "opencr_pins.h"

namespace LokSrc 
{

// 8 step unipolar stepper motor control
class MotorController
{
public:
    MotorController();
    MotorController(int in1, int in2, int in3, int in4);
    MotorController(int in1, int in2, int in3, int in4, int limit_switch_fw, int limit_switch_bw);

    void setSpeed(long rpm);

    /**
     * @brief Tries to step motor forward
     * 
     * @param steps to step forward 
     * @return true if succesfull
     * @return false if not succesfull (limit switch 1 prevents moving)
     */
    bool stepForward(int steps);

    /**
     * @brief Tries to step motor backward 
     * 
     * @param steps to step backward 
     * @return true if succesfull
     * @return false if not succesfull (limit switch 2 prevents moving)
     */
    bool stepBackward(int steps);

private:
    void step_(int stepIndex);

    bool limitSwitchAllowsMoving_(int limit_switch_pin);

    int control_in1_;
    int control_in2_;
    int control_in3_;
    int control_in4_;

    int limit_switch_fw_;
    int limit_switch_bw_;

    const int number_of_steps_ = 8;
    const int steps_per_revolution_ = 64;
    int current_step_;

    unsigned long step_delay_; // ms
    unsigned long last_step_time_;
}; // class MotorController

} // namespace LokSrc

#endif
