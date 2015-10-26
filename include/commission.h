#ifndef ELIWAFBELIGFLI
#define ELIWAFBELIGFLI

#include <vector>
#include <tuple>
using namespace std;

#define CMS_ERROR -1

#define TERM_ERROR -8
#define LOCK_ERROR -7
#define STOCK_ERROR -6
#define BARREL_ERROR -5
#define OK 3

int cms_error_code = OK;

double retrieve(vector<tuple<int,int,int>>);

double countCms(int locks,int stocks,int barrels);


#endif
