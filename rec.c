#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>//int fdA[100];
#if 0
#define deB printf(" joes5 %s %s %d \n", __func__, __FILE__, __LINE__);
#define deBV(fmt, ...) do{printf(" joes5 %s %s %d " fmt " \n", __FILE__, __func__, __LINE__,##__VA_ARGS__);}while(0)
#define deBVS(fmt, ...) do{printf(" " fmt " \n", ##__VA_ARGS__);}while(0)
#else
#define deB 
#define deBV(fmt, ...) 
#define deBVS(fmt, ...) 
#endif
void WrkProcess(int nsig){       fflush(stdout);        }
//int main3(int argc,char *argv[])
static char fArr[256][256] ={0};
static int main0_r(char *path){
	int i=0;
	FILE *pF = fopen(path, "rb");
	if(pF){//printf(" gg \n");
		while(fgets(fArr[i],256, pF)){						//fArr[i][l-1] = 0;			//deBV(" %s ", fArr[i]);
			int l = strlen(fArr[i]);
			if(l>=1){
				int n=l-1;
				if(isspace(fArr[i][n]))
					fArr[i][n] = 0;			}
			if(l>=2){
				int n=l-2;
				if(isspace(fArr[i][n]))
					fArr[i][n] = 0;			}
			if(fArr[i][0]){ deBV(" %s ", fArr[i]);
				i++; }else deBV(" null "); }
		fclose(pF);	}
	return 0; }
