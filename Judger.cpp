#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[]) {
	if(argc!=3) {
		//cerr <<"�����и�ʽ����ʹ�ø�ʽ��\n������ �ļ���1 �ļ���2\n";
		return 2;
	}
	ifstream fin1(argv[1],ios::binary);
	ifstream fin2(argv[2],ios::binary);
	if(!fin1 || !fin2) {
		//cerr <<"���ļ�ʱ���������ļ�����\n" <<argv[1] <<"��\n" <<argv[2] <<endl;
		return 2;
	}
	fin1.seekg(0, ios::end);
	fin2.seekg(0, ios::end);
	if(fin1.tellg()!=fin2.tellg()) {
		fin1.close();
		fin2.close();
		//cout <<"Dif\n";
		return 0;
	}
	fin1.seekg(0,ios::beg);
	fin2.seekg(0,ios::beg);
	int r1,r2;
	char b1[512],b2[512];
	fin1.read(b1,512);
	fin2.read(b2,512);
	r1=fin1.gcount();
	r2=fin2.gcount();
	if(r1!=r2) {
		fin1.close();
		fin2.close();
		//cerr <<"���ļ�ʱ����\n";
		return 2;
	}
	int i;
	while(!fin1.eof()) {
		for(i=0; i<r1; i++) {
			if(b1[i]!=b2[i]) {
				fin1.close();
				fin2.close();
				//cout <<"Dif\n";
				return 0;
			}
		}
		fin1.read(b1,512);
		fin2.read(b2,512);
		r1=fin1.gcount();
		r2=fin2.gcount();
		if(r1!=r2) {
			fin1.close();
			fin2.close();
			//cerr <<"���ļ�ʱ����\n";
			return 2;
		}
	}
	fin1.close();
	fin2.close();
	//cout <<"Same\n";
	return 1;
	//system("pause");
}
