/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:23:11 by lbard             #+#    #+#             */
/*   Updated: 2024/12/18 16:15:28 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <string.h>

/*
 * @Read from fd and accumulate the text in saved.
 */
static char	*read_and_accumulate(int fd, char *saved)
{
	char	*tmp;
	char	*buffer;
	int		b;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	b = read(fd, buffer, BUFFER_SIZE);
	while (b > 0)
	{
		buffer[b] = '\0';
		tmp = ft_strjoin(saved, buffer);
		if (!tmp)
			return (NULL);
		free(saved);
		saved = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
		b = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (saved);
}

/*
 * @Fetch line in new char and updates saved for the next call.
 */
static char	*fetch_line(char *saved)
{
	char	*line;
	char	*newline_pos;

	if (!saved || *saved == '\0')
		return (NULL);
	newline_pos = ft_strchr(saved, '\n');
	if (newline_pos)
	{
		line = ft_substr(saved, 0, newline_pos - saved + 1);
		ft_strlcpy(saved, newline_pos + 1, gnl_ft_strlen(newline_pos));
	}
	else
	{
		line = ft_substr(saved, 0, gnl_ft_strlen(saved));
		saved[0] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_and_accumulate(fd, saved);
	line = fetch_line(saved);
	if (saved && *saved == '\0')
	{
		free(saved);
		saved = NULL;
	}
	return (line);
}

/*int main(void)
{
	int fd;
	char *line;

	fd = open("1char.txt", O_RDONLY);
	//fd = open("story.txt.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

void	test_file(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("erreur impossible douvrir : %s\n", filename);
		return;
	}
	printf("\n----- Test du fichier : %s ----\n", filename);
	char *line;
	int	line_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Ligne %d : %s", ++line_count, line);
		free(line);
	}
	if (line_count == 0)
		printf("Aucune Ligne lue dans le fichier : %s\n", filename);
	close(fd);
	printf("----Fin du test pour %s ----\n", filename);
}

void test_edge_cases()
{
	printf("\n ------ Test des cas limites ----\n");
	char	*line = get_next_line(-1);
	if (!line)
		printf("Test FD invalide : OK\n");
	else
	{
		printf("Test FD invalide : ERREUR\n");
		free(line);
	}

	int fd = open("test.txt", O_RDONLY);
	close(fd);
	line = get_next_line(fd);
	if (!line)
		printf("Test FD ferme : OK\n");
	else 
	{
		printf("Test FD ferme : ERREUR\n");
		free(line);
	}

	printf("------ Fin des test cas limites ----");
}

int main()
{
	system("echo 'Premiere ligne\\nDeuxieme ligne\\nTroisieme ligne' > file1.txt");
	system("echo 'Une seule ligne' > file2.txt");
	system("touch empty_file.txt");
	system("head -c 100000 /dev/zero | tr '\\0' 'A' > large_file.txt");

	test_file("file1.txt"); 
	test_file("file2.txt");
	test_file("empty_file.txt");
	test_file("large_file.txt");

	test_edge_cases();
	system("rm -f file1.txt file2.txt empty_file.txt large_file.txt");

	return 0;
}*/
