#include<iostream>
#include"Ship_Harbor.h"

using namespace std;

int main()
{
	int n;
	cin >> n;
	srand(time(NULL));
	Harbor harbor(n);
	harbor.problem_init();
	for (int i = 0; i < n;i++)
	{
		Ship s;
		harbor.manage(s);
	}
	harbor.problem_end();
	system("CLS");
	cout <<"平均在港时间:"<< harbor.avg_harbor_time() << endl
		<<"平均等待时间:"<< harbor.avg_wait_time() << endl
		<<"港口闲置比例:"<< harbor.per_idle() << endl
		<<"最长在港时间:"<< harbor.max_harbor() << endl
		<<"最长等待时间:"<< harbor.max_wait()<<endl;
	return 0;
}
