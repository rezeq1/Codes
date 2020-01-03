#include<iomanip> //setf ,width
#include<fstream> //ofstream,ifstream, fstream
#include<stdlib.h>  //exit
#include<iostream>  //cin,cout

using namespace std;
class Point{
	float x,y;
public:
	Point(float x=0,float y=0):x(x),y(y){}
	void SetData(float x,float y)
	{
		this->x=x;
		this->y=y;
	}
	float GetX(){return x;}
	float GetY(){return y;}
	friend ostream& operator <<(ostream& os,const Point& p)
	{	
		
			return os<<p.x<<'\t'<<p.y<<endl;
		
	}
	friend istream& operator >>(istream& input, Point& p)
	{	
		return input>>p.x>>p.y;
	}
	
};
int main()
{
ofstream ofs("dbPoints.txt",ios::app);
if(!ofs)
{
	cerr<<"Error of open file dbPoints.txt";
	exit(1);
}
Point  p(10,20); 
float x,y;
ofs<<p; //write 10,20//
p.SetData(20,30);
ofs<<p;//write 20,30
for(int i=0;i<2;i++){
	cout<<"enter 2 float values for Point ";
	cin>>x>>y;
	p.SetData(x,y);
	ofs<<p;//    write  standart input values //
}
ofs.close();
//search record
ifstream ifs("dbPoints.txt");
if(!ifs)
     {cerr<<"error...";exit(1);}
streampos pos;
while(ifs>>p){
	  if(p.GetX()==10)
	  	  break;
	  pos=ifs.tellg(); //pointer of read
}
cout<<endl<<endl;
// display of  record of x=20
ifs.seekg(pos,ios::beg);
ifs>>p;
cout<<" find ";
cout<<p;   // write to standart output 

cout<<endl<<" context of file "<<endl;
//display context of file 
ifs.seekg(0,ios::beg);
while(ifs>>p)
	cout<<p;
ifs.close();
}
