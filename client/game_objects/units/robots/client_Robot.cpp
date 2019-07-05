#include "client_Robot.h"
#include "../../../frames/client_Frame.h"
#include "../client_Unit.h"
#include <string>
#include <iostream>
using std::string;
using std::to_string;

ClientRobot::ClientRobot(unsigned int id, unsigned int owner_id,
                         unsigned int init_pos_x, unsigned int init_pos_y):
  Unit(id, owner_id,init_pos_x,init_pos_y){
  unsigned int order = 0;
  unsigned int angle = 0;
  string path;
  for (int i = 0; i < 8; i++) {
     if (order > 3) {
        order = 0;
        angle += 180;
     }
     path = "Units/Robots/walk_" + to_string(owner_id)+ "_r" +to_string(angle);
     path+= "_n" + to_string(order) + ".png";
     order++;
     x_frames.push_back(Frame(path));
  }
  angle = 90;
  order = 0;
  for (int i = 0; i < 8; i++){
     if (order > 3){
        order = 0;
        angle += 180;
     }
     path = "Units/Robots/walk_" + to_string(owner_id)+ "_r" +to_string(angle);
     path+= "_n" + to_string(order) + ".png";
     order++;
     y_frames.push_back(Frame(path));
  }

  angle = 45;
  order = 0;
  for (int i = 0; i < 16; i++){
     if (order > 3){
        order = 0;
        angle += 90;
     }
     path = "Units/Robots/walk_" +to_string(owner_id)+ "_r" + to_string(angle);
     path+= "_n" + to_string(order) + ".png";
     order++;
     xy_frames.push_back(Frame(path));
  }
  current_frame = &x_frames[0];
}


void ClientRobot::move_x(unsigned int dest_x, double speed){
    Unit::move_x(dest_x, speed);//Llamo al metodo de la clase mas abstracta
    /**Ahora me ocupo unicamente de las animaciones propias
       de este tipo de unidad**/
       if (pos_x > dest_x){ //desplazamiento hacia la derecha
            if (frame_index < 4 || frame_index > 7){
                frame_index = 4;
            }
       } else {
           /**Desplazamiento hacia la izquierda**/
           if (frame_index > 3){
                frame_index = 0;
           }
       }
       current_frame = &x_frames[frame_index];
       frame_index++;
}

void ClientRobot::move_y(unsigned int dest_y, double speed){
    Unit::move_y(dest_y, speed);

      if (pos_y < dest_y){ //desplazamiento hacia arriba
            if (frame_index < 4 || frame_index > 7){
                frame_index = 4;
            }
       } else {
           /**Desplazamiento hacia la abajo**/
           if (frame_index > 3){
                frame_index = 0;
           }
       }
       current_frame = &y_frames[frame_index];
       frame_index++;
}

void ClientRobot::move_xy(unsigned int dest_x, unsigned int dest_y,
                          double speed){
    Unit::move_xy(dest_x, dest_y, speed);
    if (pos_x < dest_x && pos_y < dest_y){
        /**diagonal hacia arriba e izquierda**/
        if (frame_index < 12 ||frame_index > 15){
            frame_index = 12;
        }
    } else if (pos_x < dest_x && pos_y > dest_y){
            /**diagonal hacia abajo e izquierda**/
            if (frame_index > 3){
                frame_index = 0;
            }
    } else if (pos_x > dest_x && pos_y > dest_y){
            /**diagonal hacia abajo y derecha**/
            if (frame_index < 4 || frame_index > 7){
                frame_index = 4;
            }
    } else if (pos_x > dest_x && pos_y < dest_y){
            /**diagonal hacia arriba y derecha**/
            if (frame_index < 8 || frame_index > 11){
                frame_index = 8;
            }
    }
    current_frame = &xy_frames[frame_index];
    frame_index++;
}
