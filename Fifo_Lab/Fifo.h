#ifndef FIFO_H
#define FIFO_H

#define OK 0
#define NOK -1
#define ALREADY_INITIALIZED -2
#define BUFFER_FULL -3
#define BUFFER_UNINITALIZED -4
#define BUFFER_END 1

int NewFifo(int);
void DeleteFifo(void);
int Push(char);
int Pop(void);


#endif // !FIFO_H

