#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
int num_cpus = 0;
int num_gpus = 0;
int exit_daemon = 0;
int debug_output = 0;//LOG_LVL_//;
int soc_id = -1;
int enable_restore_brightness = 0;
int minimum_mode = 0;
int dump_bcl = 0;
int trace_fd = -1;
char *dump_bcl_file = NULL;
static char *config_file = NULL;
static char *output_conf = NULL;
void print_help(void)
{
	printf("\nTemperature sensor daemon\n");
	printf("\n bat current mode: time, current,lcd brightness,usb online\n");
	printf("Optional arguments:\n");
	printf("  --config-file/-c <file>        config file\n");
	printf("  --debug/-d                     debug output\n");
	printf("  --soc_id/-s single mode\n");//printf("  --soc_id/-s <target>           target soc_id\n");
	printf("  --norestorebrightness/-r       disable restore brightness functionality\n");
	printf("  --output-conf/-o               dump config file of active settings\n");
	printf("  --trace/-t                     enable ftrace tracing\n");
	printf("  --dump-bcl/-i                  BCL ibat/imax file\n");
	printf("  --help/-h                      this help screen\n");
}
static int bat_curr_mode = 0;
int parse_commandline(int argc, char *const argv[])
{
	int c;
	struct option long_options[] = {
		{"output-conf",         1, 0, 'o'},
		{"config-file",         1, 0, 'c'},
		{"debug",               0, 0, 'd'},
		{"soc_id",              1, 0, 's'},
		{"norestorebrightness", 0, 0, 'r'},
		{"dump-bcl",            2, 0, 'i'},
		{"help",                0, 0, 'h'},
		{"bat",                0, 0, 'b'},
		{"trace",		0, 0, 't'},
		{0, 0, 0, 0} 	};
	
	while ((c = getopt_long(argc, argv, "c:i::s:dro:htb", long_options, NULL)) != EOF) {
		switch (c) {
			case 'c':
				//("Using config file '%s'\n", optarg);
				config_file = optarg;
				break;
			case 'b':				//("Using config file '%s'\n", optarg);
				bat_curr_mode = 1;
				break;
			case 'i':
				//("dump BCL ibat/imax to a file\n");
				dump_bcl = 1;
				dump_bcl_file = optarg;
				break;
			case 'd':
				//("Debug output enabled\n");
				debug_output = 0;//eVL_DBG;
				break;
			case 's':
				//("Target SOC_ID specified as '%s'\n", optarg);
				soc_id = atoi(optarg);
				break;
			case 'r':
				//("Enable restore brightness feature\n");
				enable_restore_brightness = 1;
				break;
			case 'o':
				//("Output conf file to stdout and quit\n");
				output_conf = optarg;;
				break;
			case 't':
				//("tracing enabled\n");
				//trace_fd = open(TRACE_MARKER, O_WRONLY);
				break;
			case 'h':
			default:
				return 0;
		}
	}
	/* Too many/unrecognized argument(s) */
	if (optind < argc) {		//msg("Too many arguments\n");
		return 0;	}
	return 1;}
static char fArr[256][256];// ={0};
#define deB printf
int main0(char *path){	int i=0;
	FILE *pF = fopen(path, "rb");
	if(pF){ deB(" gg \n");
		while(fgets(fArr[i],256, pF)){ deB(" %s \n", fArr[i]);
			int l = strlen(fArr[i]);
			if(l>=1){
				int n=l-1;
				if(isspace(fArr[i][n]))
					fArr[i][n] = 0;
			}
			if(l>=2){
				int n=l-2;
				if(isspace(fArr[i][n]))
					fArr[i][n] = 0;			}
			if(fArr[i][0]){			deB(" %s ", fArr[i]);
				i++;			}else deB(" null ");	}
		fclose(pF);	}
	return 0; }
extern int main4_c(char *path,int curr_mode);
int main(int argc, char **argv){
	if (!parse_commandline(argc, argv)) {
		print_help();
		return 0;
	}
	//if (config_file) { printf(" fff \n");		main0(config_file);	}
	//if (output_conf) { printf(" out:%s \n", output_conf);		return 0; 	}
	main4_c(config_file, bat_curr_mode);
	return 0;
}
