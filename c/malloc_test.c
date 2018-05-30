/*
* malloc 是如何分配内存的
*
* malloc获取虚存空间的实现，与glibc的版本有关，但大体逻辑是：
* 1. 若分配内存小于128k，调用sbrk()，将堆顶指针向高地址移动，获得新的虚存空间。
* 2. 若分配内存大于128k，调用mmap(), 在文件映射区域中分配匿名虚存空间。
* 3. 这里讨论的是简单情况，如果涉及并发可能会复杂一些，不过先不讨论。
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <malloc.h>

void print_info(char* var_name, char* var_ptr, size_t size_in_kb)
{
    printf("Address of %s(%luk) 0x%lx, now heap top is 0x%lx\n", var_name, size_in_kb, var_ptr, sbrk(0));
}

int main(int argc, char** argv)
{
    char *heap_var1, *heap_var2, *heap_var3 ;
    char *mmap_var1, *mmap_var2, *mmap_var3 ;
    char *maybe_mmap_var;
    printf("Orginal heap top is 0x%lx\n", sbrk(0));
    heap_var1 = malloc(32*1024);
    print_info("heap_var1", heap_var1, 32);
    heap_var2 = malloc(64*1024);
    print_info("heap_var2", heap_var2, 64);
    heap_var3 = malloc(127*1024);
    print_info("heap_var3", heap_var3, 127);
    printf("\n");
    maybe_mmap_var = malloc(128*1024);
    print_info("maybe_mmap_var", maybe_mmap_var, 128);
    //mmap
    mmap_var1 = malloc(128*1024);
    print_info("mmap_var1", mmap_var1, 128);
    // set M_MMAP_THRESHOLD to 64k
    mallopt(M_MMAP_THRESHOLD, 64*1024);
    printf("set M_MMAP_THRESHOLD to 64k\n");
    mmap_var2 = malloc(64*1024);
    print_info("mmap_var2", mmap_var2, 64);
    mmap_var3 = malloc(127*1024);
    print_info("mmap_var3", mmap_var3, 127);

    return 1;
}
