#include <iostream>

struct Stack {
    int arr[100];
    int top;
};

Stack stack_new() {
    Stack s;
    s.top = 0;
    return s;
}

bool stack_is_empty(Stack const &s) {
    return (s.top == 0);
}

bool stack_is_full(Stack const &s) {
    return (s.top == 100);
    }

Stack& stack_push(Stack &s, int val) {
    s.arr[s.top++] = val;
    return s;
}

int stack_pop(Stack &s) {
    return s.arr[--s.top];
}

int main(){
    int n;
    n = 7;
    std::cout<<*count_ones(n)<<std::endl;
    return 0;} 