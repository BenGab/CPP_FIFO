#include <stdio.h>
#include "Fifo.h"

int main()
{
	int rc = NewFifo(4);
	if (rc < 0)
	{
		DeleteFifo();
		return rc;
	}

	rc = Push('a');

	if (rc < 0)
	{
		DeleteFifo();
		return rc;
	}

	rc = Push('b');

	if (rc < 0)
	{
		DeleteFifo();
		return rc;
	}

	rc = Push('c');

	if (rc < 0)
	{
		DeleteFifo();
		return rc;
	}

	rc = Pop();

	if (rc < 0)
	{
		DeleteFifo();
		return rc;
	}

	rc = Pop();
	if (rc < 0)
	{
		DeleteFifo();
		return rc;
	}

	DeleteFifo();
	return rc;
}