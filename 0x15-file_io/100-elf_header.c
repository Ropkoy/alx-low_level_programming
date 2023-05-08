#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: array pnter with ELF magic number
 * Return: exit code 98 -if file is an ELF
 */

void check_elf(unsigned char *e_ident)
{
int index;
for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 && e_ident[index] != 'E' && e_ident[index] != 'L' && e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
 * print_magic - print the magic number of ELF header
 * @e_ident: array pointer with ELF magic number
 * Retuen: No,separated by space
 */

void print_magic(unsigned char *e_ident)
{
int index;
printf(" Magic: ");
for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", e_ident[index]);
if (index == EI_NIDENT -1)
printf("\n");
else
printf(" ");
}
}

/**
 * print_class - print e class of ELF header
 * @e_ident: pointer to array with ELF class
 */

void print_class(unsigned char *e_ident)
{
printf(" class: ");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * print_data - print data to ELF header
 * e_ident: pointer to  array containing ELF class
 */

void print_data(unsigned char *e_ident)
{
printf(" Data: ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>n", e_ident[EI_CLASS]);
}
}

/**
 * print_version - to prints the version of ELF header
 * @e_ident: pointer to array with ELF version
 */

void print_version(unsigned char *e_ident)
{
printf(" Version: %d", e_ident[EI_VERSION]);
switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
 * print_osabi - prints the OS/ABI of ELF header 
 ** @e_idennt:  pointer to array containing ELF version
 */

void print_osabi(unsigned char *e_ident)
{
printf(" OS/ABI: ");
switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP -UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NETBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
 * print_abi - prints ABI version  ELF header
 * @e_ident: pointer of array having ELF ABI version
 */

void print_abi(unsigned char *e_ident)
{
printf(" ABI VERSION: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints type of ELF header
 * @e_type: Elf type
 * @e_ident: pointer to an array with an ELF class
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;
printf(" Type: ");
switch (e_type)
{
case ET_NONE:
printf("NONE (none)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", e_type);
}
}

/**
 * print_entry - printss entry points of ELF header
 * @_entry: ELF entry point address
 * e_ident: pointer of an array of ELF class
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf(" Entry point address: ");
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);
else
printf("%#lx\n", e_entry);
}

/**
 * close_elf - closes ELF file
 * @elf: file descriptor f ELF file
 * Return: exit code 98 on fail other instance success
 */

void close_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
exit(98);
}
}

/**
 * main - displaye info in the ELF header at start of file
 * @argc - arguments supplied to program
 * @argv -  pointer arrays to arguments
 * Return: 0 for success else on fail - exit code 98
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int f, s;
f = open(argv[1], O_RDONLY);
if (f == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_elf(f);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
s = read(f, header, sizeof(Elf64_Ehdr));
if (s == -1)
{
free(header);
close_elf(f);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}
check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);
print_class(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);
free(header);
close_elf(f);
return (0);
}
