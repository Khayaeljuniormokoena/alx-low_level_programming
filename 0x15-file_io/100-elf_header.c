#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s elf_filename\n", argv[0]);
		exit(96);
	}
	
	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
		exit(98);
	}
	
	Elf32_Ehdr header;
	ssize_t bytes_read;

	bytes_read = read(fd, &header, sizeof(header));

	if (bytes_read == -1 || bytes_read != sizeof(header))
	{
		fprintf(stderr, "Error: Cannot read ELF header from file %s\n", argv[1]);
		close(fd);
		exit(96);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: Not an ELF file: %s\n", argv[1]);
		close(fd);
		exit(96);
	}

	printf ("ELF header:\n");
	printf (" Magic: ");

	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf ("%02x ", header.e_ident[i]);
	}
	 printf("\n");
	 printf("  Class: %d-bit\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
	 printf("  Data: %s-endian\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "Little" : "Big");
	 printf("  Version: %d (current)\n", header.e_ident[EI_VERSION]);
	 printf("  OS/ABI: %d\n", header.e_ident[EI_OSABI]);
	 printf("  ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	 printf("  Type: %d\n", header.e_type);
	 printf("  Entry point address: 0x%lx\n", (unsigned long)header.e_entry);

	 close(fd);
	 return (0);
}

	
