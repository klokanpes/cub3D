/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-21 22:50:30 by vcerny            #+#    #+#             */
/*   Updated: 2025-03-21 22:50:30 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/**
 * @brief prepares the buffer for the next itteration
 *
 * This function is invoked when a valid string has been
 * found in the buffer. If all data from the buffer have been
 * consumed, it is freed and set to null. If there is leftover
 * data, they are copied into temp (which is just big enough for them),
 * the original buffer is freed and temp is assigned to the original buffer
 * pointer.
 *
 * @param char** pointer to the buffer
 * @param int location -> where the previous function left off
 * @return This function does not return a value.
 */
void	ft_remove_from_buffer(char **buffer, int location)
{
	char	*temp;
	int		len;
	int		start;

	start = location + 1;
	if (start >= ft_strlen_gnl(*buffer))
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	len = ft_strlen_gnl(*buffer + start);
	temp = (char *)malloc(len + 1);
	if (!temp)
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	ft_strcpy_gnl(temp, *buffer + start);
	free(*buffer);
	if (ft_strlen_gnl(temp) == 0)
		*buffer = NULL;
	else
		*buffer = temp;
}

/**
 * @brief Takes buffer as argument, finds new line or EOF,and
 * returns the string.
 *
 * On eof, it also sets the buffer to null and frees everything.
 * On new_line, it calls ft_remove_from_buffer-> which makes sure
 * that the leftover data only contain what has not been returned.
 *
 * @param char** pointer to the buffer
 * @return ((char *) new_line or NULL);
 */
char	*ft_extract_new_line(char **buffer)
{
	char	*newline_string;
	int		location;

	location = ft_strchr_gnl(*buffer, '\n');
	if (location == -1)
	{
		newline_string = ft_strsub_gnl(*buffer, 0, ft_strlen_gnl(*buffer));
		free(*buffer);
		*buffer = NULL;
		return (newline_string);
	}
	else
	{
		newline_string = ft_strsub_gnl(*buffer, 0, location + 1);
		if (!newline_string)
			return (NULL);
		ft_remove_from_buffer(buffer, location);
		return (newline_string);
	}
}

/**
 * @brief This is the second function in the buffer reading pipeline. It gets
 * called if the first read was successful so it attempts to read more, untill
 * a new_line is found or EOF.
 *
 * This function provides further reading functionality into the buffer. Firstly
 * it enlarges the buffer size by BUFFER_SIZE, malocs a new temp string,
 * zeroes it, and copies into it from the buffer. It then frees the original
 * buffer, sets the buffer to point to the temp string and reads again into
 *  the now enlarged buffer. If EOF is reached, it exits, else it continues
 * this behaviour in a loop until a new_line can be found in the current buffer.
 *
 * @param buffer (char **) pointer to the static buffer used by the pipeline
 * @param buffer_size The current buffer size (basically BUFFER_SIZE)¨
 * @param bytes_read (int *) how many bytes were read on the first itteration
 * It still continues to use this variable by reference
 * 
 * 	// if (!temp)
	// {
	// 	free (*buffer);
	// 	*buffer = NULL;
	// 	return ;
	// }

 * @param fd file descriptor that was originally provided
 *
 * @return Does not return a value
 */
void	ft_read_buffer_2(char **buffer, int buffer_size, int *bytes_read,
		int fd)
{
	char	*temp;

	while (ft_strchr_gnl(*buffer, '\n') == -1)
	{
		temp = NULL;
		buffer_size = ft_strlen_gnl(*buffer) + BUFFER_SIZE;
		temp = malloc((buffer_size + 1) * sizeof(char));
		ft_bzero_gnl((void *)temp, buffer_size + 1);
		ft_strcpy_gnl(temp, *buffer);
		free(*buffer);
		*buffer = temp;
		*bytes_read = read(fd, &(*buffer)[buffer_size - BUFFER_SIZE],
				BUFFER_SIZE);
		if (*bytes_read == 0)
		{
			return ;
		}
		if (*bytes_read == -1)
		{
			free (*buffer);
			*buffer = NULL;
			return ;
		}
	}
}

/**
 * @brief This function covers the case where the buffer is null. That
 * can happen on the first itteration or when the newline was cleanly found
 * in a string with nothing else there.
 *
 * If such a thing happens, the buffer is allocated to BUFFER_SIZE + 1 (space
 * for the null terminator of a string.) Then the allocated memory gets zeroed,
 * then, the function attempts to read into the buffer. If there is nothing to
 * read, the function returns an empty buffer. That is then detected by the
 * get_next_line function a processed accordingly. -> that takes care of
 * the EOF case.
 *
 * Lastly, if the read is successfull (and there seems to be more data to read)
 * the function passes the processing to the next function in this pipeline,
 * ft_read_buffer_2.
 *
 * @param int fd - file descriptor
 * @param int buffer_size - initial value to start with
 *
 * @return (char **)pointer to the buffer
 */
char	**ft_read_buffer(int fd, int buffer_size)
{
	static char	*buffer = NULL;
	int			bytes_read;

	if (!buffer)
	{
		buffer = (char *)malloc((buffer_size + 1) * sizeof(char));
		if (!buffer)
			return (&buffer);
		ft_bzero_gnl((void *)buffer, buffer_size + 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (buffer)
				free(buffer);
			buffer = NULL;
			return (&buffer);
		}
	}
	ft_read_buffer_2(&buffer, buffer_size, &bytes_read, fd);
	return (&buffer);
}

/**
 * @brief This function works with the buffer. It does error checking,
 * detects EOF, to correctly return, and calls other functions to fulfill
 * its role.
 *
 * This is the main function of this assignment. First it does a 0 len read,
 * that is to verify that the provided fd is valid. Then it checks the inputed
 * buffer size. Anything lower than one is not supported. Then it calls
 * ft_read_buffer to actually put data into the buffer. The buffer is the string
 * that this code actually works with. If it returns an empty string, this
 * function does some necessary steps and returns null. That means that the
 * file is either empty or EOF has been reached.
 * Then, if a valid buffer was returned (meaning that there is a \\n) in
 * the buffer, ft_extract_new_line is called. If it does not return a
 * valid string, null is returned from here (that is error behaviour.)
 * Else, if everything works, we return a new line.
 *
 * @param int file descriptor - where to read from
 * @return (char *) new line (with or without \\n based on EOF)
 * or NULL
 */
char	*get_next_line(int fd)
{
	char	**buffer;
	char	*new_line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buffer = ft_read_buffer(fd, BUFFER_SIZE);
	if (!(*buffer))
		return (NULL);
	if ((*buffer)[0] == '\0')
	{
		if (*buffer)
			free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	new_line = ft_extract_new_line(buffer);
	if (!new_line)
	{
		if (*buffer)
			free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (new_line);
}
