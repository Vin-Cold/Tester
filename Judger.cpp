#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char *argv[]) {if(argc!=3) return 2;
	ifstream fin1(argv[1],ios::binary);ifstream fin2(argv[2],ios::binary);
	if(!fin1||!fin2) return 2;fin1.seekg(0,ios::end);fin2.seekg(0,ios::end);
	if(fin1.tellg()!=fin2.tellg()) return fin1.close(),fin2.close(),0;
	fin1.seekg(0,ios::beg);fin2.seekg(0,ios::beg);int r1,r2;char b1[512],b2[512];
	fin1.read(b1,512);fin2.read(b2,512);r1=fin1.gcount();r2=fin2.gcount();
	if(r1!=r2) return fin1.close(),fin2.close(),2;int i;
	while(!fin1.eof()) {
		for(i=0; i<r1; i++) if(b1[i]!=b2[i]) return fin1.close(),fin2.close(),0;
		fin1.read(b1,512);fin2.read(b2,512);r1=fin1.gcount();r2=fin2.gcount();
		if(r1!=r2) return fin1.close(),fin2.close(),2;
	}
	return fin1.close(),fin2.close(),1;
}