int main3(char *i_f, int curr_mode){
	int i=0;
	struct sigaction act,oldact;
        act.sa_handler  = WrkProcess;
        act.sa_flags = SA_NODEFER;//act.sa_flags = SA_NODEFER | SA_RESETHAND; //kill -2 pidx
	sigaction(SIGINT,&act,&oldact);// ctrl+d，第一次不会导致程序的结束。而是继续执行，当用户再次执行ctrl+d的时候，程序采用结束。 改动为：act.sa_flags = SA_NODEFER； 无论对ctrl+d操作多少次，程序都不会结束 SIGKILL|SIGINT|SIGSTOP,&act,&oldact);//
/*        struct sigaction ignact={0};//        memset(&ignact, 0, sizeof(ignact));
        ignact.sa_handler = SIG_IGN;
        sigaction(SIGINT, &ignact, &intact);
        sigaction(SIGQUIT, &ignact, &quitact);     */
        #if 0
        char *sys[256] ={
        "/sys/devices/virtual/thermal/thermal_zone6/temp", //case_therm
"/sys/devices/virtual/thermal/thermal_zone4/temp",// xo_therm
//"/sys/devices/virtual/thermal/thermal_zone0/temp", // bq27541 is equal to battery
//"/sys/devices/virtual/thermal/thermal_zone1/temp", // bms always 25000
"/sys/devices/virtual/thermal/thermal_zone10/temp",//tsens_tz_sensor3 
"/sys/devices/virtual/thermal/thermal_zone11/temp",//tsens_tz_sensor4 cpu4 
"/sys/devices/virtual/thermal/thermal_zone12/temp",//tsens_tz_sensor5 cpu5 
"/sys/devices/virtual/thermal/thermal_zone13/temp",//tsens_tz_sensor6 cpu6
"/sys/devices/virtual/thermal/thermal_zone14/temp",//tsens_tz_sensor7 cpu7 
"/sys/devices/virtual/thermal/thermal_zone15/temp",//tsens_tz_sensor8 L2_cache_1
"/sys/devices/virtual/thermal/thermal_zone16/temp",//tsens_tz_sensor9 cpu0-cpu1-cpu2-cpu3
"/sys/devices/virtual/thermal/thermal_zone17/temp",// tsens_tz_sensor10 gpu
"/sys/devices/virtual/thermal/thermal_zone18/temp",//pm8950_tz
"/sys/devices/virtual/thermal/thermal_zone19/temp", // pm8004_tz
//"/sys/devices/virtual/thermal/thermal_zone2/temp",// battery
"/sys/devices/virtual/thermal/thermal_zone20/temp", // pa_therm0
/*
"/sys/devices/virtual/thermal/thermal_zone21/temp",// LLM_IA72 always 0
"/sys/devices/virtual/thermal/thermal_zone22/temp",// THRM_72-0 always 0
"/sys/devices/virtual/thermal/thermal_zone23/temp",// THRM_72-1 always 0
"/sys/devices/virtual/thermal/thermal_zone24/temp",// THRM_72-2 always 0
"/sys/devices/virtual/thermal/thermal_zone25/temp",// THRM_72-3  always 0
"/sys/devices/virtual/thermal/thermal_zone26/temp",// THRM_53-0 always 0
"/sys/devices/virtual/thermal/thermal_zone27/temp",// THRM_53-1  always 0
"/sys/devices/virtual/thermal/thermal_zone28/temp",// THRM_53-2  always 0
"/sys/devices/virtual/thermal/thermal_zone29/temp",// THRM_53-3  always 0
*/
"/sys/devices/virtual/thermal/thermal_zone3/temp", // pa_therm1
"/sys/devices/virtual/thermal/thermal_zone30/temp",// wsatz.11
"/sys/devices/virtual/thermal/thermal_zone5/temp", // xo_therm_buf
"/sys/devices/virtual/thermal/thermal_zone7/temp",// tsens_tz_sensor0 
"/sys/devices/virtual/thermal/thermal_zone8/temp",// tsens_tz_sensor1
"/sys/devices/virtual/thermal/thermal_zone9/temp", //tsens_tz_sensor2 pop_mem
"/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq",
"/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq",
"/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq",
"/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq",
"/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_cur_freq",
"/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_cur_freq",
"/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_cur_freq",
"/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_cur_freq",
"/sys/class/power_supply/battery/current_now",
"/sys/class/power_supply/battery/temp",
"/sys/class/power_supply/battery/capacity",
0        }; // /sys/class/power_supply/bq27542/energy_now  /sys/class/power_supply/bq27542/charge_full

char *sys[256] ={
        "case_therm:/sys/devices/virtual/thermal/thermal_zone6/temp", //case_therm
"xo_therm:/sys/devices/virtual/thermal/thermal_zone4/temp",// xo_therm
//"/sys/devices/virtual/thermal/thermal_zone0/temp", // bq27541 is equal to battery
//"/sys/devices/virtual/thermal/thermal_zone1/temp", // bms always 25000
"tsens_tz_sensor3:/sys/devices/virtual/thermal/thermal_zone10/temp",//tsens_tz_sensor3 
"cpu4:/sys/devices/virtual/thermal/thermal_zone11/temp",//tsens_tz_sensor4 cpu4 
"cpu5:/sys/devices/virtual/thermal/thermal_zone12/temp",//tsens_tz_sensor5 cpu5 
"cpu6:/sys/devices/virtual/thermal/thermal_zone13/temp",//tsens_tz_sensor6 cpu6
"cpu7:/sys/devices/virtual/thermal/thermal_zone14/temp",//tsens_tz_sensor7 cpu7 
"L2_cache_1:/sys/devices/virtual/thermal/thermal_zone15/temp",//tsens_tz_sensor8 L2_cache_1
"cpu0~3:/sys/devices/virtual/thermal/thermal_zone16/temp",//tsens_tz_sensor9 cpu0-cpu1-cpu2-cpu3
"gpu:/sys/devices/virtual/thermal/thermal_zone17/temp",// tsens_tz_sensor10 gpu
"pm8950_tz:/sys/devices/virtual/thermal/thermal_zone18/temp",//pm8950_tz
"pm8004_tz:/sys/devices/virtual/thermal/thermal_zone19/temp", // pm8004_tz
//"/sys/devices/virtual/thermal/thermal_zone2/temp",// battery
"pa_therm0:/sys/devices/virtual/thermal/thermal_zone20/temp", // pa_therm0
"pa_therm1:/sys/devices/virtual/thermal/thermal_zone3/temp", // pa_therm1
"wsatz.11:/sys/devices/virtual/thermal/thermal_zone30/temp",// wsatz.11
"xo_therm_buf:/sys/devices/virtual/thermal/thermal_zone5/temp", // xo_therm_buf
"tsens_tz_sensor0:/sys/devices/virtual/thermal/thermal_zone7/temp",// tsens_tz_sensor0 
"tsens_tz_sensor1:/sys/devices/virtual/thermal/thermal_zone8/temp",// tsens_tz_sensor1
"pop_mem:/sys/devices/virtual/thermal/thermal_zone9/temp", //tsens_tz_sensor2 pop_mem
"cpu0:/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq",
"cpu1:/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq",
"cpu2:/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq",
"cpu3:/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq",
"cpu4:/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_cur_freq",
"cpu5:/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_cur_freq",
"cpu6:/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_cur_freq",
"cpu7:/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_cur_freq",
"battery:/sys/class/power_supply/battery/current_now",
"battery:/sys/class/power_supply/battery/temp",
"battery:/sys/class/power_supply/battery/capacity",
"battery:/sys/class/power_supply/battery/energy_now",
"battery:/sys/class/power_supply/battery/charge_full",
0        }; 
#endif
char *sys[256]={0};
char *sysComm[256] ={0};deB
/*        char *sys[256] ={
			"/sys/devices/virtual/thermal/thermal_zone6/temp",
			"/sys/devices/virtual/thermal/thermal_zone4/temp",
			"/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq",
			"/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq",
			"/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq",
			"/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq",
			"/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_cur_freq",
			"/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_cur_freq",
			"/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_cur_freq",
			"/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_cur_freq",
			"/sys/class/power_supply/battery/current_now",
			"/sys/class/power_supply/battery/temp",
			"/sys/class/power_supply/battery/capacity",
			0,		};*/
        if(i_f){
        		main0_r(i_f);deB
        		i=0;
        		while(fArr[i][0]){
        			sys[i] = fArr[i];		//printf("%s\t", sys[i]);
        			i++;	}
        		sys[i]  = 0;deB
	}else if(curr_mode){//only record current,lcd brightness,usb online
		deB
		char *sysL[512] ={
			"curr", "/sys/class/power_supply/battery/current_now", //case_therm
			"brightness", "/sys/devices/soc.0/1a00000.qcom,mdss_mdp/qcom,mdss_fb_primary.208/leds/lcd-backlight/brightness",// xo_therm  //"/sys/devices/virtual/thermal/thermal_zone0/temp", // bq27541 is equal to battery //"/sys/devices/virtual/thermal/thermal_zone1/temp", // bms always 25000
			"usb", "/sys/class/power_supply/usb/online",		        }; 
		i=0;deB
		while(sysL[i*2] && sysL[i*2+1] && sysL[i*2][0] && sysL[i*2+1][0]){ deBV(" %d ", i);
			sys[i] = sysL[i*2+1];
			sysComm[i] = sysL[i*2]; deBV(" %d ", i);
			i++;	} deB
		sys[i] = 0;
		// printf("time \t");
		i = 0;
		// while(sysComm[i]){
		// 	printf("%s \t", sysComm[i]);//printf("%s \t", sys[i]);
		// 	i++;	}		printf("\n");
		printf("time \t");
		i = 0;
		while(sys[i]){ printf("%s \t", strrchr(sys[i], '/')+1);
			i++;	}		printf("\n");		
		while(1){			time_t epoch_time;			struct tm *tm_p;
			epoch_time = time( NULL );
			tm_p = localtime( &epoch_time );
			printf("%.2d:%.2d:%.2d_%.2d ",  tm_p->tm_hour, tm_p->tm_min, tm_p->tm_sec, tm_p->tm_mday);
			i=0;
			while(sys[i]){			char s[64];
				int fd = open(sys[i], O_RDONLY);
				if(fd >= 0){
					s[0]=0;
					ssize_t n = read(fd, s, 64);
					if(s[n-1]=='\n')
						s[n-1]=0;
					if(i==0){ //char s1[256];
						s[strlen(s)-3] = 0;//sscanf(s1,"%s000", s);
						printf("%s ", s);
					}else
						printf("%s ", s);
					close(fd);
				}else{
					printf("_ ");				//printf(" err:%s ", sys[i]);
				}
				i++;		}
			printf("\n"); //fflush(stdout);
			static int rec_sn = 0;
			if(rec_sn++ > 30){ rec_sn=0;
				fflush(stdout);			
			}
			sleep(1);	}
	}else{deB
		char *sysL[512] ={
			"case_therm", "/sys/devices/virtual/thermal/thermal_zone6/temp", //case_therm
			"xo_therm", "/sys/devices/virtual/thermal/thermal_zone4/temp",// xo_therm  //"/sys/devices/virtual/thermal/thermal_zone0/temp", // bq27541 is equal to battery //"/sys/devices/virtual/thermal/thermal_zone1/temp", // bms always 25000
			"tsens_tz_sensor3", "/sys/devices/virtual/thermal/thermal_zone10/temp",//tsens_tz_sensor3 
			"cpu4", "/sys/devices/virtual/thermal/thermal_zone11/temp",//tsens_tz_sensor4 cpu4 
			"cpu5", "/sys/devices/virtual/thermal/thermal_zone12/temp",//tsens_tz_sensor5 cpu5 
			"cpu6", "/sys/devices/virtual/thermal/thermal_zone13/temp",//tsens_tz_sensor6 cpu6
			"cpu7", "/sys/devices/virtual/thermal/thermal_zone14/temp",//tsens_tz_sensor7 cpu7 
			"L2_cache_1", "/sys/devices/virtual/thermal/thermal_zone15/temp",//tsens_tz_sensor8 L2_cache_1
			"cpu0~3", "/sys/devices/virtual/thermal/thermal_zone16/temp",//tsens_tz_sensor9 cpu0-cpu1-cpu2-cpu3
			"gpu", "/sys/devices/virtual/thermal/thermal_zone17/temp",// tsens_tz_sensor10 gpu
			"pm8950_tz", "/sys/devices/virtual/thermal/thermal_zone18/temp",//pm8950_tz
			"pm8004_tz", "/sys/devices/virtual/thermal/thermal_zone19/temp", // pm8004_tz  //"/sys/devices/virtual/thermal/thermal_zone2/temp",// battery
			"pa_therm0", "/sys/devices/virtual/thermal/thermal_zone20/temp", // pa_therm0
			"pa_therm1", "/sys/devices/virtual/thermal/thermal_zone3/temp", // pa_therm1
			"wsatz.11", "/sys/devices/virtual/thermal/thermal_zone30/temp",// wsatz.11
			"xo_therm_buf", "/sys/devices/virtual/thermal/thermal_zone5/temp", // xo_therm_buf
			"tsens_tz_sensor0", "/sys/devices/virtual/thermal/thermal_zone7/temp",// tsens_tz_sensor0 
			"tsens_tz_sensor1", "/sys/devices/virtual/thermal/thermal_zone8/temp",// tsens_tz_sensor1
			"pop_mem", "/sys/devices/virtual/thermal/thermal_zone9/temp", //tsens_tz_sensor2 pop_mem
			"cpu0", "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq",
			"cpu1", "/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq",
			"cpu2", "/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq",
			"cpu3", "/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq",
			"cpu4", "/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_cur_freq",
			"cpu5", "/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_cur_freq",
			"cpu6", "/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_cur_freq",
			"cpu7", "/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_cur_freq",
			"battery", "/sys/class/power_supply/battery/current_now",
			"battery", "/sys/class/power_supply/battery/temp",
			"battery", "/sys/class/power_supply/battery/capacity",
			"battery", "/sys/class/power_supply/bq27542/energy_now",
			"battery", "/sys/class/power_supply/bq27542/charge_full",
		        }; 
		i=0;deB
		while(sysL[i*2] && sysL[i*2+1] && sysL[i*2][0] && sysL[i*2+1][0]){ deBV(" %d ", i);
			sys[i] = sysL[i*2+1];
			sysComm[i] = sysL[i*2]; deBV(" %d ", i);
			i++;	} deB
	}
	
	printf("time \t");
	i = 0;
	while(sysComm[i]){
		printf("%s \t", sysComm[i]);//printf("%s \t", sys[i]);
		i++;	}
	printf("\n");
	printf("time \t");
	i = 0;
	while(sys[i]){
		printf("%s \t", strrchr(sys[i], '/')+1);
		i++;	}
	printf("\n");
	while(1){
		time_t epoch_time;
		struct tm *tm_p;
		epoch_time = time( NULL );
		tm_p = localtime( &epoch_time );
		printf("%.2d:%.2d:%.2d \t",  tm_p->tm_hour, tm_p->tm_min, tm_p->tm_sec );
		i=0;
		while(sys[i]){			char s[64];
			int fd = open(sys[i], O_RDONLY);
			if(fd >= 0){
				s[0]=0;
				ssize_t n = read(fd, s, 64);
				if(s[n-1]=='\n')
					s[n-1]=0;
				printf("%s \t", s);
				close(fd);
			}else{
				printf("  _ \t");				//printf(" err:%s ", sys[i]);
			}
			i++;		}
		printf("\n"); //fflush(stdout);
		sleep(1);	}
	return 0; }
int main4_c(char *path,int curr_mode){
	return main3(path, curr_mode);
}
