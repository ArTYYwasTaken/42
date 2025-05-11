/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <kemontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:06:35 by kemontei          #+#    #+#             */
/*   Updated: 2025/05/07 16:06:52 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		chars_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	chars_read = BUFFER_SIZE + 1;
	while (1)
	{
		if (buffer[0] == '\0')
			chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
			return (NULL);
		else if (chars_read == 0)
			return (line);
		buffer[chars_read] = '\0';
		line = gnl_strjoin(line, buffer);
		if (!line || gnl_strchr(buffer, '\n'))
    		break ;
		else
			clean_buffer(buffer, sizeof(buffer));
	}
	update_buffer(buffer, 0, sizeof(buffer));
	return (line);
}
/*
--//Antes//--
char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    ssize_t chars_read;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    chars_read = 1;
    line = NULL;
    while (1)
    {
        if(buffer[0] == '\0')
            chars_read = read(fd, buffer, BUFFER_SIZE);
        if (chars_read < 0)
            return (NULL);
        else if (chars_read == 0)
            return(line);
        buffer[chars_read] = '\0';
        if(!(line = ft_strjoin(line, buffer)))
        return (NULL);
        if (ft_strchr(buffer, '\n') != NULL)
             break;
    }
    update_buffer(buffer, 0);
    return(line);
}
*/
/* 
int main()
{
 	// char buffer[20] = "Hello\nWorld";
	// size_t buffer_size = sizeof(buffer);

	// printf("Before update: '%s'\n", buffer);
	// update_buffer(buffer, 0, buffer_size);
	// printf("After update: '%s'\n", buffer);

	// int fd = open("test.txt", O_RDONLY);
	// char *line;
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	// close (fd);

    // char *s1 = NULL;
	// char *s2 = strdup("mundo");
	// char *str = gnl_strjoin(s1, s2);
	// printf ("%s", str);
	// free(str);
	// free (s2);
	return 0;
}
*/