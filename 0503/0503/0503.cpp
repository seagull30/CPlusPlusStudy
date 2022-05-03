#include <iostream>
#include <stdarg.h>

void myprintf(const char* format, ...);

int main()
{
    myprintf("Hello my printf : %d, %c, %s", -10, 'A', "hello");

    return 0;
}
void myprintf(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    while (*format != '\0')
    {
		if (*format == '%')
		{
			++format;
			switch (*format)
			{
			case 'd':
			{
				int i = va_arg(args, int);
				char a[10] = "";
				int j = 0;
				if (i == 0)
					putchar('0');
				else if (i < 0)
				{
					putchar('-');
					i = -i;
				}

				while (i != 0)
				{
					a[j] = (i % 10) + '0';
					++j;
					i /= 10;
				}
				for (; j >= 0; j--)
				{
					putchar(a[j]);
				}

				++format;
				break;
			}

			case 'c':
			{
				char c = va_arg(args, char);
				putchar(c);
				++format;
				break;
			}

			//case 'f':
			//{
			//	double f = va_arg(args, double);
			//	putchar(a[j]);
			//	++format;
			//	break;
			//}

			case 's':
			{
				char* s = va_arg(args, char*);
				while (*s != '\0')
				{
					putchar(*s);
					++s;
				}
				++format;
				break;
			}

			default:
				--format;
				break;

			}
		}

		putchar(*format);
		++format;
	}
    va_end(args);
}
