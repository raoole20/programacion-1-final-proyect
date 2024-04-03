#ifndef IDENTIFY_H
#define IDENTIFY_H

struct Identify
{
	int _id;
	Identify() { static int id = 1; _id = id++; }
};

#endif // IDENTIFY_H