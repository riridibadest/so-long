// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <string.h>

// // Function to simulate get_next_line
// char *get_next_line(int fd) {
//     char *line = malloc(1024); // Allocate a buffer
//     if (!line) return NULL;
//     if (!fgets(line, 1024, fdopen(fd, "r"))) {
//         free(line);
//         return NULL;
//     }
//     return line;
// }

// // Function to simulate ft_strjoin
// char *ft_strjoin(char *s1, const char *s2) {
//     if (!s1) return strdup(s2);
//     char *joined = malloc(strlen(s1) + strlen(s2) + 1);
//     if (!joined) return NULL;
//     strcpy(joined, s1);
//     strcat(joined, s2);
//     return joined;
// }

// // Function to simulate ft_split
// char **ft_split(const char *s, char delim) {
//     // Simplified split function
//     char **result = malloc(1024 * sizeof(char*)); // Allocate for 1024 lines
//     if (!result) return NULL;
//     size_t count = 0;
//     char *token = strtok(strdup(s), &delim);
//     while (token) {
//         result[count++] = token;
//         token = strtok(NULL, &delim);
//     }
//     result[count] = NULL;
//     return result;
// }

// void test_map_reading(const char *map_path) {
//     int fd = open(map_path, O_RDONLY);
//     if (fd == -1) {
//         perror("Error opening file");
//         return;
//     }

//     char *line;
//     char *all_content = NULL;
//     while ((line = get_next_line(fd)) != NULL) {
//         char *temp = all_content;
//         all_content = ft_strjoin(all_content, line);
//         free(temp);
//         free(line);
//     }
//     close(fd);

//     if (all_content) {
//         char **map = ft_split(all_content, '\n');
//         free(all_content);
//         // Print map for verification
//         for (size_t i = 0; map[i]; i++) {
//             printf("%s\n", map[i]);
//             free(map[i]);
//         }
//         free(map);
//     }
// }

// int main(int argc, char **argv) {
//     if (argc != 2) {
//         fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
//         return EXIT_FAILURE;
//     }
//     test_map_reading(argv[1]);
//     return EXIT_SUCCESS;
// }

