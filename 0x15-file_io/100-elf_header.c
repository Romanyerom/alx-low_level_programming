#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * error_and_exit - Prints an error message and exits with the given code.
 * @code: The exit code.
 * @message: The error message to print.
 */

void error_and_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * print_magic - Prints the ELF magic numbers.
 * @ehdr: Pointer to the ELF header structure.
 */

void print_magic(Elf64_Ehdr *ehdr)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr->e_ident[i]);
	printf("\n");
}

/**
 * print_class - Prints the ELF class.
 * @ehdr: Pointer to the ELF header structure.
 */

void print_class(Elf64_Ehdr *ehdr)
{
	printf("  Class:                             ");
	switch (ehdr->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
}

/**
 * print_data - Prints the ELF data encoding.
 * @ehdr: Pointer to the ELF header structure.
 */

void print_data(Elf64_Ehdr *ehdr)
{
	printf("  Data:                              ");
	switch (ehdr->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
}

/**
 * print_version - Prints the ELF version.
 * @ehdr: Pointer to the ELF header structure.
 */

void print_version(Elf64_Ehdr *ehdr)
{
	printf("  Version:                           %d (current)\n", ehdr->e_ident[EI_VERSION]);
}

/**
 * print_osabi - Prints the OS/ABI.
 * @ehdr: Pointer to the ELF header structure.
 */

void print_osabi(Elf64_Ehdr *ehdr)
{
	printf("  OS/ABI:                            ");
	switch (ehdr->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %d>\n", ehdr->e_ident[EI_OSABI]);
		break;
	}
}

/**
 * print_abiversion - Prints the ABI version.
 * @ehdr: Pointer to the ELF header structure.
 */

void print_abiversion(Elf64_Ehdr *ehdr)
{
	printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the ELF type.
 * @ehdr: Pointer to the ELF header structure.
 */

void print_type(Elf64_Ehdr *ehdr)
{
	printf("  Type:                              ");
	switch (ehdr->e_type)
	{
	case ET_NONE:
		printf("NONE (No file type)\n");
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
		printf("<unknown: %x>\n", ehdr->e_type);
		break;
	}
}

/**
 * print_entry - Prints the entry point address.
 * @ehdr: Pointer to the ELF header structure.
 */

void print_entry(Elf64_Ehdr *ehdr)
{
	printf("  Entry point address:               0x%lx\n", ehdr->e_entry);
}

/**
 * main - Displays the information contained in the ELF header of an ELF file.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, or the corresponding error code on failure.
 */

int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2)
		error_and_exit(98, "Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_and_exit(98, "Error: Can't read file");

	if (read(fd, &ehdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		error_and_exit(98, "Error: Can't read file");

	if (lseek(fd, 0, SEEK_SET) == -1)
		error_and_exit(98, "Error: Can't read file");

	printf("ELF Header:\n");
	print_magic(&ehdr);
	print_class(&ehdr);
	print_data(&ehdr);
	print_version(&ehdr);
	print_osabi(&ehdr);
	print_abiversion(&ehdr);
	print_type(&ehdr);
	print_entry(&ehdr);

	if (close(fd) == -1)
		error_and_exit(100, "Error: Can't close file descriptor");

	return (0);
}
