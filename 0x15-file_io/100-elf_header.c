#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void error_exit(const char *message) {
dprintf(STDERR_FILENO, "%s\n", message);
exit(98);
}

void print_elf_header(const char *file_name) {
int fd = open(file_name, O_RDONLY);
if (fd == -1) {
error_exit("Error: Can't open ELF file");
}

Elf32_Ehdr header;
ssize_t bytes_read = read(fd, &header, sizeof(header));
if (bytes_read != sizeof(header)) {
error_exit("Error: Can't read ELF header");
}

if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3) {
error_exit("Error: Not an ELF file");
}

printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++) {
printf("%02x ", header.e_ident[i]);
}
printf("\n");
printf("  Class:                             %s\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
printf("  Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "Unknown");
printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
printf("  OS/ABI:                            %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Unknown");
printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
printf("  Type:                              ");
switch (header.e_type) {
case ET_NONE:  printf("NONE (Unknown type)\n"); break;
case ET_REL:   printf("REL (Relocatable file)\n"); break;
case ET_EXEC:  printf("EXEC (Executable file)\n"); break;
case ET_DYN:   printf("DYN (Shared object file)\n"); break;
case ET_CORE:  printf("CORE (Core file)\n"); break;
default:       printf("Unknown\n"); break;
}
printf("  Entry point address:               0x%x\n", header.e_entry);

close(fd);
}

int main(int argc, char *argv[]) {
if (argc != 2) {
error_exit("Usage: elf_header elf_filename");
}

print_elf_header(argv[1]);

return 0;
}
