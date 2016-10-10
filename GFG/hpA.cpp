//FB-01
#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define Point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;

double orientation(Point p, Point q, Point r)
{
    double val = (q.S - p.S) * (r.F - q.F) -
              (q.F - p.F) * (r.S - q.S);
 
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
}

vector<Point> convexHull(vector<Point> points)
{
    int n = points.size();
    vector<Point> hull;
 
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].F < points[l].F)
            l = i;
 
    int p = l, q;
    do
    {
        hull.push_back(points[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
          
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
 
        p = q;
 
    } while (p != l);  

    return hull;
}

int main()
{
	int n;
	double a,b;
	cin >> n ; 
	vector<Point> v;
	fr(i,0,n)
	{
		cin >> a >> b;
		v.pb(mp(a,b));
	}

	if(n==2)
	{
		double dist = (v[0].F-v[1].F)*(v[0].F-v[1].F) + (v[0].S-v[1].S)*(v[0].S-v[1].S);
		cout << std::setprecision(4) << std::fixed << sqrt(dist/2) << endl;
	}
	else
	{
		//Find Convex hull
		vector<Point> hull = convexHull(v);
		double minsqr = 1000000000000;
		//Iterate over all the edges of hull
		fr(i,0,hull.size())
		{
			double sine,cosine;
			if(hull[i].F-hull[(i+1)%hull.size()].F==0)
			{
				sine = 1; 	
				cosine = 0; 
			}
			else
			{
				double tane = (hull[i].S-hull[(i+1)%hull.size()].S)/(hull[i].F-hull[(i+1)%hull.size()].F) ; 
				sine = tane/(sqrt(1+tane*tane)); 	
				cosine = 1/(sqrt(1+tane*tane));  	
			}
			double xmax=-1001,xmin=1001;
			double ymax=-1001,ymin=1001;
			fr(j,0,hull.size())
			{
				double xnew = hull[j].F*cosine - hull[j].S*sine;
				double ynew = hull[j].F*sine + hull[j].S*cosine;
				if(xnew < xmin)
					xmin = xnew;
				if(xnew > xmax)
					xmax = xnew;
				if(ynew < ymin)
					ymin = ynew;
				if(ynew > ymax)
					ymax = ynew;
			} 
			double dist = (xmax-xmin)*(xmax-xmin) + (ymax-ymin)*(ymax-ymin); 
			if(dist < minsqr)
				minsqr = dist;
		}
		cout << std::setprecision(4) << std::fixed << sqrt(minsqr/2) << endl;
	}
}
