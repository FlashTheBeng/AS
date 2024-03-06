#include <nanvix/sem.h>

PUBLIC int sys_semop(int semid, int op){
    for(int i=0; i<SEM_MAX; i++){
        if(tab_semaphore[i].key == semid){
            if(op == 0 || tab_semaphore[i].is_valid == 0) return -1;
    
            disable_interrupts();
            
            //up
            if(op > 0){
                if(tab_semaphore[i].counter == 0){
                    wakeup(&tab_semaphore[i].waiting_list_process);
                } else {
                    tab_semaphore[i].counter++;
                }

            //down
            } else {
                if(tab_semaphore[i].counter > 0){
                    tab_semaphore[i].counter--;
                } else{
                    sleep(&tab_semaphore[i].waiting_list_process, curr_proc->priority);
                }
            }
            enable_interrupts();
            return 0;
        } 
    }
    return -1;
    
}