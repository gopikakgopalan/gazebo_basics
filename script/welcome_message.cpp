#include <gazebo/gazebo.hh>
#include <iostream>

namespace gazebo{
 class WorldPluginMyRobot : public WorldPlugin{
   public:
	WorldPluginMyRobot() : WorldPlugin() {}

        void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf){
	    std::cout<<"Welcome to Udacity Cafe\n"<<std::flush;	
	} 
 };

 GZ_REGISTER_WORLD_PLUGIN(WorldPluginMyRobot)
}
