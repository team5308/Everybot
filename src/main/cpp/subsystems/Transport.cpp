/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Transport.h"

std::shared_ptr<frc::Joystick> Transport::joyT;

std::shared_ptr<frc::JoystickButton> Transport::joyBut1;

std::shared_ptr<WPI_VictorSPX> Transport::vic1;

Transport::Transport() : Subsystem("ExampleSubsystem") {
  joyT.reset(new frc::Joystick(0));

  joyBut1.reset(new frc::JoystickButton(joyT.get(), 1));

  vic1.reset(new WPI_VictorSPX(2));
  
  // scgT = std::make_shared<frc::SpeedControllerGroup>(*vic1,*vic2);
 
}

void Transport::InitDefaultCommand() {
  // Set the default command for a subsystem her
  // SetDefaultCommand(new MySpecialCommand());
}

void Transport::Periodic(){
  perSpeed = curSpeed;
  curSpeed = joyT -> GetThrottle();

  if(perSpeed != curSpeed) {
    printf("%.2f\n", curSpeed);
  }

  if(joyBut1 -> Get()){
    vic1 -> Set(curSpeed);
  }
  else vic1 -> Set(0);
}

