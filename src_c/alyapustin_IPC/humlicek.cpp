#include <math.h>
#include "cmplx.h"

_complex approx1(_complex), approx2(_complex, _complex), 
		approx3(_complex), approx4(_complex, _complex); 
	
double humlicek(double x, double y)
{
	_complex t, u, z;
	t.x = y;
	t.y = -x;
	double s;
		
    if(y >= 15.) // all points are in region I
		z = approx1(t); 
    else if(y<15. && y>=5.5) // points are in region I or II
	{	s = fabs(x) + y;
		if(s >= 15.) z = approx1(t); 
		else
		{	u = t*t;  z = approx2(t,u);  }
	 }
	else if(y<5.5 && y>0.75)
	{	s = fabs(x) + y;
		if(s >= 15.)  z = approx1(t); 
		else if(s < 5.5) z = approx3(t); 
		else
		{	u = t*t; z = approx2(t,u);  }
	 }
	else
	{	s = fabs(x) + y;
		if(s >= 15.) z = approx1(t); 
		else if(s < 15.0 && s>=5.5)
		{	u = t*t; z = approx2(t,u);  }
		else if(s<5.5 && y >= (0.195*fabs(x)-0.176) ) //region III
			z = approx3(t);
		else
		{	u = t*t;  
			s = exp(u.x);	
			z.x = s*cos(u.y);
			z.y = s*sin(u.y);
			z = z - approx4(t,u);
		 }
	 }
	return(z.x); 
}


_complex approx1(_complex t)
{
	return( (t * 0.5641896)/(0.5 + t*t) );	
}

_complex approx2(_complex t, _complex u)
{
 return( (t * (1.410474 + u*0.5641896))/(0.75 + u*(3+u)) );
}

_complex approx3(_complex t)
{
 return( (16.4955 + t * (20.20933 + t*(11.96482 + t*
         (3.778987 + t*0.5642236)))) / (16.4955 + t*(38.82363 + t*
         (39.27121 + t*(21.69274 + t*(6.699398 + t)))))  );
 }

_complex approx4(_complex t, _complex u)
{
 return( (t * (36183.31 - u*(3321.99 - u*(1540.787 - u*
		 (219.031 - u*(35.7668 - u*(1.320522 -u*0.5641896))))))) / 
         (32066.6 - u*(24322.8 - u*(9022.23 - u*(2186.18 - u*(364.219 -
         u*(61.5704 - u*(1.84144 - u)))))))  );
 }