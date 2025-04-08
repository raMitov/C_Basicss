#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void * hello_fun()
{
    printf("Hello World\n");
    return NULL;

}
int main()
{
//pthread_create(pthread_t*thread, const pthread_attr_t*attr, void*(start_routie)(void*),void*arg);
//the first argument
//an ingiger used to identify the thread in the system
//on sucessful creation pthread_create() stores the ID of the thread in the location refferenced by thread
//the second argument..
//you can specify thread attributes object or null for the default values
//examples of attributes that can be specified include detatched state scheduling policy scope stack addre and stack size
//the third argment is name of the function that the thread will execute once its created
//the fourth argument is used to pass arguments to the function(start_routine)
//a pointer cast of type void is required
//NULL may be used if no argument is to be passed
//to apss multiple arguments you woyld need to use a pointer to a structure
//
//pthread_join
//a join is performed when one wants to wait for a thread to finish
//used to link the current tread process to another thread
//a thread calling routine may launch multiple threads then wait for them to finish to get the results
//a call to pthread_join blocks the calling thread until the thread with the identifier equal to the furst argment trminates
//makes the progrram stop in order to wait for the end of the selected thread
//
//int pthread_join(pthread_t thread, void **value_ptr);
//the first argument is the thread id of the thread you want to wait for
//if the second argument is not null this value is passed to pthread_exit() by the terinating thread
//
//pthread_exit(void *value_ptr);
pthread_t thread;
pthread_create(&thread, NULL, hello_fun, NULL);
pthread_join(thread, NULL);
pthread_exit(NULL);
return 0;
}
