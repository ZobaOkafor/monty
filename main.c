#include "monty.h"


/**
 * main - monty code interpreter
 * @argc: argument count
 * @argv: argument array
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char line[256], opcode[5];
	size_t len;
	int value, line_number = 0;

	if (argc != 2)
	{	fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE); }
	file = fopen(argv[1], "r");
	if (file == NULL)
	{	perror("Error opening file");
		return (EXIT_FAILURE); }
	while (fgets(line, sizeof(line), file) != NULL)
	{	line_number++;
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (sscanf(line, "%4s %d", opcode, &value) == 2
			|| sscanf(line, "%4s", opcode) == 1)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (sscanf(line, "%*s %d", &value) == 1)
					push(value, line_number);
				else
				{	fprintf(stderr, "L%d: Usage: push integer\n", line_number);
					fclose(file);
					return (EXIT_FAILURE); } }
			else if (strcmp(opcode, "pall") == 0)
				pall();
			else
			{	fprintf(stderr, "L%d: unknown opcode %s\n", line_number, opcode);
				fclose(file);
				return (EXIT_FAILURE); } }
		else
		{	fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			return (EXIT_FAILURE); } }
	return (EXIT_SUCCESS);
}
