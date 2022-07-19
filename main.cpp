#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#define MAX 1000

int main(int argc, char *argv[]) {
	FILE *f1, *f2;
	int ch;
	int index = 3;
	uint8_t network_buffer[4] = {0,};

	f1 = fopen(argv[1], "rb");
	f2 = fopen(argv[2], "rb");
	
	while((ch= fgetc(f1))!=EOF){
		network_buffer[index] = ch;
		index--;
	}
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	uint32_t n = *p;
	
	index = 3;
	while((ch= fgetc(f2))!=EOF){
                network_buffer[index] = ch;
                index--;
        }
        p = reinterpret_cast<uint32_t*>(network_buffer);
        uint32_t n2 = *p;

	printf("(%d)0x%x + (%d)0x%x = (%d)0x%x\n",n,n,n2,n2,n+n2,n+n2);

	fclose(f1);
	fclose(f2);

}
