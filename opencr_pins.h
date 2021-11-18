#ifndef OPENCR_PINS_
#define OPENCR_PINS_

// These are also defined in <chip.h> but with different numbering.
// This numbering matches to GPIO layout. 1 and 2 are left out because they are 3.3V and Ground pins
#define TB_BDPIN_GPIO_3            50
#define TB_BDPIN_GPIO_4            51
#define TB_BDPIN_GPIO_5            52
#define TB_BDPIN_GPIO_6            53
#define TB_BDPIN_GPIO_7            54
#define TB_BDPIN_GPIO_8            55
#define TB_BDPIN_GPIO_9            56
#define TB_BDPIN_GPIO_10           57
#define TB_BDPIN_GPIO_11           58
#define TB_BDPIN_GPIO_12           59
#define TB_BDPIN_GPIO_13           60
#define TB_BDPIN_GPIO_14           61
#define TB_BDPIN_GPIO_15           62
#define TB_BDPIN_GPIO_16           63
#define TB_BDPIN_GPIO_17           64
#define TB_BDPIN_GPIO_18           65
#define TB_BDPIN_GPIO_19           66
#define TB_BDPIN_GPIO_20           67

#define CRANE_MOTOR_DRIVER_IN1 TB_BDPIN_GPIO_4 
#define CRANE_MOTOR_DRIVER_IN2 TB_BDPIN_GPIO_6 
#define CRANE_MOTOR_DRIVER_IN3 TB_BDPIN_GPIO_8 
#define CRANE_MOTOR_DRIVER_IN4 TB_BDPIN_GPIO_10 

#define GRIPPER_L_MOTOR_DRIVER_IN1 TB_BDPIN_GPIO_12 
#define GRIPPER_L_MOTOR_DRIVER_IN2 TB_BDPIN_GPIO_14
#define GRIPPER_L_MOTOR_DRIVER_IN3 TB_BDPIN_GPIO_16
#define GRIPPER_L_MOTOR_DRIVER_IN4 TB_BDPIN_GPIO_18

#define GRIPPER_R_MOTOR_DRIVER_IN1 TB_BDPIN_GPIO_13
#define GRIPPER_R_MOTOR_DRIVER_IN2 TB_BDPIN_GPIO_15
#define GRIPPER_R_MOTOR_DRIVER_IN3 TB_BDPIN_GPIO_17
#define GRIPPER_R_MOTOR_DRIVER_IN4 TB_BDPIN_GPIO_19

#define CRANE_FW_LIMIT_SWITCH_ NOT_DEFINED
#define CRANE_BW_LIMIT_SWITCH_ NOT_DEFINED

#define GRIPPER_L_FW_LIMIT_SWITCH_ NOT_DEFINED
#define GRIPPER_L_BW_LIMIT_SWITCH_ NOT_DEFINED

#define GRIPPER_R_FW_LIMIT_SWITCH_ NOT_DEFINED
#define GRIPPER_R_BW_LIMIT_SWITCH_ NOT_DEFINED

#define NOT_DEFINED -1

#endif
