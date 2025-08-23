/**
 * File: robotWorld.cpp
 *
 * Author: ThommoMC
 * Created: 8-24-2025
 *
 * Description: Keeps tracks of other robots location based on what they informed us of.
 *              Also handles the vision thread detecting bots and attempting to track those.
 *
 * Copyright: Anki, Inc. 2016
 *
 **/

#include "engine/robotWorld.h"
#include "engine/robot.h"
#include "engine/cozmoContext.h"
#include "clad/externalInterface/messageEngineToGame.h"

namespace Anki {
namespace Vector {

RobotWorld::RobotWorld()
: IDependencyManagedComponent(this, RobotComponentID::RobotWorld)
{

}

void RobotWorld::InitDependent(Vector::Robot* robot, const RobotCompMap& dependentComps) {
    _robot = robot;
}

Result RobotWorld::VisionUpdate(const std::list<Vision::SalientPoint>& observedPoints) {
    // This is a stub currently, as I haven't actually gotten around to wiring "theres a robot here!" up yet.
    // We would keep track of the last time we saw a bot here and then determine if its just a false detection or a actual robot.
    
    return RESULT_OK;
}

}
}

