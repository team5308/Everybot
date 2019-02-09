/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drive.h"
#include <cstdio>

std::shared_ptr<frc::Joystick> Drive::joyD;

std::shared_ptr<frc::Spark> Drive::spa1;
std::shared_ptr<frc::Spark> Drive::spa2;

std::shared_ptr<frc::Spark> Drive::spa3;
std::shared_ptr<frc::Spark> Drive::spa4;

std::shared_ptr<frc::SpeedControllerGroup> Drive::scgD1;
std::shared_ptr<frc::SpeedControllerGroup> Drive::scgD2;

std::shared_ptr<frc::DifferentialDrive> Drive::diff;

Drive::Drive() : Subsystem("ExampleSubsystem") {
  joyD.reset(new frc::Joystick(0));

  spa1.reset(new frc::Spark(0));
  spa2.reset(new frc::Spark(6));

  spa3.reset(new frc::Spark(2));
  spa4.reset(new frc::Spark(3));

  scgD1 = std::make_shared<frc::SpeedControllerGroup>(*spa1,*spa2);
  scgD2 = std::make_shared<frc::SpeedControllerGroup>(*spa3,*spa4);

  diff.reset(new frc::DifferentialDrive(*scgD1,*scgD2));
}

void Drive::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.


inline double abs(double x){
  if(x < 0.0){
    return -x;
  }else{
    return x;
  }
}

double suoqu(double x){
if(abs(x) < 0.14){
  return 0.0;
}else{
  return x;
}
}

void Drive::Periodic(){

  // if(joyD->GetRawButton(3))
  // {
  //   // scgD2->Set(1);
  //   spa1 -> Set(1);
  //   printf("1d1d1\n");
  // }
  // else if(joyD->GetRawButton(4))
  // {
  //   spa2 ->Set(1);
  //   printf("2de2d2d\n");
  // }
  // elsePP
  // {
  //   spa1->Set(0);
  //   spa2->Set(0);
  // }
  

  double ty = 1.0;
  
  // scgD1->Set(ty);
  // scgD2->Set(ty);

  // printf("ffrfrf\n");  

diff -> ArcadeDrive(suoqu(joyD -> GetY()), suoqu(joyD -> GetX()));
}




