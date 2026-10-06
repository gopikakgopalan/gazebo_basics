#include <gazebo/gazebo.hh>
#include <iostream>

namespace gazebo{

	class WorldPulginMyRobot : public WorldPlugin{
		
		public:
			WorldPulginMyRobot() : WorldPlugin(){
				printf("Hell World\n");
				std::cout<<"Hello from constructor\n"<<std::flush;
			}
			
			void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf){
				gzmsg<<"Hello world from load\n";
			}

	};
	GZ_REGISTER_WORLD_PLUGIN(WorldPulginMyRobot)
	
}
