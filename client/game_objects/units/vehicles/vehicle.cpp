#include "vehicle.h"
#include "../../../frames/frame.h"

Vehicle::Vehicle(unsigned int id, unsigned int owner_id,
                             unsigned int init_pos_x,unsigned int init_pos_y):
                             Unit(id, owner_id,init_pos_x,init_pos_y){
  current_xframe = x_frames.begin();
  current_yframe = y_frames.begin();
  current_frame = &*current_xframe;
}

void Vehicle::move_x(unsigned int dest_x, double speed){
    Unit::move_x(dest_x, speed);//Llamo al metodo de la clase mas abstracta
    /**Ahora me ocupo unicamente de las animaciones propias
       de este tipo de unidad**/
       if (pos_x < dest_x){ //desplazamiento hacia la derecha
            if (frame_index > 2){
                frame_index = 0;
            }
       } else {
           /**Desplazamiento hacia la izquierda**/
           if (frame_index < 3 || frame_index > 5){
                frame_index = 3;
           }
       }
       current_frame = &x_frames[frame_index];
       frame_index++;
}

void Vehicle::move_y(unsigned int dest_y, double speed){
    Unit::move_y(dest_y, speed);

      if (pos_y < dest_y){ //desplazamiento hacia arriba
            if (frame_index < 3 || frame_index > 5){
                frame_index = 3;
            }
       } else {
           /**Desplazamiento hacia abajo**/
           if (frame_index > 2){
                frame_index = 0;
           }
       }
       current_frame = &y_frames[frame_index];
       frame_index++;
}

void Vehicle::move_xy(unsigned int dest_x, unsigned int dest_y,
                            double speed){
    Unit::move_xy(dest_x, dest_y, speed);
    if (pos_x > dest_x && pos_y > dest_y){
        /**diagonal hacia arriba e izquierda**/
        if (frame_index < 3 ||frame_index > 5){
            frame_index = 3;
        }
    } else if (pos_x > dest_x && pos_y < dest_y){
            /**diagonal hacia abajo e izquierda**/
            if (frame_index < 6 ||frame_index > 8){
                frame_index = 6;
            }
    } else if (pos_x < dest_x && pos_y < dest_y){
            /**diagonal hacia abajo y derecha**/
            if (frame_index < 9 || frame_index > 11){
                frame_index = 9;
            }
    } else if (pos_x < dest_x && pos_y > dest_y){
            /**diagonal hacia arriba y derecha**/
            if (frame_index > 2){
                frame_index = 0;
            }
    }
    current_frame = &xy_frames[frame_index];
    frame_index++;
}

