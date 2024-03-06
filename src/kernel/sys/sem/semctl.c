#include <nanvix/sem.h>

PUBLIC int sys_semctl(int semid, int cmd, int val) {
    for(int i=0; i<SEM_MAX; i++){
        if(tab_semaphore[i].key == semid){
            if(tab_semaphore[i].is_valid == 1){
                switch(cmd){
                    case GETVAL:
                        return tab_semaphore[i].counter;
                    case SETVAL:
                        tab_semaphore[i].counter = val;
                        break;
                    case IPC_RMID:
                        if(tab_semaphore[i].waiting_list_process == NULL){
                            tab_semaphore[i].is_valid = 0;
                            nb_semaphore -= 1;
                        }
                        break;
                    default:
                        return -1;
                }
            } 
        }
         
    }
    
    return 0;
}