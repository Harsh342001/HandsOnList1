#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


int main(){

	struct stat file_stat;
	int ret_stat;
	stat("dest" , &file_stat);

	printf("File inode  : %ld \n" , file_stat.st_ino);
	printf("Number of hardlinks : %ld \n" , file_stat.st_nlink);
	printf("User ID of owner : %d \n" , file_stat.st_uid);
	printf("Group ID of owner : %d \n" , file_stat.st_gid);
	printf("Total size, in bytes : %ld \n" , file_stat.st_size);
	printf("block size : %ld \n" , file_stat.st_blksize);
	printf("Number of blocks : %ld \n" , file_stat.st_blocks);
	printf("Time of last access : %ld \n" , file_stat.st_atim.tv_sec);
	printf("time of last modification : %ld \n" , file_stat.st_mtim.tv_sec);
	printf("time of last change : %ld \n" , file_stat.st_ctim.tv_sec);


}