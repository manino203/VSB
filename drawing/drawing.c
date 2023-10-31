#include <stdlib.h>
#include "drawing.h"


void set_color(int color){
    switch(color){
        case 0:set_blue_color();break;
        case 1:set_black_color();break;
        case 2:set_green_color();break;
        case 3:set_red_color();break;
        case 4:set_white_color();break;
        case 5:set_yellow_color();break;
        default:;
    }
}

void dotted_line(int len){
    for(int i = 0; i < len; i++){
        draw_pixel();
        move_right();
        move_right();
    }
}

void stairs(int n){
    for (int i = 0; i < n; ++i) {
        draw_pixel();
        move_right();
        draw_pixel();
        move_down();
        draw_pixel();
        move_right();
    }
}

void flower(int w, int h){
    set_red_color();
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j <w; ++j) {
            draw_pixel();
            move_right();
        }
        for (int j = 0; j < w; ++j) {
            move_left();
        }
        move_down();
    }
    for (int i = 0; i < w / 2; ++i) {
        move_right();
    }
    for(int i = 0; i < h - w; ++i) {
        set_green_color();
        draw_pixel();
        move_down();
    }
}

void drawing0(){
    set_color(rand() % 5);
    dotted_line(2);
    move_to(3,5);
    set_color(rand() % 5);
    dotted_line(3);
    set_color(rand() % 5);
    move_to(4, 2);
    dotted_line(2);
    move_down();
    move_down();
    move_down();
    move_down();
    set_color(rand() % 5);
    dotted_line(5);
}

void drawing1(){
    for (int i = 0; i < 10; i+=2) {
        set_color(i/2);
        move_to(i, 0);
        stairs(i);
    }
}

void drawing2(){
    flower(5,10);
    move_to(3, 12);
    flower(3, 5);
    move_to(1, 17);
    flower(4, 8);
    move_to(7, 25);
    flower(3, 5);
}

void drawing3(int rows, int columns){
    int flower_height = 5;
    int flower_width = 3;
    for (int r = 0; r < rows; ++r) {
        move_to(r * (flower_height), 0);
        for (int c = 0; c < columns; ++c) {
            move_to(r * (flower_height + 2), (flower_width + 1) * c + 1);
            flower(flower_width, flower_height);
        }
    }
}

void drawing4(){
    int count = 13;
    while(count > 0){
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < count; ++i) {
                set_green_color();
                draw_pixel();
                switch (j) {
                    case 0:
                        move_down();
                        break;
                    case 1:
                        move_right();
                        break;
                    case 2:
                        move_up();
                        break;
                    case 3:
                        move_left();
                        break;
                    default:;
                }
                animate_ms(30);
            }
            count--;
        }
    }
}

int main() {
    // Keep this line here2
    int drawing = 0;
    scanf("%d", &drawing);
    clear_screen();

    // Load the input - what should be drawn.


//     Put your drawing code here
    switch (drawing) {
        case 0:
            drawing0();break;
        case 1:
            drawing1();break;
        case 2:
            drawing2();break;
        case 3:
            drawing3(2, 5);break;
        case 4:
            drawing4();break;
        default:;
    }
    // Keep this line here
    end_drawing();

    return 0;
}