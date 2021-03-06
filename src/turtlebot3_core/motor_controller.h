/*******************************************************************************
* Copyright (C) 2022 Marius Niemenmaa 
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H
#define DEBUG_LOKSRC

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
     * @return false if not succesfull (limit switch fw prevents moving)
     */
    bool stepForward(int steps);

    /**
     * @brief Tries to step motor backward 
     * 
     * @param steps to step backward 
     * @return true if succesfull
     * @return false if not succesfull (limit switch bw prevents moving)
     */
    bool stepBackward(int steps);

private:
    void step_(int stepIndex);

    bool limitSwitchAllowsMoving_(int limit_switch_pin);

    /**
     * @brief Will return true if both limit switches are passing HIGH signal
     * 
     * If debug mode is on and both limit switches are active, motor is allowed to move
     * Used to drive motor off the rail when mechanical work is required
     * 
     * @param limiting_pin: pin number for limit switch limiting fw/bw movement
     * @return true if limit switches can be ignored
     * @return false if other limit switch is not in HIGH state or not defined
     */
    bool limitSwitchBypassActive_(int limiting_pin);

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
    bool stepping_in_progress_ = false;
}; // class MotorController

} // namespace LokSrc

#endif
