#include <nanvix/pm.h>

typedef struct {
    int key;
    int accesNumber;
    

} semaphore;

#define MAX_SEM 256
PRIVATE semaphore SEMAPHORES[MAX_SEM];
