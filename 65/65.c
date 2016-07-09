#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// bool isNumber(char* s) {
//     int length = strlen(s);
//     int i;
//     int point_number = 0;
//     int point_index = -1;
//     int e_number = 0;
//     int e_index = -1;
//     int negative_number = 0;
//     int negative_index[2] = {-1, -1};
//     int positive_number = 0;
//     int positive_index[2] = {-1, -1};
//     while (' ' == s[length - 1]) {
//         s[length - 1] = '\0';
//         length -= 1;
//     }
//     while (' ' == s[0]) {
//         length -= 1;
//         s += 1;
//     }
//     if (0 == length) {
//         return false;
//     }
//     for (i = 0; i < length; i++) {
//         if ((('0' > s[i]) || ('9' < s[i])) && (('.' != s[i]) && ('e' != s[i]) && ('-' != s[i]) && ('+' != s[i]))) {
//             return false;
//         }
//         if ('.' == s[i]) {
//             point_number += 1;
//             point_index = i;
//         } 
//         if ('e' == s[i]) {
//             e_number += 1;
//             e_index = i;
//         } 
//         if ('-' == s[i]) {
//             if (2 == negative_number) {
//                 return false;
//             }
//             negative_index[negative_number] = i;
//             negative_number += 1;
//         }
//         if ('+' == s[i]) {
//             if (2 == positive_number) {
//                 return false;
//             }
//             positive_index[positive_number] = i;
//             positive_number += 1;
//         }
//     }
//     if ((0 == point_number) && (0 == e_number) && (0 == negative_number) && (0 == positive_number) && (length != 0)) {
//         return true;
//     }
//     if ((1 < point_number) || (1 < e_number) || (2 < negative_number) || (2 < positive_number)) {
//         return false;
//     }
//     if (1 == negative_number) {
//         if (0 == e_number) {
//             if (0 != negative_index[0]) {
//                 return false;
//             }
//         } else {
//             if ((0 != negative_index[0]) && (e_index + 1 != negative_index[0])) {
//                 return false;
//             }
//         }
//     } else if (2 == negative_number) {
//         if (0 == e_number) {
//             return false;
//         } else {
//             if ((0 != negative_index[0]) || (e_index + 1 != negative_index[1])) {
//                 return false;
//             }
//         }
//     }
//     if (1 == positive_number) {
//         if (0 == e_number) {
//             if (0 != positive_index[0]) {
//                 return false;
//             }
//         } else {
//             if ((0 != positive_index[0]) && (e_index + 1 != positive_index[0])) {
//                 return false;
//             }
//         }
//     } else if (2 == positive_number) {
//         if (0 == e_number) {
//             return false;
//         } else {
//             if ((0 != positive_index[0]) || (e_index + 1 != positive_index[1])) {
//                 return false;
//             }
//         }
//     }
//     if ((-1 != e_index) && (-1 != point_index)) {
//         if ((0 != point_number) || (0 != negative_number)) {
//             if ((1 != point_index) && (2 != point_index)) {
//                 return false;
//             }
//         } else {
//             if ((1 != point_index) && (0 != point_index)) {
//                 return false;
//             }
//         }
//         if (e_index < point_index) {
//             return false;
//         }
//     }
//     if ((length - 1 == negative_index[negative_number - 1]) || (length - 1 == positive_index[positive_number - 1])) {
//         return false;
//     }
//     if ((0 == e_index) || (length - 1 == e_index)) {
//         return false;
//     }
//     if ((point_index != -1) && (length == 1)) {
//         return false;
//     }
//     if ((length == 2) && (point_index != -1) && ((0 != negative_number) || (0 != positive_number))) {
//         return false;
//     }
//     return true;
// }

bool isNumber(char* s) {
    bool dot = 0;
    bool e = 0;
    bool num = 0;
    while (*s == ' ') {
        s += 1;
    }
    if (*s == '-' || *s == '+') {
        s += 1 ;
    }
    while (*s) {
        switch(*s) {
            case '.':
                if (dot) {
                    return false;
                }
                else dot = 1;
                s += 1;
                break;
            case 'e':
                if (e) {
                    return false;
                }
                if (!num) {
                    return false;
                }
                else {
                    e = 1;
                    dot = 1;
                    num = 0;
                    s += 1;
                    if (*s == '-' || *s == '+') {
                        s += 1;
                    }
                }
                break;
            case '0':
            case'1':
            case'2':
            case'3':
            case'4':
            case'5':
            case'6':
            case'7':
            case'8':
            case'9':
                num = 1;
                s += 1;
                break;
            case ' ':
                do {
                    s += 1;
                } while (*s == ' ');
                if (*s) {
                    return false;
                }
                break;
            default:
                return false;
                break;
        }
    }
    if (!num) {
        return false;
    }
    return true;
}

int main() {
    char s[] = "+8 ";
    bool result;
    result = isNumber(s);
    printf("%d\n", result);
    return 0;
}