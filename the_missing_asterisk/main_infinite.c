#include <stdio.h>
#include <stdbool.h>

// Get the next message from e.g. a file.
// Getting a message might fail for some reason and there might be no message available.
bool get_next_message(char const **message)
{
    if (message == NULL)
    {
        return false;
    }

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
        // Oops missing `*` here -> Leads to infinite loop in `main`
        message = NULL;
    }

    return true;
}

int main(void)
{
    char const *message = NULL;

    do
    {
        if (get_next_message(&message))
        {
            if (message != NULL)
            {
                printf("Message: %s\n", message);
            }
            else
            {
                printf("No message available\n");
                break;
            }
        }
        else
        {
            printf("Error: get_next_message() failed\n");
            return 1;
        }
    } while (message != NULL);

    printf("End of program\n");
    return 0;
}