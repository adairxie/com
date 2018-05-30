/*
 * malloc 分配多大的内存，就占用多大的物理内存空间吗？
 *
 * 我们知道，malloc分配的内存是虚拟地址空间，而虚拟地址空间使用进程页表进行映射，
 * 那么分配了空间就是占用了物理内存了吗？
 *
 * 首先，进程使用多少内存可通过ps
 * aux命令查看，其中关键的两个信息(第五、六列)为：
 * 1.VSZ，virtual memory
 * size，表示进程总共使用的虚拟地址空间大小，
 * 包括进程地址空间的代码段、数据段、堆、文件映射区域、栈、内核空间等所有虚拟地址
 * 使用的总和，单位是K
 * 2.RSS，resident set size, 表示进程实际使用的物理内存空间，RSS总小于VSZ。
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
 #include <sys/mman.h>
 #include <malloc.h>

 char ps_cmd[1024];

 void print_info(char* var_name, char* var_ptr, size_t size_in_kb)
 {
     printf("Address of %s(%luk) 0x%lx, now heap top is 0x%lx\n",
            var_name， size_in_kb, var_ptr, sbrk(0));
     system(ps_cmd);
 }

 int main(int argc, char** argv)
 {
     char *non_set_var, *set_1k_var, *set_5k_var, *set_7k_var;
     pid_t pid;
     pid = getpid();
     sprintf(ps_cmd, "ps aux | grep %lu | grep -v grep", pid);
     non_set_var = malloc(64*1024);
     print_info("non_set_var", non_set_var, 32);
     set_1k_var = malloc(64*1024);
     memset(set_1k_var, 0, 1024);
     print_info("set_1k_var", set_1k_var, 64);
     set_5k_var = malloc(127*1024);
     memset(set_5k_var, 0, 5*1024);
     print_info("set_5k_var", set_5k_var, 127);
     set_7k_var = malloc(64*1024);
     memset(set_7k_var, 0, 7*1024);
     print_info("set_7k_var", set_7k_var, 64);
     return 1;
 }
