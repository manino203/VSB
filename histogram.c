#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int digit_count(int num){
    if (num == 0){
        return 1;
    }
    int counter = 0;
    while(num != 0){
        num /= 10;
        counter ++;
    }
    return counter;
}

int max(int arr[]){
    int max = 0;
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size;++i) {
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void horizontal(){
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int y_axis[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        if (val >= m && val <= (m + 8)){
            y_axis[val-m] ++;
        }else{
            y_axis[9] ++;
        }
    }
    int max_digit_count = digit_count(m + 8);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < (max_digit_count - digit_count(i + m)); ++j) {
            printf(" ");
        }
        printf("%d ", i+m);
        for (int j = 0; j < y_axis[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }
    if(y_axis[9] > 0){
        printf("invalid: ");
        for (int j = 0; j < y_axis[9]; ++j) {
            printf("#");
        }
    }
}

void vertical(){
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int range = 10;
    int x_axis[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 1; i <= n; ++i) {
        int val;
        scanf("%d", &val);
        if (val >= m && val <= (m + 8)){
            x_axis[(val - m)+1] ++;
        }else{
            x_axis[0] ++;
        }
    }

    for (int y = max(x_axis); y > 0; y--) {
        for (int x = 0; x < range; ++x) {
            if(x_axis[x] >= y){
                printf("#");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("i");
    for (int i = m; i <= m+8; ++i) {
        printf("%d", i);

    }
}

int main(){
    char mode;
    scanf("%c", &mode);
    switch(mode){
        case 'h':
            horizontal();
            break;
        case 'v':
            vertical();
            break;
        default:
            printf("Neplatny mod vykresleni");
            return 1;
    }
    printf("\n");
    return  0;
}