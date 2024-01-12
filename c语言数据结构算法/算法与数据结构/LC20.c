//#include<stdlib.h>
//#include<stdio.h>
//
//typedef struct Stack {
//    char* date;
//    int top, size;
//}Stack;
//
//Stack* initStack(n) {
//    Stack* s = (Stack*)malloc(sizeof(Stack));
//    s->date = (char*)malloc(sizeof(char) * n);
//    s->top = -1;
//    s->size = n;
//    return s;
//}
//
//void push(Stack* s, int val) {
//    s->date[s->top + 1] = val;
//    s->top++;
//}
//
//void pop(Stack* s) {
//    s->top--;
//}
//
//void clear(Stack* s) {
//    free(s->date);
//    free(s);
//}
//
//int isValid(char* s) {
//    int sz = (int)strlen(s);
//    Stack* q = initStack(sz + 2);
//    int i = 0, flag = 1;
//    for (i = 0; i < sz; i++) {
//        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
//            push(q, s[i]);
//        }
//        else {
//            if (q->top == -1) {
//                clear(q);
//                return 0;
//            }
//            switch (s[i]) {
//            case ')':
//                if (q->date[q->top] == '(') {
//                    pop(q);
//                }
//                else {
//                    flag = 0;
//                }
//                break;
//            case ']':
//                if (q->date[q->top] == '[') {
//                    pop(q);
//                }
//                else {
//                    flag = 0;
//                }
//                break;
//            case '}':
//                if (q->date[q->top] == '{') {
//                    pop(q);
//                }
//                else {
//                    flag = 0;
//                }
//                break;
//            }
//        }
//        if (flag == 0) {
//            clear(q);
//            return 0;
//        }
//
//    }
//
//    if (q->top == -1) {
//        clear(q);
//        return 1;
//    }
//    clear(q);
//    return 0;
//}
//
//int main() {
//    char s[] = "]";
//    isValid(s);
//    return 0;
//}