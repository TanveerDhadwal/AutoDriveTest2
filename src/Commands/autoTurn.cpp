// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "autoTurn.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

autoTurn::autoTurn(double speed, double angle): Command() {
	m_speed = speed;
	m_angle = angle;
	finished = false;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void autoTurn::Initialize() {
	SetTimeout(2);
	Robot::drive->SetExp();
}

// Called repeatedly when this Command is scheduled to run
void autoTurn::Execute() {
	SmartDashboard::PutNumber("Left Motor .3 shoved left", -m_speed-(Robot::drive->getGAngle()*0.01));
	SmartDashboard::PutNumber("Right Motor Speed shoved left", m_speed+(Robot::drive->getGAngle()*0.01));
	SmartDashboard::PutNumber("Left Motor Speed shoved right", -m_speed+(Robot::drive->getGAngle()*0.01));
	SmartDashboard::PutNumber("Right Motor Speed shoved right", m_speed-(Robot::drive->getGAngle()*0.01));
	SmartDashboard::PutNumber("Gyro Position", Robot::drive->getGAngle());
	if (m_angle > 0) {
		if (Robot::drive->getGAngle() < m_angle){
			Robot::drive->driveMethod(-m_speed,m_speed);
		} else {
			finished = true;
		}
	} else if (m_angle < 0) {
		if (Robot::drive->getGAngle() > m_angle){
			Robot::drive->driveMethod(m_speed,-m_speed);
		} else {
			finished = true;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool autoTurn::IsFinished() {
	if (finished || IsTimedOut())
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void autoTurn::End() {
	Robot::drive->driveMethod(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoTurn::Interrupted() {

}
