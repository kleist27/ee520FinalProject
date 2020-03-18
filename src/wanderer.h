#ifndef __WANDERER_AGENT__H
#define __WANDERER_AGENT__H 

#include <string>
#include <math.h>
#include "enviro.h"

namespace {

    using namespace enviro;

    class MovingForward : public State, public AgentInterface {
        public:
        void entry(const Event& e) {}
        void during() { 
            if(sensor_value(0) <= 20){
                speed = 0.5; //! Created low speed manauvers for close encounters with wall
            }else if(60 > sensor_value(0) > 20){
                speed = 1.45; //! Created medium speed manauvers for decent length from the wall
            }else if(sensor_value(0) > 60){
                speed = 5; //! Created high speed manauvers for time when far from wall
            }
            track_velocity(speed,0);
            if ( sensor_value(0) < 20 && !(sensor_value(1) < 5 && sensor_value(2) < 5)) {
                emit(Event(tick_name)); //! Change the class activity from moving forward to rotation class 
            }            
        }
        void exit(const Event& e) {}
        double rate, speed;
        void set_tick_name(std::string s) { tick_name = s; }
        std::string tick_name;
    };
    class Rotating : public State, public AgentInterface {
        public:
        void entry(const Event& e) { 
            if(sensor_value(1) < sensor_value(2)){
                rate = -1.05; 
            }else if (sensor_value(1) > sensor_value(2)) {
                rate = 1.05; 
            }else{
                rate = 0; 
            }
        }
        void during() { 
            track_velocity(0,rate); 
            if ( sensor_value(0) > 60) {
                emit(Event(tick_name));
            }
        }
        void exit(const Event& e) {}
        double rate;
        void set_tick_name(std::string s) { tick_name = s; }
        std::string tick_name;        
    };

    class WandererController : public StateMachine, public AgentInterface {

        public:
        WandererController() : StateMachine() {

            set_initial(moving_forward);
            tick_name = "tick_" + std::to_string(rand()%1000); // use an agent specific generated 
                                                               // event name in case there are 
                                                               // multiple instances of this class
            add_transition(tick_name, moving_forward, rotating);
            add_transition(tick_name, rotating, moving_forward);
            moving_forward.set_tick_name(tick_name);
            rotating.set_tick_name(tick_name);

        }
        MovingForward moving_forward;
        Rotating rotating;
        std::string tick_name;

    };

    class Wanderer : public Agent {

        public:
        Wanderer(json spec, World& world) : Agent(spec, world) {
            add_process(wc);
        }
        void during() {
            //() == 0 ) {
            watch("button_click", [&](Event& e) {
                if ( e.value()["value"] == "restart_button" ) {
                    // if ( get_id() == 0 ) {
                    // Agent& new_wanderer = add_agent("Wanderer", 2, {{"fill", "lightgreen"}});
                    // Agent::start();
                    // }   
                }
            });
            // label(std::to_string((int) x()) + ", " + std::to_string((int) y()), 15, 15);
            //}
        }
        WandererController wc;

    };

    DECLARE_INTERFACE(Wanderer);

}

#endif