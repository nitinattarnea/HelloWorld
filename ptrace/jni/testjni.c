/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

//#include<sys/types.h>
//#include <sys/wait.h>

//#include<linux/user.h>
#include <string.h>
#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>


//#include <asm/user.h>
#include <sys/ptrace.h>

//#include <asm/mman.h>
//#include <dlfcn.h>
//#include <dirent.h>
//#include <sys/unistd.h>
//#include <sys/errno.h> 
/*#define PTRACE_PEEKTEXT 1
#define PTRACE_POKETEXT 4
#define PTRACE_ATTACH	16
#define PTRACE_CONT 	7
#define PTRACE_DETACH   17
#define PTRACE_SYSCALL	24
#define CPSR_T_MASK	( 1u << 5 )
/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/HelloJni/HelloJni.java
 */


/*int ptrace_attach( pid_t pid )
{
	if ( ptrace( PTRACE_ATTACH, pid, NULL, 0 ) < 0 )
		{
//__android_log_print(ANDROID_LOG_DEBUG,"errno%d",errno);
__android_log_print(ANDROID_LOG_DEBUG,"ptrace_attaach","fail");
			return -1;

		}
__android_log_print(ANDROID_LOG_DEBUG,"ptrace_attach","sucess");
		return 0;
}*/
int ptrace_attach( pid_t pid )
{
int ret=ptrace( PTRACE_ATTACH, pid, NULL, 0  );
//__android_log_print(ANDROID_LOG_DEBUG,"ptrace_attach ret=%d",ret);

	if(ret<0)
{
__android_log_print(ANDROID_LOG_DEBUG,"ptrace_attach","sf");
		
return -1;
	}

//	waitpid( pid, NULL, WUNTRACED );

	//LOGD("attached\n");

/*	if ( ptrace( PTRACE_SYSCALL, pid, NULL, 0  ) < 0 )
	{
		perror( "ptrace_syscall" );
__android_log_print(ANDROID_LOG_DEBUG,"ptrace_attach","fail");
		return -1;
	}
*/
//	waitpid( pid, NULL, WUNTRACED );
__android_log_print(ANDROID_LOG_DEBUG,"ptrace_attach","sucess");
	return 0;
}

int ptrace_detach( pid_t pid )
{
	if ( ptrace( PTRACE_DETACH, pid, NULL, 0 ) < 0 )
		{
			perror( "ptrace_detach" );
__android_log_print(ANDROID_LOG_DEBUG,"ptrace_detach","fail");
			return -1;
		}
__android_log_print(ANDROID_LOG_DEBUG,"ptrace_detach","sucess");
		return 0;
}




/*int find_pid_of( const char *process_name )
{

	int id;
	pid_t pid = -1;
	DIR* dir;
	FILE *fp;
	char filename[32];
	char cmdline[256];

	struct dirent * entry;

	if ( process_name == NULL )
		return -1;

	dir = opendir( "/proc" );
	if ( dir == NULL )
		return -1;

	while( (entry = readdir( dir )) != NULL )
	{
		id = atoi( entry->d_name );
		if ( id != 0 )
		{
			sprintf( filename, "/proc/%d/cmdline", id );
			fp = fopen( filename, "r" );
			if ( fp )
			{
				fgets( cmdline, sizeof(cmdline), fp );
				fclose( fp );

				if ( strcmp( process_name, cmdline ) == 0 )
				{
					// process found 
					pid = id;
					break;
				}
			}
		}
	}

	closedir( dir );
__android_log_print(ANDROID_LOG_INFO,"find_pid_of","run");

//__android_log_print(ANDROID_LOG_INFO,"PID IS%d",id);

	return pid;
}*/
 /*long freespaceaddr(pid_t pid)  
{  
__android_log_print(ANDROID_LOG_INFO,"7","free");
    FILE *fp;  
    char filename[30];  
    char line[85];  
    long addr;  
    char str[20];  
    sprintf(filename, "/proc/%d/maps", pid);  
    fp = fopen(filename, "r");  
    if(fp == NULL)  
        exit(1);  
    while(fgets(line, 624, fp) != NULL) {  
        sscanf(line, "%lx %*lx %*s %*s %s", &addr, str, str, str, str);  
        if(strcmp(str, "00:00") == 0)  ptrace_detach(pid);
            break;  
    }  
    fclose(fp); 
//printf("addr is %lx\n",addr);
//__android_log_print(ANDROID_LOG_DEBUG,"addr is%lx",addr);
    return addr;  
}*/
jstring Java_com_ptrace_PtraceActivity_stringFromJNI( JNIEnv* env,
                                                  jobject thiz )
{
int ret=ptrace( PTRACE_ATTACH, 109, NULL, NULL  );
if(ret<0)
__android_log_print(ANDROID_LOG_DEBUG,"ptrace_attach","sf");
		

//__android_log_print(ANDROID_LOG_DEBUG,"uid%d",getuid());
//pid_t target_pid;
//struct pt_regs* regs, oldregs;
 //long addr;  

//__android_log_print(ANDROID_LOG_DEBUG,"1","main ");
//target_pid = find_pid_of("/system/bin/servicemanager");
//ptrace_attach(target_pid);
//ptrace_attach(109);
//wait(NULL);  
//__android_log_print(ANDROID_LOG_DEBUG,"wait","is done");
//ptrace_detach(109);
  //      ptrace(PTRACE_GETREGS, 624, NULL, &regs); 
//__android_log_print(ANDROID_LOG_INFO,"getregs","is done");

//__android_log_print(ANDROID_LOG_INFO,"regs%lx",regs->ARM_pc);
//addr = freespaceaddr(624);  //获得空闲空间
// memcpy(&oldregs, &regs, sizeof(regs));  //报存寄存器状态
//__android_log_print(ANDROID_LOG_INFO,"6","ret");
    return (*env)->NewStringUTF(env, "pppp");

}
