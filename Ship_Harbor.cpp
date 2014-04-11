#include"Ship_Harbor.h"

Ship::Ship()
{
	between = 15 + rand() % 130;
	unload	= 45 + rand() % 45;
}

Harbor::Harbor()
{
	HARTIME		= 0;
	MAXHAR		= 0;
	WAITTIME	= 0;
	MAXWAIT		= 0;
	IDLETIME	= 0;
}

Harbor::Harbor(int n) :num(n)
{
	HARTIME		= 0;
	MAXHAR		= 0;
	WAITTIME	= 0;
	MAXWAIT		= 0;
	IDLETIME	= 0;
}

void Harbor::manage(Ship s)
{
	vector<Ship>::iterator it = ship.end() - 1;
	s.arrive = it->arrive + s.between;
	double	time_diff = s.arrive - it->finish;
	if (time_diff >= 0)
	{
		s.idle = time_diff;
		s.wait = 0;
	}
	else
	{
		s.wait = -time_diff;
		s.idle = 0;
	}
	s.start		= s.arrive	+ s.wait;
	s.finish	= s.start	+ s.unload;
	s.harbor	= s.wait	+ s.unload;
	HARTIME		= HARTIME	+ s.harbor;
	WAITTIME	= WAITTIME	+ s.wait;
	IDLETIME	= IDLETIME + s.idle;
	if (s.harbor >= MAXHAR)
		MAXHAR = s.harbor;
	if (s.wait >= MAXWAIT)
		MAXWAIT = s.wait;
	ship.push_back(s);
}

void Harbor::problem_init()
{
	Ship s;
	HARTIME		= s.unload;
	MAXHAR		= s.unload;
	s.arrive	= s.between;
	IDLETIME	= s.arrive;
	s.finish	= s.arrive + s.unload;
	ship.push_back(s);
}

void Harbor::problem_end()
{
	AVG_HARTIME		= HARTIME / num;
	AVG_WAITTIME	= WAITTIME / num;
	PER_IDLE		= IDLETIME / (ship.end()-1)->finish;
}

double Harbor::avg_wait_time()
{
	return AVG_WAITTIME;
}

double Harbor::avg_harbor_time()
{
	return AVG_HARTIME;
}

double Harbor::per_idle()
{
	return PER_IDLE;
}

double Harbor::max_harbor()
{
	return MAXHAR;
}

double Harbor::max_wait()
{
	return MAXWAIT;
}
