//线段与线段 
double cross(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
	double a=(x3-x1)*(y4-y1)-(y3-y1)*(x4-x1); 
	double b=(x3-x2)*(y4-y2)-(y3-y2)*(x4-x2);
	return a*b; 
}
//点与线段
double mul(double x,double y,double x1,double y1,double x2,double y2){
	double a=(x1-x)*(y2-y)-(y1-y)*(x2-x); 
	return a; 
}
//线段与线段 
double mult(Point sp, Point ep, Point op){
    return (sp.x-op.x)*(ep.y-op.y) - (ep.x-op.x)*(sp.y-op.y);
}

bool isInter(Point s1, Point e1, Point s2, Point e2){
    if( min(s1.x, e1.x) <= max(s2.x, e2.x) &&
        min(s1.y, e1.y) <= max(s2.y, e2.y) &&
        min(s2.x, e2.x) <= max(s1.x, e1.x) &&
        min(s2.y, e2.y) <= max(s1.y, e1.y) &&
        mult(s2, e2, s1) * mult(s2, e2, e1) <= 0 &&
        mult(s1, e1, s2) * mult(s1, e1, e2) <= 0)
        return true;
    return false;
}
//node
struct node{
	double x,y;
};

double cross(node a,node b,node c,node d){
	double a1=(c.x-a.x)*(d.y-a.y)-(c.y-a.y)*(d.x-a.x);
	double a2=(c.x-b.x)*(d.y-b.y)-(c.y-b.y)*(d.x-b.x);
	return a1*a2;
}

double mul(node a,node p1,node p2){
	return (p1.x-a.x)*(p2.y-a.y)-(p1.y-a.y)*(p2.x-a.x);
} 
