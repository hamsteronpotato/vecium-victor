/**
 * File: robotWorld.h
 *
 * Author: ThommoMC
 * Created: 8-24-2025
 *
 * Description: Implements a container for mirroring on the main thread any robot faces
 *              detected on the vision system thread.
 *
 * Copyright: Anki, Inc. 2016
 *
 **/

#include "engine/robotComponents_fwd.h"
#include "util/entityComponent/iDependencyManagedComponent.h"
#include "coretech/common/shared/types.h"
#include "generated/coretech/vision/clad/types/salientPointTypes.h"
#include <list>

namespace Anki {
namespace Vector {
class Robot;

class RobotWorld : public IDependencyManagedComponent<RobotComponentID> {
    public: 
        RobotWorld();

        virtual void InitDependent(Vector::Robot* robot, const RobotCompMap& dependentComps) override;
        virtual void GetInitDependencies(RobotCompIDSet& dependencies) const override {
            dependencies.insert(RobotComponentID::CozmoContextWrapper);
        };
        virtual void GetUpdateDependencies(RobotCompIDSet& dependencies) const override {};

        Result VisionUpdate(const std::list<Vision::SalientPoint>& observedPoints);
        
    private:
        Robot* _robot;
 };
}
}

