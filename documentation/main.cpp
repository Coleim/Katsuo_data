#include <unistd.h>
#include <sys/mman.h>

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
inline float endian_swap(float x)
{
     float a;
   unsigned char *dst = (unsigned char *)&a;
   unsigned char *src = (unsigned char *)&x;

   dst[0] = src[3];
   dst[1] = src[2];
   dst[2] = src[1];
   dst[3] = src[0];
   
   return a;
}



int main()
{ 
	FILE * pFile;
	pFile = fopen ("eta_410101.dta" , "r");
	if (pFile == NULL) perror ("Error opening file");

	int fd =  fileno(pFile);
	cout << fd << endl;

	int imt = 3600, jmt = 1500;
	int i=1;
	size_t sizet=sizeof(float)*imt*jmt;

 	 
	float *raw = (float*)mmap(0, sizet, PROT_WRITE | PROT_READ | PROT_EXEC, MAP_PRIVATE, fd, 0);

	if(raw == MAP_FAILED)
	{
		cout << " error mmap" << endl;
		return 2;
	} 

	
	cout << "---------------"<< endl;
	cout << "raw : " << raw << endl;
	cout << "sizeof(raw) : " << sizeof(raw) << endl;
	cout << "sizeof(raw) / sizeof(float) : " << sizeof(raw) / sizeof(float) << endl;
	
	
	float va = 0, vl = 0;
	int starti = 1*imt*jmt;
	int dec = 20;
	
	
	
	for (int i =  starti-imt; i >=0; i+= dec) {
		vl = raw[i];
		va = endian_swap(vl);
		cout <<  (va>-1000?" ":"*");
		if(i%imt == 0){
			 cout << endl;
			 i-= dec*imt - imt;
			 
			 }
    }

	return 0;
}




/*
int main()
{ 
	FILE * pFile;
	pFile = fopen ("u_0.5_4101.dta" , "r");
	//eta_410101.dta
	if (pFile == NULL) perror ("Error opening file");

	int fd =  fileno(pFile);
	cout << fd << endl;

	int imt = 720, jmt = 300, kmt = 54;
	int i=1;
	size_t sizet=sizeof(float)*imt*jmt*kmt;
 	 
	float * raw = (float*)mmap(0, sizet, PROT_WRITE | PROT_READ | PROT_EXEC, MAP_PRIVATE, fd, 0);

	if(raw == MAP_FAILED)
	{
		cout << " error mmap" << endl;
		return 2;
	} 
	

	
	cout << "---------------"<< endl;
	cout << "raw : " << raw << endl;
	cout << "sizeof(raw) : " << sizeof(raw) << endl;
	cout << "sizeof(raw) / sizeof(float) : " << sizeof(raw) / sizeof(float) << endl;

	float va = 0, vl = 0;
	int starti = 1*imt*jmt;
	int dec = 5;

	for (int i =  starti+imt*jmt; i >=starti; i-= dec) {
		vl = raw[i];
		va = endian_swap(vl);
		//cout << va << " - ";
		cout <<  (va>-1000?" ":"*");
		if(i%imt == 0){
			 cout << endl;
			 i-= dec*imt;
			 }
    }
	return 0;
}*/

