#include <stdlib.h>
#include <stdio.h>

int main(){
    int value;
    scanf("%d", &value);

    int num_system;
    scanf("%d", &num_system);

    char chars[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

    int result[32];
    int count = 1;
    while (value > 0){
        result[count++] = value % num_system;
        value /= num_system;
    }
    for (int i = count - 1; i > 0; --i) {
        if (result[i] < 10) {
            printf("%d", result[i]);
        }else{
            printf("%c",chars[result[i] % 10]);
        }
    }
    return 0;
}
