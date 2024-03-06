#ifndef NANVIX_SEM_H_
#define NANVIX_SEM_H_
    #include <nanvix/const.h>
    #include <nanvix/pm.h>

    typedef struct {
        int is_valid;
        int counter;
        int key;
        struct process** waiting_list_process;
    } semaphore;

    #define SEM_MAX 100
    #define COUNTER_MAX 5
    #define GETVAL   0
    #define SETVAL   1
    #define IPC_RMID 2

    EXTERN int nb_semaphore;
    EXTERN semaphore tab_semaphore[SEM_MAX];

    EXTERN int sys_semget(int);
    EXTERN int sys_semctl(int, int, int);
    EXTERN int sys_semop(int,int);

#endif
