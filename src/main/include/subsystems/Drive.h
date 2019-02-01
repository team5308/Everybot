/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h> 
#include "frc/Joystick.h"
#include "rev/CANSparkMax.h"

class Drive : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Drive();
  void InitDefaultCommand() override;
  void Periodic() override;

  static std::shared_ptr<frc::Joystick> joyD;

  static std::shared_ptr<frc::Spark> spa1;
  static std::shared_ptr<frc::Spark> spa2;
  
  static std::shared_ptr<frc::Spark> spa3;
  static std::shared_ptr<frc::Spark> spa4;
  
  static std::shared_ptr<frc::SpeedControllerGroup> scgD1;
  static std::shared_ptr<frc::SpeedControllerGroup> scgD2;

  static std::shared_ptr<frc::DifferentialDrive> diff;
};
