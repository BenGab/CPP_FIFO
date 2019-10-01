#include<stdio.h>
#include<stdlib.h>
#include "Fifo.h"

static char *buffer = NULL;
static char *in = NULL;
static char *out = NULL;
static int bsize = 0;
static int currSize = 0;
static int readSize = 0;

int NewFifo(int size)
{
	if (buffer != NULL)
	{
		return ALREADY_INITIALIZED;
	}

	buffer = (char*) malloc(sizeof(char) * size);

	if (buffer == NULL)
	{
		return NOK;
	}
	
	in = buffer;
	bsize = size;
	return OK;
}

void DeleteFifo(void)
{
	if (buffer == NULL) 
	{
		return;
	}

	free(buffer);
	in = NULL;
	out = NULL;
}

int Push(char value)
{
	if (buffer == NULL)
	{
		return BUFFER_UNINITALIZED;
	}

	if (in == out)
	{
		return BUFFER_FULL;
	}

	*in = value;

	if (out == NULL)
	{
		out = buffer;
	}

	++in;
	++currSize;

	if (currSize >= bsize)
	{
		in = buffer;
		currSize = 0;
	}

	return OK;
}

int Pop(void)
{
	if (buffer == NULL)
	{
		return BUFFER_UNINITALIZED;
	}

	if (in == out)
	{
		return BUFFER_FULL;
	}


	printf("%d\n", *out);
	++out;
	++readSize;

	if (readSize >= bsize)
	{
		out = buffer;
		readSize = 0;
	}

	if (in == out)
	{
		return BUFFER_END;
	}

	return OK;

}
