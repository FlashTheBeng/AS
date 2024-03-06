#include <nanvix/sem.h>


PUBLIC int sys_semget(int key){
    for(int i=0; i< nb_semaphore; i++){
        if(tab_semaphore[i].key == key) {
            return i;
        }
    }
    if(nb_semaphore >= SEM_MAX) return -1;
    
    for(int i=0; i<SEM_MAX; i++){
        if(tab_semaphore[i].is_valid == 0){
            tab_semaphore[i].is_valid = 1;
            tab_semaphore[i].key = key;
            tab_semaphore[i].counter = COUNTER_MAX;
            tab_semaphore[i].waiting_list_process = NULL;
            nb_semaphore += 1;
            return i;
        }
    }
    return -1;
    
}


