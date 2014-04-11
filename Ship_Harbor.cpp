#pragma once
#include<vector>
#include<cstdlib>
#include<ctime>

using std::vector;

class Harbor;

class Ship
{
	double		between;
	double		idle;
	double		arrive;
	double		start;
	double		unload;
	double		wait;
	double		finish;
	double		harbor;
	friend	class	Harbor;

public:
	Ship();
};

class Harbor
{
	vector<Ship> ship;
	int		num;
	double	AVG_HARTIME;
	double	HARTIME;
	double	MAXHAR;
	double	AVG_WAITTIME;
	double	WAITTIME;
	double	MAXWAIT;
	double	IDLETIME;
	double	PER_IDLE;
public:
	Harbor();
	Harbor(int n);
	void	problem_init();
	void	problem_end();
	void	manage(Ship	s);
	double	avg_harbor_time();
	double	max_harbor();
	double	avg_wait_time();
	double	max_wait();
	double	per_idle();
};
