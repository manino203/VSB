#include <stdio.h>

void print_row(int n){
    for (int x = 0; x < n; x++) {
        printf("x");
    }
    printf("\n");
}

void full_rect(int w, int h){
    for (int y = 0; y < h; y++) {
        print_row(w);
    }
};

void inside_rect(int w, int h, void (*f)(int, int, int, int)){
    for (int y = 0; y < h; y++) {
        if (y == 0 || y == (h - 1)){
            print_row(w);
        }else{
            for (int x = 0; x < w; x++) {
                if (x == 0 || x == (w - 1)){
                    printf("x");
                }else{
                    (*f)(x - 1, y - 1, w - 2, h - 2);
                }
            }
            printf("\n");
        }
    }
};

void space(int x, int y, int w, int h){
    printf(" ");
}

void hollow_rect(int w, int h){
    inside_rect(w, h, space);
}

int num = 0;
void row_increasing(int x, int y, int w, int h){
    printf("%d", num);
    num ++;
    num %= 10;
}

void row_number_rect(int w, int h){
    inside_rect(w, h, row_increasing);
};
void diagonal(int w, int h){
    for(int y = 0; y < w; y++){
        for (int x = 0; x < y; x++) {
            printf(" ");
        }
        printf("x\n");
    }
};

void t(int w, int h){
    print_row(w);
    for(int r = 0; r < (h-1); r++){
        for (int i = 0; i < w / 2; i++)
            printf(" ");
        printf("x");
        printf("\n");
    }
};

void column_increasing(int x, int y, int w, int h){
    printf("%d", (y + (h * x)) % 10);
}

void column_number_rect(int w, int h){
    inside_rect(w, h, column_increasing);
};

int obrazce_main() {

    int pattern = 0;
    int width = 0;
    int height = 0;

    scanf("%d%d%d", &pattern, &width, &height);
    switch (pattern){
        case 0:
            full_rect(width, height); break;
        case 1:
            hollow_rect(width, height); break;
        case 2:
            row_number_rect(width, height); break;
        case 3:
            diagonal(width, height); break;
        case 6:
            t(width, height); break;
        case 9:
            column_number_rect(width, height); break;
        default:
            printf("Neznamy obrazec\n");break;
    }
    return 0;
}