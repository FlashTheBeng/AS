    #define GETVAL   0 /**< Returns the value of a semaphore. */
	#define SETVAL   1 /**< Sets the value of a semaphore.    */
	#define IPC_RMID 3 /**< Destroys a semaphore.            */

    PUBLIC int sys_semctl(int semid, int cmd, int val) {
    switch (cmd) {
    }