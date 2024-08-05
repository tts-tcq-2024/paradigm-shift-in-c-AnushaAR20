#include<stdio.h>

void print_message(int message_index, enum ParameterType parameter_type) {
    printf("%s\n", messages[current_language][parameter_type][message_index]);
}
