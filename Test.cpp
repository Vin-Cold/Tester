#include<map>
#include<set>
#include<list>
#include<queue>
#include<vector>
#include<string>
#include<time.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define reg register
#define ll long long
#define inf 2147483647
#define lowbit(x) ((x)&-(x))
#define abs(x) ((x)<0?-(x):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define isd(c) ('0'<=(c)&&(c)<='9')
#define isa(c) ('a'<=(c)&&(c)<='z')
#define isA(c) ('A'<=(c)&&(c)<='Z')
#define ckmax(a,b) ((a)=max((a),(b)))
#define ckmin(a,b) ((a)=min((a),(b)))
#define swap(a,b) ((a)==(b)?(a)=(b):((a)^=(b)^=(a)^=(b)))
using namespace std;
template<typename T> inline void read(T&x){T f=1;x=0;char c;
    for (c=getchar(); !isd(c); c=getchar()) f=(c=='-')?-1:f;
    for (; isd(c); c=getchar()) x=(x<<3)+(x<<1)+(c^48);x*=f;
}
template<typename T> inline void wt(T x,char c='\0'){char ch[(sizeof(T)+1)<<1];if (x<0) x=-x,putchar('-');
    int t=-1; do ch[++t]=x%10+'0',x/=10; while(x); do putchar(ch[t]); while(t--); if (c!='\0') putchar(c);
}
int head,tail;
char filename[1024],suffix[2][100],judge[1024],del[1024],produce[1024],username[101][1024];
int T,mark[101],usernum,flmk[101][101];
inline void clear(){
	head=0,tail=0;
	memset(mark,0,sizeof(mark));
	memset(filename,0,sizeof(filename));
	memset(suffix,0,sizeof(suffix));
	memset(judge,0,sizeof(judge));
	memset(del,0,sizeof(del));
	memset(produce,0,sizeof(produce));
}
int main(){
    FILE*in=fopen("testsettings.txt","r");
    fscanf(in,"%d",&usernum);
    for (int i=1; i<=usernum; ++i)fscanf(in,"%s",username[i]);
    fscanf(in,"%d",&T);
    for (int t=1; t<=T; ++t){
    	clear(); fscanf(in,"%s",filename); fscanf(in,"%d %d",&head,&tail);
    	fscanf(in,"%s",suffix[0]);fscanf(in,"%s",suffix[1]);puts(filename);
    	for (int j=1; j<=usernum; ++j){
    		puts(username[j]);int fl=0;time_t a,b;
    		for (int tmp=0,i=head; i<=tail; ++i){
    			sprintf(produce,"source\\%s\\%s.exe<data\\%s\\%s%d.in>data\\%s\\%s%d.%s",
                 username[j],filename,filename,filename,i,filename,filename,i,suffix[0]),
                printf("%d:",++tmp),a=clock(),system(produce),b=clock();
                sprintf(del,"data\\%s\\%s%d.%s",filename,filename,i,suffix[0]),
                memset(produce,0,sizeof(produce));
				sprintf(judge,"Judger.exe data\\%s\\%s%d.%s data\\%s\\%s%d.%s",
                  filename,filename,i,suffix[0],filename,filename,i,suffix[1]);
    			mark[i]=system(judge),
                printf("%s",mark[i]==0?"Wrong Answer":mark[i]==1?"Accept":"File Error"),
                remove(del),fl+=(mark[i]==1);
                if (mark[i]<2) printf("  Times:%dms\n",(int)b-(int)a);else putchar('\n');
    		}
			printf("marks:%d\n",(fl*100/(tail-head+1)/100)*100);
			flmk[j][t]=(fl*100/(tail-head+1)/100)*100;
    	}
    }
	FILE*out=fopen("Final.txt","wt+");
	for (int i=1,j; i<=usernum; ++i)
		for (printf("%s:",username[i]),fprintf(out,"%s:",username[i]),j=1; j<=T; ++j)
            wt(flmk[i][j]," \n"[j==T]),fprintf(out,"%d%c",flmk[i][j]," \n"[j==T]);
    return 0;
}
