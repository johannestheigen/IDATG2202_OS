/**
 * Program used to simulate a simple reader-writer problem.
 * Note: this cannot run directly here as it depends on the custom header
 * "common_threads.h" from another repository.
 *
 * @author Erik Hjelmås
 * @author Johannes Nupen Theigen (Modified to solve task)
 * @version 14.10.2025
 * @since 14.10.2025
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common_threads.h"

#ifdef linux
#include <semaphore.h>
#elif __APPLE__
#include "zemaphore.h"
#endif

#define MAX_MOD_READ 100
#define MAX_MOD_WRITE 100

typedef struct _rwlock_t {
  sem_t writelock;
  sem_t lock;
  sem_t turnstile;
  int readers;
} rwlock_t;

void rwlock_init(rwlock_t *lock) {
  lock->readers = 0;
  Sem_init(&lock->lock, 1);
  Sem_init(&lock->writelock, 1);
  Sem_init(&lock->turnstile, 1);
}
