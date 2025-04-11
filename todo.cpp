#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    int i;
    for(i=0; i<MAX_TASKS; i++) {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    int i;
    for(i=0; i<MAX_TASKS; i++) {
        delete tasks[i];
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int i = 0, L;
    L = string_length(src);
    for(i=0; i<L; i++) {
        dest[i] = src[i];
    }
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if(size >= MAX_TASKS) {
        throw std::range_error("Invalid Addition");
        return;
    }
    int L = string_length(task);
    tasks[size] = new char [L+1];
    tasks[size][L] = '\0';
    
    string_copy(tasks[size], task);
    
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if(size == 0 || index < 0 || index >= size) {
        throw std::range_error("Invalid Removal");
        return;
    }
    int i;
    for(i = index; i<size-1; i++) {
        string_copy(tasks[i], tasks[i+1]);
    }
    delete tasks[size - 1];
    tasks[size - 1] = nullptr;
    size--;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;    
    const char **res = new const char* [size];
    int i, L;
    for(i=0; i<size; i++) {
        L = string_length(tasks[i]);
        char *tmp = new char[L+1];
        tmp[L] = '\0';
        
        string_copy(tmp, tasks[i]);
        res[i] = tmp;
    }
    return res;
}