#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char* get_step(char* path, int i, int j) {
//     char* step = (char*)malloc((j - i) * sizeof(char));
//     int k = 0;
//     for (k = i + 1; k < j; k++) {
//         step[k - i - 1] = path[k];
//     }
//     step[j - i - 1] = '\0';
//     return step;
// }

// char* simplifyPath(char* path) {
//     char** path_stack = NULL;
//     char* step = NULL;
//     char* result = NULL;
//     int path_stack_size = 1;
//     int path_stack_pointer = 0;
//     int path_length = 0;
//     int result_pointer = 0;
//     int step_length = 0;
//     int i = 0, j = 0;
//     int stack_steps_length = 0;
//     char root[] = "/";
//     char stay[] = ".";
//     char back[] = "..";
//     char empty[] = ""; 
//     path_stack = (char**)malloc(sizeof(char*));
//     path_length = strlen(path);
//     i = 0;
//     while (i < path_length) {
//         j = i + 1;
//         while ((path[j] != '/') && (j < path_length)) {
//             j += 1;
//         } 
//         step = get_step(path, i, j);
//         if (0 == strcmp(step, back)) {
//             path_stack_pointer -= 1;
//             free(step);
//             if (path_stack_pointer < 0) {
//                 return "/";
//             } else {
//                 stack_steps_length -= strlen(path_stack[path_stack_pointer]);
//                 free(path_stack[path_stack_pointer]);
//             }
//         } else if ((0 != strcmp(step, stay)) && (0 != strcmp(step, empty))) {
//             path_stack[path_stack_pointer] = step;
//             stack_steps_length += strlen(step);
//             path_stack_pointer += 1;
//             if (path_stack_size <= path_stack_pointer) {
//                 path_stack = realloc(path_stack, (path_stack_pointer + 1) * sizeof(char*));
//                 path_stack_size = path_stack_pointer + 1;
//             }
//         }
//         i = j;
//     }
//     if (0 == path_stack_pointer) {
//         return "/";
//     }
//     result = (char*)malloc((stack_steps_length + path_stack_pointer + 1) * sizeof(char));
//     for (i = 0; i < path_stack_pointer; i++) {
//         result[result_pointer] = '/';
//         result_pointer += 1;
//         step_length = strlen(path_stack[i]);
//         for (j = 0; j < step_length; j++) {
//             result[result_pointer] = path_stack[i][j];
//             result_pointer += 1;
//         }
//     }
//     result[stack_steps_length + path_stack_pointer + 1] = '\0';
//     return result; 
// }

#define MAX 1000

char* simplifyPath(char *path) {
    char *r = malloc(MAX);
    char str[MAX];
    char stack[MAX][MAX];
    int top = 0, j, i = 0;
    while(1) {
        while(path[i]=='/') {
            i++;
        }
        j = 0;
        while (path[i] && path[i] != '/') {
            str[j++] = path[i++];
        }
        str[j] = 0;
        if (j != 0){
            if (!strcmp(str, "..")){
                if (top != 0)
                top--;
            } else if (strcmp(str, ".")) {
                strcpy(stack[top++], str);
            }
        }
        else {
            break;
        }
    }
    strcpy(r, "/");
    for(i = 0; i < top; i++) {
        strcat(r, stack[i]); 
        if(i != top - 1) {
            strcat(r, "/");
        }
    }
    return r;
}

/**
 * ORZ...The output of run code is different from the one of submit 
 * Here is someone else's code 
 **/

int main() {
    char path[] = "/qSNIo///b/../BtIY/DrG/./MTWto/.///./h/../dz/KBIma/y/wgatd/fhrm///ePfTD/Hef/TVM/../mhZ/JR/.///vnZ/cRCQu";
    char* result = simplifyPath(path);
    puts(result);
    return 0;
}