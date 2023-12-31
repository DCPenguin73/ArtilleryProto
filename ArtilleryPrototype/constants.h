#pragma once
#include <math.h>
#include "Database.h"

const double PI = (2 * acos(0.0));
const double WEIGHT = 46.7;   // Weight in KG
const double  TIME_INTERVAL = .01;

double surface_area = (154.89 / 2000) * (154.89 / 2000) * PI;
double domain1[] = { 0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000 };
double range1[] = { 9.807, 9.804, 9.801, 9.797, 9.794, 9.791, 9.788, 9.785, 9.782, 9.779, 9.776, 9.761, 9.745, 9.730 };
Database gravity = Database(domain1, range1, 14);

double domain2[] = { 0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 40000, 50000, 60000, 70000, 80000 };
double range2[] = { 1.2250000, 1.1120000, 1.0070000, 0.9093000, 0.8194000, 0.7364000, 0.6601000, 0.5900000, 0.5258000, 0.4671000, 0.4135000, 0.1948000, 0.0889100, 0.0400800, 0.0184100,
0.0039960, 0.0010270, 0.0003097, 0.0000828, 0.0000185 };
Database airDensity = Database(domain2, range2, 20);

double domain3[] = { 0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 40000 };
double range3[] = { 340, 336, 332, 328, 324, 320, 316, 312, 308, 303, 299, 295, 295, 295, 305, 324 };
Database speedSound = Database(domain3, range3, 16);

double domain4[] = { 0.300, 0.500, 0.700, 0.890, 0.920, 0.960, 0.980, 1.000, 1.020, 1.060, 1.240, 1.530, 1.990, 2.870, 2.890, 5.000 };
double range4[] = { 0.1629, 0.1659, 0.2031, 0.2597, 0.3010, 0.3287, 0.4002, 0.4258, 0.4335, 0.4483, 0.4064, 0.3663, 0.2897, 0.2297, 0.2306, 0.2656 };
Database dragCoef = Database(domain4, range4, 16);