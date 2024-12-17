/*************************************************************************
	> File Name: 7.my_cp.c
	> Author: 
	> Mail: 
	> Created Time: Sat 14 Dec 2024 08:18:43 PM CST
 ************************************************************************/

#include "./common/head.h"


int main(int argc, char **argv)
{
    int opt, copy_flag = 0;
    
    while ((opt = getopt(argc, argv, "a")) != -1) {
        switch (opt) {
            case 'a' : 
                copy_flag = 1;
                break;
            default:
                fprintf(stderr, "Usage : %s [-a] <src_file> <dest_file>\n", argv[0]);
                exit(1);
        }
    }
    if(argc - optind != 2) {
        fprintf(stderr, "Usage : %s [-a] <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }
    
    const char *src = argv[optind];
    const char *dest = argv[optind + 1];



    return 0;
}
