#include <stdio.h>
#include <stdlib.h>

// Function to create a file
void create_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error creating file");
        return;
    }
    fprintf(fp, "Sample content written to %s\n", filename);
    fclose(fp);
    printf("File created: %s\n", filename);
}

// Function to delete a file
void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted: %s\n", filename);
    } else {
        perror("Error deleting file");
    }
}

// Function to copy a file
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "r");
    FILE *dest = fopen(destination, "w");
    char ch;

    if (src == NULL || dest == NULL) {
        perror("Error opening files for copy");
        return;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied from %s to %s\n", source, destination);

    fclose(src);
    fclose(dest);
}

// Function to move/rename a file
void move_file(const char *oldname, const char *newname) {
    if (rename(oldname, newname) == 0) {
        printf("File moved/renamed to: %s\n", newname);
    } else {
        perror("Error moving file");
    }
}

int main() {
    const char *file1 = "test.txt";
    const char *file2 = "copy_test.txt";
    const char *moved_file = "moved_test.txt";

    create_file(file1);
    copy_file(file1, file2);
    move_file(file2, moved_file);
    delete_file(file1);
    delete_file(moved_file);

    return 0;
}
