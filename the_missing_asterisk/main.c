#include <stdio.h>
#include <stdbool.h>

void get_next_message(char const **message)
{
    // Of course we should add a null check for message here
    // Simulate some logic which tells if there is a message available
    static bool message_available = true;

    if (message_available)
    {
        *message = "Hello, World!";

        // Simulate that the message is consumed
        message_available = false;
    }
    else
    {
        *message = NULL;
    }
}

int main(void)
{
    char const *message = NULL;

    do
    {
        get_next_message(&message);

        if (message != NULL)
        {
            printf("Message: %s\n", message);
        }
        else
        {
            printf("No message available\n");
        }
    } while (message != NULL);

    printf("End of program\n");
    return 0;
}