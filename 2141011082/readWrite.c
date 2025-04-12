#include<stdio.h>
#include <unistd.h>
int main(){
      char buff[100];
      int bytesread,byteswritten;
      bytesread = read(0, buff, 100);
      printf("Bytes read = %d\n", bytesread);
      byteswritten = write(1,buff,bytesread);
      byteswritten = write(1,"Manyukumar", 5);
      printf("Bytes writeen = %d\n", byteswritten);
      return 0;
}
