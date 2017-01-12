// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::driveleftMotor1;
std::shared_ptr<CANTalon> RobotMap::driveleftMotor2;
std::shared_ptr<CANTalon> RobotMap::driverightMotor1;
std::shared_ptr<CANTalon> RobotMap::driverightMotor2;
std::shared_ptr<RobotDrive> RobotMap::driveRobotDrive41;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    driveleftMotor1.reset(new CANTalon(4));
    lw->AddActuator("Drive", "leftMotor1", driveleftMotor1);
    
    driveleftMotor2.reset(new CANTalon(3));
    lw->AddActuator("Drive", "leftMotor2", driveleftMotor2);
    
    driverightMotor1.reset(new CANTalon(2));
    lw->AddActuator("Drive", "rightMotor1", driverightMotor1);
    
    driverightMotor2.reset(new CANTalon(1));
    lw->AddActuator("Drive", "rightMotor2", driverightMotor2);
    
    driveRobotDrive41.reset(new RobotDrive(driveleftMotor1, driveleftMotor2,
              driverightMotor1, driverightMotor2));
    
    driveRobotDrive41->SetSafetyEnabled(true);
        driveRobotDrive41->SetExpiration(0.1);
        driveRobotDrive41->SetSensitivity(0.5);
        driveRobotDrive41->SetMaxOutput(1.0);

        driveRobotDrive41->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
        driveRobotDrive41->SetInvertedMotor(RobotDrive::kRearRightMotor, true);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
