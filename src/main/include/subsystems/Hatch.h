/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>

class Hatch : public frc::Subsystem {
 private:
  static std::shared_ptr<frc::Servo> tst;
  static std::shared_ptr<frc::Joystick> joy;

  static std::shared_ptr<WPI_VictorSPX> doorM;
  
 public:
  Hatch();
  void InitDefaultCommand() override;
  void Periodic() override;
  
  bool doorMode();
};
