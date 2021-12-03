/*******************************************************************************
* Copyright (C) 2021 Marius Niemenmaa 
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

#include "motor_controller.h"
#include "Arduino.h"

namespace LokSrc
{

MotorController::MotorController() { }
MotorController::MotorController(int in1, int in2, int in3, int in4) : MotorController::MotorController(in1, in2, in3, in4, NOT_DEFINED, NOT_DEFINED) { }
MotorController::MotorController(int in1, int in2, int in3, int in4, int limit_switch_fw, int limit_switch_bw) 
    : control_in1_(in1), control_in2_(in2), control_in3_(in3), control_in4_(in4), limit_switch_fw_(limit_switch_fw), limit_switch_bw_(limit_switch_bw) 
{
    this->current_step_ = 0;

    pinMode(this->control_in1_, OUTPUT);
    pinMode(this->control_in2_, OUTPUT);
    pinMode(this->control_in3_, OUTPUT);
    pinMode(this->control_in4_, OUTPUT);

    if (limit_switch_fw_ != NOT_DEFINED)
        pinMode(this->limit_switch_fw_, INPUT);
    if (limit_switch_bw_ != NOT_DEFINED)
        pinMode(this->limit_switch_bw_, INPUT);

    setSpeed(1000L);
}

void MotorController::setSpeed(long rpm)
{
  this->step_delay_ = (60L * 1000L * 1000L / this->steps_per_revolution_) / rpm;
}

void MotorController::step_(int stepIndex)
{
    switch (stepIndex) {
        case 0:
            digitalWrite(this->control_in1_, LOW);
            digitalWrite(this->control_in2_, HIGH);
            digitalWrite(this->control_in3_, HIGH);
            digitalWrite(this->control_in4_, HIGH);
            break;
        case 1:
            digitalWrite(this->control_in1_, LOW);
            digitalWrite(this->control_in2_, LOW);
            digitalWrite(this->control_in3_, HIGH);
            digitalWrite(this->control_in4_, HIGH);
            break;
        case 2:
            digitalWrite(this->control_in1_, HIGH);
            digitalWrite(this->control_in2_, LOW);
            digitalWrite(this->control_in3_, HIGH);
            digitalWrite(this->control_in4_, HIGH);
            break;
        case 3:
            digitalWrite(this->control_in1_, HIGH);
            digitalWrite(this->control_in2_, LOW);
            digitalWrite(this->control_in3_, LOW);
            digitalWrite(this->control_in4_, HIGH);
            break;
        case 4:
            digitalWrite(this->control_in1_, HIGH);
            digitalWrite(this->control_in2_, HIGH);
            digitalWrite(this->control_in3_, LOW);
            digitalWrite(this->control_in4_, HIGH);
            break;
        case 5:
            digitalWrite(this->control_in1_, HIGH);
            digitalWrite(this->control_in2_, HIGH);
            digitalWrite(this->control_in3_, LOW);
            digitalWrite(this->control_in4_, LOW);
            break;
        case 6:
            digitalWrite(this->control_in1_, HIGH);
            digitalWrite(this->control_in2_, HIGH);
            digitalWrite(this->control_in3_, HIGH);
            digitalWrite(this->control_in4_, LOW);
            break;
        case 7:
            digitalWrite(this->control_in1_, LOW);
            digitalWrite(this->control_in2_, HIGH);
            digitalWrite(this->control_in3_, HIGH);
            digitalWrite(this->control_in4_, LOW);
            break;
    }
}

bool MotorController::stepForward(int steps)
{
    if (!limitSwitchAllowsMoving_(this->limit_switch_fw_))
        return false;
    
    while (steps > 0) {
        unsigned long time_since_last_step = micros() - this->last_step_time_;

        if (time_since_last_step < this->step_delay_) {
            // delay_ms(this->step_delay_ - time_since_last_step);
            continue;
        }

        this->last_step_time_ = micros();

        this->current_step_++;
        if (this->current_step_ == this->number_of_steps_)
            this->current_step_ = 0;

        this->step_(this->current_step_);

        steps--;
    }

    return true;
}

bool MotorController::stepBackward(int steps) 
{
    if (!limitSwitchAllowsMoving_(this->limit_switch_bw_))
        return false;

    while (steps > 0) {
        unsigned long time_since_last_step = micros() - this->last_step_time_;

        if (time_since_last_step < this->step_delay_) {
            // delay_ms(this->step_delay_ - time_since_last_step);
            continue;
        }

        this->last_step_time_ = micros();

        if (this->current_step_ == 0)
            this->current_step_ = this->number_of_steps_;
        this->current_step_--;

        this->step_(this->current_step_);

        steps--;
    }

    return true;
}

bool MotorController::limitSwitchAllowsMoving_(int switch_pin)
{
    if (switch_pin == NOT_DEFINED)
        return true;
    
    return HIGH == digitalRead(switch_pin);
}

} // namespace LokSrc
