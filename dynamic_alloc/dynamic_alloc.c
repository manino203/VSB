#include <stdio.h>
#include <stdlib.h>

struct Turtle {
    int dir;
    int pos[2];
};

struct Turtle init_turtle(){
    struct Turtle turtle;
    turtle.dir = 0;
    turtle.pos[0] = 0;
    turtle.pos[1] = 0;
    return  turtle;
}

int wrap_in(int start, int stop, int value){
    if(value < start){
        return stop;
    }
    if(value > stop){
        return start;
    }
    return value;
}

void init_canvas(char** canvas, int rows, int cols){
    for (int r = 0; r < rows; ++r) {
        canvas[r] = calloc(cols, sizeof(char));
        for (int c = 0; c < cols; ++c) {
            canvas[r][c] = '.';
        }
    }
}

void print_canvas(char** canvas, int rows, int cols){
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            printf("%c", canvas[r][c]);
        }
        printf("\n");
    }
}

void draw(char** canvas, struct Turtle turtle){
    if(canvas[turtle.pos[1]][turtle.pos[0]] == '.') {
        canvas[turtle.pos[1]][turtle.pos[0]] = 'o';
    }else{
        canvas[turtle.pos[1]][turtle.pos[0]] = '.';
    }
}

void move(int rows, int cols, struct Turtle* turtle){
    switch (turtle->dir) {
        case 0:
            turtle->pos[0] = wrap_in(0, cols, turtle->pos[0] + 1);
            break;
        case 1:
            turtle->pos[1] = wrap_in(0, rows, turtle->pos[1] + 1);
            break;
        case 2:
            turtle->pos[0] = wrap_in(0, cols, turtle->pos[0] - 1);
            break;
        case 3:
            turtle->pos[1] = wrap_in(0, rows, turtle->pos[1] - 1);
            break;
        default:break;
    }
}

int main(){
    int rows;
    int cols;
    scanf("%d %d", &rows, &cols);
    struct Turtle turtles[3];
    for (int i = 0; i < 3; ++i) {
        turtles[i] = init_turtle();
    }
    char** canvas = (char**)calloc(rows, sizeof(char*) * cols);
    init_canvas(canvas, rows, cols);
    int turtle_count = 1;
    char action = ' ';
    while(1){
        scanf("%c", &action);
        if(action == 'x'){
            break;
        }
        if(action == 'f'){
            if (turtle_count < 3) {
                turtle_count++;
            }
        }else{
            for (int i = 0; i < turtle_count; ++i) {
                switch (action) {
                    case 'o':
                        draw(canvas, turtles[i]);
                        break;
                    case 'm':
                        move(rows - 1,cols - 1, &turtles[i]);
                        break;
                    case 'l':
                        turtles[i].dir = wrap_in(0, 3, turtles[i].dir - 1);
                        break;
                    case 'r':
                        turtles[i].dir = wrap_in(0, 3, turtles[i].dir + 1);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    print_canvas(canvas, rows, cols);
    return 0;
}