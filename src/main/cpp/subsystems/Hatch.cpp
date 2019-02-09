/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Hatch.h"

std::shared_ptr<frc::Servo> Hatch::tst;
std::shared_ptr<frc::Joystick> Hatch::joy;

std::shared_ptr<WPI_VictorSPX> Hatch::doorM; 

Hatch::Hatch() : Subsystem("Hatch") {
  tst.reset(new frc::Servo(9));
  joy.reset(new frc::Joystick(0));

  doorM.reset(new WPI_VictorSPX(1));
}

void Hatch::InitDefaultCommand() {
  
}

void Hatch::Periodic()
{
  if(doorMode()) return;
  tst->Set(joy->GetThrottle());
  if(joy -> GetRawButton(4))
  {
    tst -> Set(0.4);
    printf("Get Sey\n");
  }
  else if(joy -> GetRawButton(9))
  {
    tst -> Set(0);
    printf("Get back\n");
  }
  
}


bool Hatch::doorMode()
{
  int deg = joy->GetPOV();
  
  printf("POV:   %d\n", deg);
  
  if(deg == 0)
  {
    doorM -> Set(1);
  }
  else if(deg == 180)
  {
    doorM -> Set(-1);
  }
  else
  {
    doorM -> Set(0);
  }
  
  return true;
}